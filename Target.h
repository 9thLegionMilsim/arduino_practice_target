/*
 * Author: Laurent Goderre
 */

#include <Adafruit_PWMServoDriver.h>

#pragma once
class Target
{
	static int servoCount;
	static uint8_t boardAddr;
	static Adafruit_PWMServoDriver current_pwm;
	int number;
	int servoNumber;
	Adafruit_PWMServoDriver pwm;

	Target(int targetNumber, Adafruit_PWMServoDriver pwm, int servoNumber);
public:
	static Target* create_target(int targetNumber);
	static void resetFactory();

	~Target(void);

	void show(void);
	void hide();
};
