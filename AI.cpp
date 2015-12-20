#include <stdio.h>
#include <wiringPi.h>
#include <math.h>
#include "Car.h"
#include <string>
using namespace std;

void goToDirection(int x, int y) {
	GearMotors motors;
	DistanceSensor sensor;

	x *= 50; //convert seconds
	bool xPositive;
	if (x >= 0)
		xPositive = 1;
	else {
		xPositive = 0;
		x *= -1;
	}
	y *= 50; //convert seconds
	double angle = atan((double) x / y) * 57.295;
	double distance = sqrt(pow(x, 2) + pow(y, 2)); //seconds
	double distanceRange = 1000;
	if (xPositive && x != 0) {
		motors.turnRight(angle);
	} else if (!xPositive) {
		motors.turnLeft(angle);
	}
	int distanceCounter = 0;
	int coveredDistance = 0;
	int distanceToObject;
	while (distance > 0) {

		if (distance < 1000) {
			distanceRange = distance;
		}
		motors.forward(0);
		if (distanceCounter % 2 == 0) {
			distanceToObject = sensor.measure();
			if (distanceToObject <= 50 && distance > distanceToObject) {
				x -= angle / 90 * coveredDistance;
				y -= (90 - angle) / 90 * coveredDistance;

				if (xPositive) {
					motors.turnRight(90 - angle);
					motors.forward(x);
					motors.turnLeft(90);
					if (sensor.measure() <= 50)
					{
						motors.turnRight(90);
						motors.forward(1000);
						motors.turnLeft(90);
						if (sensor.measure() <= 50)
						{
							motors.turnLeft(90);
							motors.forward(2000+x);
							motors.turnRight(90);
							goToDirection((x+1000)/50,y/50);
						}
						else
							goToDirection(-1000/50,y/50);
					}
					else
					{
						goToDirection(0, y/50);
					}

				} else {
					motors.turnLeft(90 - angle);
					x *= -1;
					//goToDirection();

				}

				motors.stop();
				return;
			}
		}
		delay(distanceRange);
		distanceCounter++;
		distance -= distanceRange;
		coveredDistance += distanceRange;
	}
	motors.stop();

}

void convertToInt(string numbers) {

}

int main() {
	wiringPiSetupGpio();
	goToDirection(50, 100);
	return 0;
}
