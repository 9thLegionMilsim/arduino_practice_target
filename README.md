Arduino Practice Target System
=======================

Material Needed
-----------

1. Arduino Uno Board (other Arduino boards may work as well)
2. One Adafruit 16-Channel 12-bit PWM/Servo Driver for each 16 targets used
3. One servo per target
4. Power supply for the servos (i.e. 4xAA Battery Holder or 5V 10A power supply)

Assembly
-----------

Follow the following guide to setup the [Adafruit servo driver](https://learn.adafruit.com/16-channel-pwm-servo-driver/overview) and connect it to the Arduino. If more than 16 targets are used, it is critical that the addressing for each board is sequential (i.e. 0x40, 0x41 and so on).


Getting Started with the Code
-----------

This assumes you already have the Arduino IDE installed.

1. Download the following libraries and extract them in your arduino library folder (`My Documents\Arduino\libraries`)
  * [Time Library](http://playground.arduino.cc/uploads/Code/Time.zip)
  * [Adafruit PWM Servo Drive Library](https://github.com/adafruit/Adafruit-PWM-Servo-Driver-Library/archive/master.zip)
2. Rename the `Adafruit-PWM-Servo-Driver-Library-master` folder to `Adafruit_PWMServoDriver`
3. [Download the code](https://github.com/9thLegionMilsim/arduino_practice_target/archive/master.zip), extract it.
4. Rename the project folder from `arduino_practice_traget-master` to `arduino_practice_traget`
5. Open the Arduino IDE and upload the sketch to the board. ([More information on uploading a sketch to an Arduino](http://www.arduino.cc/en/Main/Howto))

Customizing the Project
-----------

Coming Soon...
