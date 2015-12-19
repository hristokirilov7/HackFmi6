
#include <stdio.h>
#include <time.h>
#include <wiringPi.h>
#include <piFace.h>
#include <softPwm.h>
using namespace std;

int Motor1E = 27;
int Motor1A = 17;
int Motor1B = 18;


int Motor2E = 26;
int Motor2A = 13;// ## 19 13
int Motor2B = 19;//#26

//sensor
int TRIG = 23;
int ECHO = 24;


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


 void testSensor ()
{
	pinMode(TRIG, OUTPUT);
	pinMode(ECHO, INPUT);

	digitalWrite(TRIG,0);
	delay(30);

	digitalWrite(TRIG, 1);
	delayMicroseconds(20);
	digitalWrite(TRIG,0);

	while(digitalRead(ECHO) == 0);

	long startTime = micros();
	while (digitalRead(ECHO) == 1);
	long travelTime = micros() - startTime;

	//get distance
	int distance = travelTime / 58;
	printf("%d", distance);
}


 virtual class GearMotors
 {
 private:
 	virtual int Motor1E;
 	virtual int Motor1A;
 	virtual int Motor1B;

 	virtual int Motor2E;
 	virtual int Motor2A;
 	virtual int Motor2;
 public:
 	virtual void instance()
 	{
 		wiringPiSetupGpio();
 		Motor1E = 27;
 		Motor1A = 17;
 		Motor1B = 18;

 		Motor2E = 26;
 		Motor2A = 13;
 		Motor2B = 19;

 		pinMode(Motor1A, OUTPUT);
 		pinMode(Motor1B, OUTPUT);
 		pinMode(Motor1E, OUTPUT);

 		pinMode(Motor1A, OUTPUT);
 		pinMode(Motor1B, OUTPUT);
 		pinMode(Motor1E, OUTPUT);
 	}

 	virtual void forward (unsigned time = 1000)
 	{
 		digitalWrite(Motor1E, 1);
 		digitalWrite(Motor1A, 1);
 		digitalWrite(Motor1B, 0);

 		digitalWrite(Motor2E, 1);
 		digitalWrite(Motor2A, 1);
 		digitalWrite(Motor2B, 0);

 		if (time != 0)
 		{
 			delay(time);

 			digitalWrite(Motor1E,0);
 			digitalWrite(Motor2E,0);
 		}
 	}

 	virtual void backward (unsigned time = 1000)
 	{
 		digitalWrite(Motor1A, 1);
 		digitalWrite(Motor1B, 1);
 		digitalWrite(Motor1E, 0);

 		digitalWrite(Motor2A, 0);
 		digitalWrite(Motor2B, 1);
 		digitalWrite(Motor2E, 1);

 		if (time != 0)
 		{
 			delay (time);

 			digitalWrite(Motor1A,0);
 			digitalWrite(Motor2E,0);
 		}
 	}

 	virtual void stop ()
 	{
 		digitalWrite(Motor1A, 0);
 		digitalWrite(Motor1B, 0);
 		digitalWrite(Motor1E, 0);

 		digitalWrite(Motor2A, 0);
 		digitalWrite(Motor2B, 0);
 		digitalWrite(Motor2E, 0);
 	}
 };

int main() {
	wiringPiSetupGpio();
	testMotors();
	testSensor();

	return 0;
}
