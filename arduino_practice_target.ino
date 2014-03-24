/*
 * Author: Laurent Goderre
 */

#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>
#include <Time.h>

#include "Target.h"

const int lenTargets = 16;
const float visibleTime = 2000;
const float idleTime = 250;

void setup(){
  Serial.begin(9600);
}

void loop()
{
	Target * currentTarget = NULL;
	Target * targets[lenTargets];
	int t;

	for(int i=0; i<lenTargets; i++)
	{
		targets[i] = new Target(i);
	}

	srand (now());

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




