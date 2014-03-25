/*
 * Author: Laurent Goderre
 */

#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>
#include <Time.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

#include "Target.h"

#define SERVOFREQUENCY	60
#define SERVOPERBOARD	16

const int lenTargets = 16;
const float visibleTime = 2000;
const float idleTime = 250;

Target * targets[lenTargets];
Target * currentTarget = NULL;

void setup(){
	Serial.begin(9600);

	Adafruit_PWMServoDriver pwm = NULL;
	uint8_t boardAddr = 0x40;
	uint8_t servoNum= 0;

	for(int i=0; i<lenTargets; i++)
	{
		if (i % SERVOPERBOARD == 1) {
			pwm = Adafruit_PWMServoDriver(boardAddr++);
			pwm.begin();
			pwm.setPWMFreq(SERVOFREQUENCY);
			servoNum = 0;
		}

		targets[i] = new Target(i, pwm, servoNum);
	}

	srand (now());
}

void loop()
{
	while (true) 
	{
		if (currentTarget) {
			currentTarget->hide();
			delay(idleTime);
		}
		currentTarget = targets[rand() % lenTargets];
		currentTarget->show();
		delay(visibleTime);
	}

	delete *targets;

	return;
}
