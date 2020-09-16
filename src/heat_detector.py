#! /usr/bin/env python
# -*- coding: utf-8 -*-

"""
voltbro ROS course examples
2020
"""

import rospy
from std_msgs.msg import Float32MultiArray, String, Bool
import numpy as np


class HeatDetector(object):
    """
    it can receive message from heat sensor topic in form of 64x1 Float32MultiArray
    then it must perform some analysis of that array and decide if there is an overheat or not
    if overheat was detected, it must send a string pause command to robot control topic to notify the operator
    then, after a certain period of time it nust send continure command and do not respond to overheat for little period of time
    """
    def __init__(self):

        # hardcoded constants
        self._current_pixel_array = None
        self._threshold = 50
        self._overheat_detected = False
        self._overheat_ignore = False
        self._overheat_start_time = 0
        self._blink_start_time = 0
        self._wait_after_detection = 10  # sec
        self._ignore_heat_after_continue = 10  # sec
        self._continue_command = 'next'
        self._pause_command = 'pause'
        self._control_topic = 'patrol_control'
        self._heat_pixels_topic = 'amg88xx_pixels'
        self._alarm_led_topic = 'alarm_led'
        self._alarm_blink_period = 0.5
        self._current_led_state = False

        # start it
        rospy.init_node('heat_detector')
        rospy.loginfo('HeatDetector: start heat detector node')

        # get roslaunch params and reinit part of params
        self._wait_after_detection = rospy.get_param('~wait_after_detection', 10)
        self._ignore_heat_after_continue = rospy.get_param('~ignore_heat_after_continue', 10)
        self._threshold = rospy.get_param('~threshold', 45)
        self._control_topic = rospy.get_param('~control_topic', 'patrol_control')
        self._alarm_led_topic = rospy.get_param('~alarm_led_topic ', 'alarm_led')
        self._heat_pixels_topic = rospy.get_param('~heat_pixels_topic' ,'amg88xx_pixels')

        self._rate = rospy.Rate(10)

        # init self as subscriber and publisher and start node
        self._alarm_led_pub = rospy.Publisher(self._alarm_led_topic , Bool, queue_size=10)
        self._cmd_pub = rospy.Publisher(self._control_topic , String, queue_size=10)
        self._heat_sub = rospy.Subscriber(self._heat_pixels_topic, Float32MultiArray, self._heat_callback)

        # turn off the LED by force if it accidentally remains in state on
        self._alarm_led_pub.publish(False)

        # start publishing loop
        self._run()
    
    def _mean_detector(self):
        """
        very simple function, but we can use more complex detector in future
        if mean bigger then threshold then panic
        """

        if np.mean(self._current_pixel_array)>= self._threshold:
            return True
        else:
            return False

    def _max_detector(self):
        """
        If one pixel from data array is bigger than threshold, then panic
        """
        if np.max(self._current_pixel_array)>= self._threshold:
            return True
        else:
            return False

    def bye(self):

        # and publish pause command once
        self._cmd_pub.publish(self._pause_command)
        # turn off the LED by force if it accidentally remains in state on
        self._alarm_led_pub.publish(False)

    def _pixels_identyfier(self):
        # check if we already detected heat and now in handling state
        if not (self._overheat_detected or self._overheat_ignore) :
            if self._max_detector():
                # set detected flag and update timer
                self._overheat_detected = True
                self._overheat_start_time = rospy.Time.now().to_sec()
                rospy.loginfo('HeatDetector: overheat detected')
                # and publish pause command once
                self._cmd_pub.publish(self._pause_command)
                # and start alarm blink
                self._blink_start_time = rospy.Time.now().to_sec()

                rospy.loginfo('HeatDetector: pause command sent')
        else:
            if self._overheat_detected:
                rospy.loginfo('HeatDetector: we have detected overheat and wait')
            else:
                if self._overheat_ignore:
                    rospy.loginfo('HeatDetector: we have to ignore heat for some time')

    def _alarm_blink(self):
        # blinks only when self._overheat_detected or self._overheat_ignore
        if self._overheat_detected or self._overheat_ignore:
            if rospy.Time.now().to_sec() - self._blink_start_time >= self._alarm_blink_period:
                self._current_led_state = not self._current_led_state
                # time to toggle alarm lamp on arduino
                self._alarm_led_pub.publish(self._current_led_state)
                # and update time
                self._blink_start_time = rospy.Time.now().to_sec()
        pass

    def _heat_callback(self, heat_msg):
        # just put msg data to self variable
        rospy.loginfo('HeatDetector: heat pixels message received')
        self._current_pixel_array = heat_msg.data

        if not (self._overheat_detected or self._overheat_ignore):
            rospy.loginfo('HeatDetector: heat max value is {}'.format(np.max(self._current_pixel_array)))
            #rospy.loginfo(heat_msg.data)

        # and check if there is overheat
        self._pixels_identyfier()

    def _run(self):
        while not rospy.is_shutdown():
            # we call alarm blink check everytime
            self._alarm_blink()

            if self._overheat_detected:
                # wait for send continue
                if rospy.Time.now().to_sec() - self._overheat_start_time >= self._wait_after_detection:
                    # it means that we have to send continue and set ignore heat flag
                    self._overheat_detected = False
                    self._overheat_ignore = True
                    rospy.loginfo('HeatDetector: continue command sent')
                    self._cmd_pub.publish(self._continue_command)
            else:
                if self._overheat_ignore:
                    # wait to start detect heat again
                    if rospy.Time.now().to_sec() - self._overheat_start_time >= self._wait_after_detection + self._ignore_heat_after_continue:
                        # set off all flags and start detecting
                        self._overheat_ignore = False
                        self._overheat_start_time = 0  # TODO: do we need to do that
                        # turn off the LED by force if it accidentally remains in state on
                        self._alarm_led_pub.publish(False)
                        rospy.loginfo('HeatDetector: continue heat detecting')
            #rospy
            self._rate.sleep()


if __name__ == '__main__':

    try:
        hd = HeatDetector()

    except rospy.ROSInterruptException:
        hd.bye()
        print("bye")
