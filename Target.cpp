/*
 * Author: Laurent Goderre
 */

#include <stdio.h>
#include <Arduino.h>
#include "Target.h"

//-------------------------------------
// TODO: CALIBRATE THESE FOR SERVOS
const int servoOnPosition = 150;
const int servoOffPosition = 400;
//-------------------------------------

const String showingStr = "Showing target #";
const String hidingStr = "Hiding target #";

Target::Target(int targetNumber, Adafruit_PWMServoDriver pwm, int servoNumber) : number(targetNumber), pwm(pwm), servoNumber(servoNumber) {
}

Target::~Target(void){}

void Target::show()
{
	Serial.println(showingStr + (number + 1));
	pwm.setPWM(servoNumber, 0, servoOnPosition);
}

void Target::hide()
{
	Serial.println(hidingStr + (number + 1));
	pwm.setPWM(servoNumber, 0, servoOffPosition);
}

