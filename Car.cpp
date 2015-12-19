
//####
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
}*/


 void testSensor ()
{
	pinMode(TRIG, OUTPUT);
	pinMode(ECHO, INPUT);
/*
	//Settle Sensor
	digitalWrite(TRIG, 0);
	delay (2000);


	//Test
	digitalWrite(TRIG, 1);
	delayMicroseconds(10);
	digitalWrite(TRIG, 0);

	clock_t start, end;
	while (digitalRead(ECHO) == 1)
		start = clock();
//	start = clock();
	while (digitalRead(ECHO) == 0)
		end = clock();
	printf("%lu",end);
	printf("\n");
	printf("%lu",start);
	double duration = (end - start) / 1000000.0;
	double distance = duration * 17150;
//	printf("%f", distance);

	digitalWrite(TRIG,0);
	digitalWrite(ECHO,0);
*/
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

int main() {
	wiringPiSetupGpio();
	//testMotors();
	testSensor();

	return 0;
}
