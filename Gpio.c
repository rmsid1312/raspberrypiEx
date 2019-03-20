#include <stdio.h>
#include <wiringPi.h>
#include <stdlib.h>
// ./helloGpio [PinNumber]

void Light(int gpioNo,int flag);

int main(int argc, char *argv[])
{
	int gpioNo;
	int i;
	int delayTime = 255;
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

	for(i=0;i<10;i++)
	{
		//STEP 3. Pin  write
		Light(gpioNo,1);
		Light(gpioNo,0);
	}	
	return 0;
}

void Light(int gpioNo,int flag)
{
	int delayTime;
	for(delayTime=0;delayTime<64;delayTime++)
	{
		if(flag == 1)
		{
			digitalWrite(gpioNo,HIGH);
			delay(delayTime);
			digitalWrite(gpioNo,LOW);
			delay(64-delayTime);
		}
		else
		{
			digitalWrite(gpioNo,LOW);
			delay(delayTime);
			digitalWrite(gpioNo,HIGH);
			delay(64-delayTime);
		}
	}	
}
