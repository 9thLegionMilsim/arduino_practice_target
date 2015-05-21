/*
 * Author: Laurent Goderre
 */

#include <Time.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

#include "LaneMode.h"
#include "SerialMode.h"

int targetMode = 0;
TargetsMode* mode;

void setup() {
	Serial.begin(9600);

	switch(targetMode) {
		case 0:
			mode = new LaneMode();
			break;
		case 1:
			mode = new SerialMode();
			break;
	}
}

void loop() {
	mode->loop();
}
