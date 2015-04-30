/*
 * Author: Laurent Goderre
 */

#include <Arduino.h>
#include "Lane.h"

const String laneStr = "Lane #";
const String laneStrEnd =  ": ";

Lane::Lane(int laneNumber, int lenTargets, Target* targets[]): number(laneNumber), lenTargets(lenTargets), targets(targets) {
}

Lane::~Lane(void){
	for(int t=0;t<lenTargets;t++) {
		delete targets[t];
	}
}

void Lane::showTarget() {
	Serial.print(laneStr + (number + 1) + laneStrEnd);
	currentTarget = targets[rand() % lenTargets];
	currentTarget->show();
}

void Lane::hideCurrentTarget(){
	Serial.print(laneStr + (number + 1) + laneStrEnd);
	currentTarget->hide();
}

