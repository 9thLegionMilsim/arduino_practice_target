/*
 * Author: Laurent Goderre
 */

#include <Arduino.h>
#include "Lane.h"

const String laneStr = "Lane #";

Lane::Lane(int laneNumber, int lenTargets, Target* targets[]): number(laneNumber), lenTargets(lenTargets), targets(targets) {
}

Lane::~Lane(void){}

void Lane::showTarget() {
	Serial.println(laneStr + (number + 1));
	currentTarget = targets[rand() % lenTargets];
	currentTarget->show();
}

void Lane::hideCurrentTarget(){
	Serial.println(laneStr + (number + 1));
	currentTarget->hide();
}