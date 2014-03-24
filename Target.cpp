/*
 * Author: Laurent Goderre
 */

#include <stdio.h>
#include <Arduino.h>
#include <Adafruit_PWMServoDriver.h>
#include "Target.h"

Target::Target(int targetNumber, Adafruit_PWMServoDriver pwm) : number(targetNumber), pwm(pwm) {}

Target::~Target(void){}

void Target::show()
{
	Serial.println("Showing target #" + number);
}

void Target::hide()
{
	Serial.println("Hiding target #" + number);
}


