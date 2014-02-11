/*
 * Author: Laurent Goderre
 */

// arduino-practice-target.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>
#include <time.h>

#include "Target.h"

const int lenTargets = 5;
const float visibleTime = 2;
const float idleTime = 0.25;

void wait (float seconds)
{
	clock_t endTime = clock() + seconds * CLOCKS_PER_SEC;
	while (clock() < endTime) {}
}

int main(int argc, _TCHAR* argv[])
{
	Target * currentTarget = NULL;
	Target * targets[lenTargets];
	int t;

	for(int i=0; i<lenTargets; i++)
	{
		targets[i] = new Target(i);
	}

	srand (time(NULL));

	while (true) 
	{
		if (currentTarget) {
			currentTarget->hide();
			wait(idleTime);
		}
		currentTarget = targets[rand() % lenTargets];
		currentTarget->show();
		wait(visibleTime);
	}

	delete *targets;

	return 0;
}

