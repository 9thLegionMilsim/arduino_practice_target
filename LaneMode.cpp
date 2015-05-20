/*
 * Author: Laurent Goderre
 */

#include <Time.h>

#include "Target.h"
#include "LaneMode.h"

const int lenLanes = 6;
const int targetsPerLane = 3;
const int visibleTime = 5000;
const int idleTimeMin = 3000;
const int idleTimeMax = 5000;

LaneMode::LaneMode() : TargetsMode() {
	Target** targets;

	lanes = new Lane* [lenLanes];

	for(int l=0; l<lenLanes; l++) {
		targets = new Target* [targetsPerLane];

		for (int t=0; t<targetsPerLane; t++) {
			targets[t] = Target::create_target(t);
		}

		lanes[l] = new Lane(l, targetsPerLane, targets);
	}

	srand (now());

	//Allow time for the targets to reset to original position
	delay(1000);
}

LaneMode::~LaneMode(void) {
	for (int l=0; l<lenLanes; l++) {
		delete lanes[l];
	}
}

void LaneMode::loop() {
	if (started) {
		for (int l=0; l<lenLanes; l++) {
			lanes[l]->hideCurrentTarget();
		}
		delay(rand() % (idleTimeMax - idleTimeMin) + idleTimeMin);
	} else {
		started = true;
	}
	for (int l=0; l<lenLanes; l++) {
		lanes[l]->showTarget();
	}
	delay(visibleTime);
};

