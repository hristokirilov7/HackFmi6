#include <stdio.h>
#include <wiringPi.h>
#include <math.h>
using namespace std;


class GearMotors {
private:
	int Motor1A;
	int Motor1B;
	int Motor1E;

	int Motor2A;
	int Motor2B;
	int Motor2E;

	int rotationTime;
public:
	GearMotors() {
		//wiringPiSetupGpio();
		Motor1A = 17;
		Motor1B = 18;
		Motor1E = 27;

		Motor2A = 13;
		Motor2B = 19;
		Motor2E = 26;

		rotationTime = 1400;

		pinMode(Motor1A, OUTPUT);
		pinMode(Motor1B, OUTPUT);
		pinMode(Motor1E, OUTPUT);

		pinMode(Motor2A, OUTPUT);
		pinMode(Motor2B, OUTPUT);
		pinMode(Motor2E, OUTPUT);
	}

	void forward(unsigned time = 5000) {
		digitalWrite(Motor1A, 1);
		digitalWrite(Motor1B, 0);
		digitalWrite(Motor1E, 1);

		digitalWrite(Motor2A, 1);
		digitalWrite(Motor2B, 0);
		digitalWrite(Motor2E, 1);
		if (time > 2000)
		{
			delay(2000);
			turnLeft(5);
			forward(time - 2000);
			return;
		}
		if (time != 0) {
			delay(time);

			digitalWrite(Motor1E, 0);
			digitalWrite(Motor2E, 0);
		}
	}

	void backward(unsigned time = 1000) {
		digitalWrite(Motor1A, 1);
		digitalWrite(Motor1B, 1);
		digitalWrite(Motor1E, 0);

		digitalWrite(Motor2A, 0);
		digitalWrite(Motor2B, 1);
		digitalWrite(Motor2E, 1);

		if (time != 0) {
			delay(time);

			digitalWrite(Motor1A, 0);
			digitalWrite(Motor2E, 0);
		}
	}

	void turnLeft (double angle = 90)
	{
		double coef = rotationTime  * angle / 90;
		digitalWrite(Motor1A, 1);
		digitalWrite(Motor1B, 0);
		digitalWrite(Motor1E, 1);

		digitalWrite(Motor2A, 0);
		digitalWrite(Motor2B, 1);
		digitalWrite(Motor2E, 1);

		delay (coef);
		digitalWrite(Motor1A, 0);
		digitalWrite(Motor2B, 0);
	}
	void turnRight(double angle = 90)
	{
		double coef = rotationTime * angle / 90; 
		digitalWrite(Motor1A, 1);
		digitalWrite(Motor1B, 1);
		digitalWrite(Motor1E, 0);

		digitalWrite(Motor2A, 1);
		digitalWrite(Motor2B, 0);
		digitalWrite(Motor2E, 1);


		delay(coef);
		digitalWrite(Motor1A, 0);
		digitalWrite(Motor2A, 0);
	}
	void stop() {
		digitalWrite(Motor1A, 0);
		digitalWrite(Motor1B, 0);
		digitalWrite(Motor1E, 0);

		digitalWrite(Motor2A, 0);
		digitalWrite(Motor2B, 0);
		digitalWrite(Motor2E, 0);
	}
	void testMotor() 
	{
		forward(2000);
		backward(2000);
		turnLeft();
		turnRight(); 
		stop(); 
	}
};

class DistanceSensor {
private:
	int TRIG;
	int ECHO;
public:
	DistanceSensor() {
		TRIG = 23;
		ECHO = 24;

		pinMode(TRIG, OUTPUT);
		pinMode(ECHO, INPUT);

		digitalWrite(TRIG, 0);
		delay(30);
	}
	int measure ()
	{
		digitalWrite(TRIG, 1);
		delayMicroseconds(20);
		digitalWrite(TRIG, 0);

		while (digitalRead(ECHO) == 0)
			;

		long startTime = micros();
		while (digitalRead(ECHO) == 1)
			;
		long travelTime = micros() - startTime;

		//get distance
		int distance = travelTime / 58;
		return distance;
	}
};
