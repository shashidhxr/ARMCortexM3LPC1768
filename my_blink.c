#include<lpc17xx.h>

unsigned int delay;

int main(void)

{
	IO0DIR = (1<<10);
	
	while(1)
	{
		IO0CLR = (1<<10);
		for (delay=0; delay<500000;delay++)
			IO0SET=(1<<10)
		for (delay=0;delay<5000000;delay++)
		
	}
}
