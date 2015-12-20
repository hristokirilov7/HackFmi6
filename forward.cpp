#include <stdio.h>
#include <wiringPi.h>
#include <math.h>
#include "Car.h"

int main() {
	wiringPiSetupGpio();
	GearMotors motor; 
	motor.forward(0);
	return 0; 
}
