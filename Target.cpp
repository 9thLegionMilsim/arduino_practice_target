/*
 * Author: Laurent Goderre
 */

#include <stdio.h>
#include "Target.h"

Target::Target(int targetNumber) : number(targetNumber){}

Target::~Target(void){}

void Target::show()
{
	printf("Showing target #%d\n", number);
}

void Target::hide()
{
	printf("Hiding target #%d\n", number);
}