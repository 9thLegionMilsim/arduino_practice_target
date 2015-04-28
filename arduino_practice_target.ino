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

const int lenLanes = 6;
const int targetsPerLane = 3;
const int visibleTime = 5000;
const int idleTimeMin = 3000;
const int idleTimeMax = 5000;

Lane* lanes[lenLanes];
bool started = false;

void setup(){
	Serial.begin(9600);

	Target** targets;

	for(int l=0; l<lenLanes; l++)
	{
		targets = new Target* [targetsPerLane];

		for (int t=0; t<targetsPerLane; t++){
			targets[t] = Target::create_target(t);
		}

		lanes[l] = new Lane (l, targetsPerLane, targets);
	}

	srand (now());

	//Allow time for the targets to reset to original position
	delay(1000);
}

void loop()
{
	while (true)
	{
		if (started) {
			for (int l=0; l<lenLanes; l++) {
				lanes[l]->hideCurrentTarget();
			}
			delay(rand() % (idleTimeMax - idleTimeMin) + idleTimeMin);
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
