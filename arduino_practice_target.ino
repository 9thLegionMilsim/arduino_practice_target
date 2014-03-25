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

const int lenTargets = 16;
const float visibleTime = 2000;
const float idleTime = 250;

Target * targets[lenTargets];
Target * currentTarget = NULL;

void setup(){
	Serial.begin(9600);

	Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
	pwm.begin();
	pwm.setPWMFreq(SERVOFREQUENCY);

	for(int i=0; i<lenTargets; i++)
	{
		targets[i] = new Target(i, pwm);
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
