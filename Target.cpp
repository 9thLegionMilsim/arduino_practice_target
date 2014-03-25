/*
 * Author: Laurent Goderre
 */

#include <stdio.h>
#include <Arduino.h>
#include <Adafruit_PWMServoDriver.h>
#include "Target.h"

//-------------------------------------
// TODO: CALIBRATE THESE FOR SERVOS
const int servoOnPosition = 150;
const int servoOffPosition = 600;
//-------------------------------------

Target::Target(int targetNumber, Adafruit_PWMServoDriver pwm, int servoNumber) : number(targetNumber), pwm(pwm), servoNumber(servoNumber) {}

Target::~Target(void){}

void Target::show()
{
	Serial.println("Showing target #" + (number + 1));
	pwm.setPWM(servoNumber, 0, servoOnPosition);
}

void Target::hide()
{
	Serial.println("Hiding target #" + (number + 1));
	pwm.setPWM(servoNumber, 0, servoOffPosition);
}