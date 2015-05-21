/*
 * Author: Laurent Goderre
 */

#include <stdio.h>
#include <Arduino.h>
#include "Target.h"

#define SERVOFREQUENCY	1600
#define SERVOPERBOARD	16
#define TWBITRATE	12;

//-------------------------------------
// TODO: CALIBRATE THESE FOR SERVOS
const int servoOffPosition = 150;
const int servoOnPosition = 400;
//-------------------------------------

const uint8_t baseAddr = 0x40;

const String showingStr = "Showing target #";
const String hidingStr = "Hiding target #";

int Target::servoCount = 0;
uint8_t Target::boardAddr = baseAddr;
Adafruit_PWMServoDriver Target::current_pwm = NULL;

Target* Target::create_target(int targetNumber) {
	uint8_t servoNum = Target::servoCount++ % SERVOPERBOARD;

	if (servoNum == 0) {
		current_pwm = Adafruit_PWMServoDriver(boardAddr++);
		current_pwm.begin();
		current_pwm.setPWMFreq(SERVOFREQUENCY);
		TWBR = TWBITRATE;
	}

	return new Target(targetNumber, current_pwm, servoNum);
}

void Target::resetFactory() {
	servoCount = 0;
	boardAddr = baseAddr;
}

Target::Target(int targetNumber, Adafruit_PWMServoDriver pwm, int servoNumber) : number(targetNumber), pwm(pwm), servoNumber(servoNumber) {
	//Hide the target on initalization
	this->hide();
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
