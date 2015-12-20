#include <stdio.h>
#include "Car.h"
#include <math.h>

int main()
{
	wiringPiSetupGpio();
	GearMotors motor;
	motor.stop();
	return 0; 
}
