#include <iostream>
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
	cout << "Going forwards\n";
	digitalWrite(Motor1E, 1);
	digitalWrite(Motor1A, 1);
	digitalWrite(Motor1B, 0);

	digitalWrite(Motor2E, 1);
	digitalWrite(Motor2A, 1);
	digitalWrite(Motor2B, 0);

	delay(1000);


	cout << "Going forwards\n";
	digitalWrite(Motor1A, 1);
	digitalWrite(Motor1B, 1);
	digitalWrite(Motor1E, 0);

	digitalWrite(Motor2A, 0);
	digitalWrite(Motor2B, 1);
	digitalWrite(Motor2E, 1);

	delay(1000);
}


void testSensor ()
{
	pinMode(TRIG, OUTPUT);
	pinMode(ECHO, INPUT);

	//Settle Sensor
	digitalWrite(TRIG, 1);
	delay (2000);


	//Test
	digitalWrite(TRIG, 1);
	delayMicroseconds(10);
	digitalWrite(TRIG, 0);

	time_t start, end;
	while (digitalRead(ECHO) == 0)
		start = clock();
	while (digitalRead(ECHO) == 1)
		end = clock();
	double duration = (end - start) / 1000000.0;
	double distance = duration * 17150;
	cout << distance << endl;
}

int main() {
	wiringPiSetup();
	//testMotors();
	testSensor();

	return 0;
}
