#include <stdio.h>
#include <wiringPi.h>
#include <stdlib.h>
#define loopCount 20
#define delayTime 255
// ./helloGpio [PinNumber] 
int main(int argc, char *argv[])
{
	int gpioNo;
	int i;
	//STEP 1. WiringPi Init
	wiringPiSetup();
	
	if(argc<2)
	{
		printf("Usage : %s gpioNo!",argv[0]);
		return -1;
	}

	gpioNo = atoi(argv[1]);
	
	//STEP 2. Pin direction setup
	pinMode(gpioNo, OUTPUT);

	for(i=0;i<loopCount;i++)
	{
		//STEP 3. Pin  write
		digitalWrite(gpioNo, HIGH);
		delay(delayTime);
		//delayTime++;
		digitalWrite(gpioNo, LOW);
       		delay(delayTime);
	}	
	//for(int i=254;i>=0;i--)
	//{
	//	digitalWrite(gpioNo, HIGH);
	//	delay(delayTime--);
	//}
	return 0;
}
