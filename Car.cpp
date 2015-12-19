#include <stdio.h>
#include <time.h>
#include <wiringPi.h>
#include <piFace.h>
#include <softPwm.h>
using namespace std;

/*int Motor1E = 27;
 int Motor1A = 17;
 int Motor1B = 18;


 int Motor2E = 26;
 int Motor2A = 13;// ## 19 13
 int Motor2B = 19;//#26

 //sensor
 int TRIG = 23;
 int ECHO = 24;
 */
/*
 void testMotors ()
 {
 pinMode(Motor1A, OUTPUT);
 pinMode(Motor1B, OUTPUT);
 pinMode(Motor1E, OUTPUT);

 pinMode(Motor2A, OUTPUT);
 pinMode(Motor2B, OUTPUT);
 pinMode(Motor2E, OUTPUT);

 printf("Going forwards\n");


 {	digitalWrite(Motor1E, 1);
 digitalWrite(Motor1A, 1);
 digitalWrite(Motor1B, 0);

 digitalWrite(Motor2E, 1);
 digitalWrite(Motor2A, 1);
 digitalWrite(Motor2B, 0);
 }
 delay(5000);

 digitalWrite(Motor1E,0);
 digitalWrite(Motor2E,0);

 printf("Going backwards\n");
 digitalWrite(Motor1A, 1);
 digitalWrite(Motor1B, 1);
 digitalWrite(Motor1E, 0);

 digitalWrite(Motor2A, 0);
 digitalWrite(Motor2B, 1);
 digitalWrite(Motor2E, 1);

 delay(1000);

 digitalWrite(Motor1A,0);
 digitalWrite(Motor2E,0);
 }

void testSensor() {
	pinMode(TRIG, OUTPUT);
	pinMode(ECHO, INPUT);

	digitalWrite(TRIG, 0);
	delay(30);

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
	printf("%d", distance);
}
*/
class GearMotors {
private:
	int Motor1A;
	int Motor1B;
	int Motor1E;

	int Motor2A;
	int Motor2B;
	int Motor2E;
public:
	GearMotors() {
		//wiringPiSetupGpio();
		Motor1A = 17;
		Motor1B = 18;
		Motor1E = 27;

		Motor2A = 13;
		Motor2B = 19;
		Motor2E = 26;

		pinMode(Motor1A, OUTPUT);
		pinMode(Motor1B, OUTPUT);
		pinMode(Motor1E, OUTPUT);

		pinMode(Motor2A, OUTPUT);
		pinMode(Motor2B, OUTPUT);
		pinMode(Motor2E, OUTPUT);
	}

	void forward(unsigned time = 1000) {
		digitalWrite(Motor1A, 1);
		digitalWrite(Motor1B, 0);
		digitalWrite(Motor1E, 1);

		digitalWrite(Motor2A, 1);
		digitalWrite(Motor2B, 0);
		digitalWrite(Motor2E, 1);

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

	void turnLeft ()
	{
		digitalWrite(Motor1A, 1);
		digitalWrite(Motor1B, 0);
		digitalWrite(Motor1E, 1);

		digitalWrite(Motor2A, 0);
		digitalWrite(Motor2B, 1);
		digitalWrite(Motor2E, 1);

		delay (2000);
		digitalWrite(Motor1A, 0);
		digitalWrite(Motor2B, 0);
	}

	void stop() {
		digitalWrite(Motor1A, 0);
		digitalWrite(Motor1B, 0);
		digitalWrite(Motor1E, 0);

		digitalWrite(Motor2A, 0);
		digitalWrite(Motor2B, 0);
		digitalWrite(Motor2E, 0);
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
		printf("%d", distance);
		return distance;
	}
};

int main() {
	wiringPiSetupGpio();
	//testMotors();
	//testSensor();
	GearMotors testMotors;
	
	DistanceSensor testSensor;

	testMotors.forward(3000);

	bool flag = 1;
	while (flag)
	{
	if (testSensor.measure() <= 200)
		{
			delay(3000);
			flag = 0;
			testMotors.backward(3000);
		}
	}
	return 0;
}
