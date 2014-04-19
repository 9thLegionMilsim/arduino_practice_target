/*
 * Author: Laurent Goderre
 */

#include <stdio.h>
#include <Arduino.h>
#include "Target.h"

//-------------------------------------
// TODO: CALIBRATE THESE FOR SERVOS
const int servoOffPosition = 150;
const int servoOnPosition = 400;
//-------------------------------------

const String showingStr = "Showing target #";
const String hidingStr = "Hiding target #";

Target::Target(int targetNumber, Adafruit_PWMServoDriver pwm, int servoNumber) : number(targetNumber), pwm(pwm), servoNumber(servoNumber) {
	//Set Servo to initial position
	pwm.setPWM(servoNumber, 0, servoOffPosition);
}

Target::~Target(void){}

void Target::show()
{
	Serial.println(showingStr + (number + 1));
	for (uint16_t pulselen = servoOffPosition; pulselen < servoOnPosition; pulselen++) {
		pwm.setPWM(servoNumber, 0, pulselen);
	}
}

void Target::hide()
{
	Serial.println(hidingStr + (number + 1));
	for (uint16_t pulselen = servoOnPosition; pulselen > servoOffPosition; pulselen--) {
		pwm.setPWM(servoNumber, 0, pulselen);
	}
}

