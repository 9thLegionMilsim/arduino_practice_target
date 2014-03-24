/*
 * Author: Laurent Goderre
 */

#include <stdio.h>
#include "Arduino.h"
#include "Target.h"

Target::Target(int targetNumber) : number(targetNumber){}

Target::~Target(void){}

void Target::show()
{
	Serial.println("Showing target #" + number);
}

void Target::hide()
{
	Serial.println("Hiding target #" + number);
}


