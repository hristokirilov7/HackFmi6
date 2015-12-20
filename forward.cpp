#include <stdio.h>
#include <wiringPi.h>
#include <math.h>
using namespace std;

int Motor1A= 17;
int Motor1B = 18;
int Motor1E = 27;

int Motor2A =13;
int Motor2B = 19;
int Motor2E = 26;



void forward(unsigned time = 5000) {
	digitalWrite(Motor1A, 1);
	digitalWrite(Motor1B, 0);
	digitalWrite(Motor1E, 1);

	digitalWrite(Motor2A, 1);
	digitalWrite(Motor2B, 0);
	digitalWrite(Motor2E, 1);

	int rotationTime = 1400; 
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

int main() {
	forward(0);
	return 0; 
}