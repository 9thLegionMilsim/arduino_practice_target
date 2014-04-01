/*
 * Author: Laurent Goderre
 */

#include "Target.h"

#pragma once
class Lane
{
	int number;
	int lenTargets;
public:
	Lane(int laneNumber, int lenTargets, Target* targets[]);
	~Lane(void);

	Target * currentTarget;
	Target** targets;

	void showTarget(void);
	void hideCurrentTarget(void);
};