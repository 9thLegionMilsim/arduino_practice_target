#pragma once
class Target
{
	int number;
	Adafruit_PWMServoDriver pwm;
public:
	Target(int targetNumber, Adafruit_PWMServoDriver pwm);
	~Target(void);
	
	void show(void);
	void hide();
};



