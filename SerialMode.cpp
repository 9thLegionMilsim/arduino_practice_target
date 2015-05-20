/*
 * Author: Laurent Goderre
 */

#include <Time.h>

#include "Target.h"
#include "SerialMode.h"

const int lenTargets = 6;
const int visibleTime = 5000;
const int idleTimeMin = 3000;
const int idleTimeMax = 5000;

SerialMode::SerialMode() : TargetsMode() {
	targets = new Target* [lenTargets];

	for (int t=0; t<lenTargets; t++) {
		targets[t] = Target::create_target(t);
	}

	srand (now());

	//Allow time for the targets to reset to original position
	delay(1000);
}

SerialMode::~SerialMode(void) {
	for (int t=0; t<lenTargets; t++) {
		delete targets[t];
	}
}

void SerialMode::loop() {
	if (started) {
		hideCurrentTarget();
		delay(rand() % (idleTimeMax - idleTimeMin) + idleTimeMin);
	} else {
		started = true;
	}

	showTarget();

	delay(visibleTime);
};

void SerialMode::showTarget() {
	currentTarget = targets[rand() % lenTargets];
	currentTarget->show();
}

void SerialMode::hideCurrentTarget(){
	currentTarget->hide();
}

