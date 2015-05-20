/*
 * Author: Laurent Goderre
 */

#pragma once
class TargetsMode {
protected:
	bool started;
public:
	TargetsMode();
	virtual void loop() = 0;
};
