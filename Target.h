/*
 * Author: Laurent Goderre
 */

#include <Adafruit_PWMServoDriver.h>

#pragma once
class Target
{
	int number;
	int servoNumber;
	Adafruit_PWMServoDriver pwm;
public:
	Target(int targetNumber, Adafruit_PWMServoDriver pwm, int servoNumber);
	~Target(void);
	
	void show(void);
	void hide();
};

