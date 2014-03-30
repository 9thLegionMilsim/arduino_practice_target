/*
 * Author: Laurent Goderre
 */

#pragma once
class Target
{
	int number;
	int servoNumber;
	Adafruit_PWMServoDriver pwm;
	String showingStr;
	String hidingStr;
public:
	Target(int targetNumber, Adafruit_PWMServoDriver pwm, int servoNumber);
	~Target(void);
	
	void show(void);
	void hide();
};