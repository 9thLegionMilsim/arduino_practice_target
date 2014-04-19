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
#define TWBITRATE	12;

const int lenLanes = 6;
const int targetsPerLane = 3;
const float visibleTime = 2000;
const float idleTime = 250;

Lane* lanes[lenLanes];
bool started = false;

void setup(){
	Serial.begin(9600);

	Adafruit_PWMServoDriver pwm = NULL;
	uint8_t boardAddr = 0x40;
	uint8_t servoNum= 0;
	Target** targets;

	for(int l=0; l<lenLanes; l++)
	{
		targets = new Target* [targetsPerLane];

		for (int t=0; t<targetsPerLane; t++){
			servoNum = (l * targetsPerLane + t) % SERVOPERBOARD;

			if (servoNum == 0) {
				pwm = Adafruit_PWMServoDriver(boardAddr++);
				pwm.begin();
				pwm.setPWMFreq(SERVOFREQUENCY);
				TWBR = TWBITRATE;
			}

			targets[t] = new Target(t, pwm, servoNum);;
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