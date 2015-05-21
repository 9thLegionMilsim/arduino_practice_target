/*
 * Author: Laurent Goderre
 */

#include "Target.h"
#include "TargetsMode.h"

#pragma once
class SerialMode : public TargetsMode {
	Target** targets;
	Target* currentTarget;

	void showTarget();
	void hideCurrentTarget();
public:
	SerialMode();
	~SerialMode();

	void loop();
};
