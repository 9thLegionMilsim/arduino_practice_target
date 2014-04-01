/*
 * Author: Laurent Goderre
 */

#include <stdio.h>
#include <stdlib.h>
#include <Time.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

#include "Target.h"
#include "Lane.h"

#define SERVOFREQUENCY	60
#define SERVOPERBOARD	16

const int lenLanes = 5;
const int targetsPerLane = 3;
const float visibleTime = 2000;
const float idleTime = 250;

Lane * lanes[lenLanes];
bool started = false;

void setup(){
	Serial.begin(9600);

	Adafruit_PWMServoDriver pwm = NULL;
	uint8_t boardAddr = 0x40;
	uint8_t servoNum= 0;

	for(int l=0; l<lenLanes; l++)
	{
		Target* targets[targetsPerLane];

		for (int t=0; t<targetsPerLane; t++){
			servoNum = l * t % SERVOPERBOARD;

			if (servoNum == 0) {
				pwm = Adafruit_PWMServoDriver(boardAddr++);
				pwm.begin();
				pwm.setPWMFreq(SERVOFREQUENCY);
			}

			targets[t] = new Target(t, pwm, servoNum);
		}

		lanes[l] = new Lane (l, targetsPerLane, targets);
	}

	srand (now());
}

void loop()
{
	while (true) 
	{
		if (started) {
			for (int l=0; l<lenLanes; l++) {
				lanes[l]->hideCurrentTarget();
			}
			delay(idleTime);
		} else{
			started = true;
		}
		for (int l=0; l<lenLanes; l++) {
			lanes[l]->showTarget();
		}
		delay(visibleTime);
	}

	delete *lanes;
}
