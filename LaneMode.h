/*
 * Author: Laurent Goderre
 */

#include "Lane.h"
#include "TargetsMode.h"

#pragma once
class LaneMode : public TargetsMode {
	Lane** lanes;
public:
	LaneMode();
	~LaneMode();

	void loop();
};
