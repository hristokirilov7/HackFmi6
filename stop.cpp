<<<<<<< HEAD
#include <stdio.h>
#include <wiringPi.h>
#include <math.h>
using namespace std;

int Motor1A = 17;
int Motor1B = 18;
int Motor1E = 27;

int Motor2A = 13;
int Motor2B = 19;
int Motor2E = 26;

void stop() {
	digitalWrite(Motor1A, 0);
	digitalWrite(Motor1B, 0);
	digitalWrite(Motor1E, 0);

	digitalWrite(Motor2A, 0);
	digitalWrite(Motor2B, 0);
	digitalWrite(Motor2E, 0);
}

int main() {
	stop(); 
	return 0; 
=======
#include <stdio.h>
#include <wiringPi.h>
#include <math.h>
using namespace std;

int Motor1A = 17;
int Motor1B = 18;
int Motor1E = 27;

int Motor2A = 13;
int Motor2B = 19;
int Motor2E = 26;

void stop() {
	digitalWrite(Motor1A, 0);
	digitalWrite(Motor1B, 0);
	digitalWrite(Motor1E, 0);

	digitalWrite(Motor2A, 0);
	digitalWrite(Motor2B, 0);
	digitalWrite(Motor2E, 0);
}

int main() {
	stop(); 
	return 0; 
>>>>>>> bca64380a8ddbb1fd5b1c1073ec1c63687146dcd
}