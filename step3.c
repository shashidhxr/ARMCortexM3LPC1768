/*
#include<LPC17xx.h>

void delay(unsigned long int x)
{
 	unsigned long int i=0;
 	for(i=0;i<x;i++);	
}
int main()
{
	unsigned char arr1[10]={0x11,0x22,0x44,0x88},i,j;	
	LPC_GPIO1->FIOMASK=0xFFC3FFF;
	LPC_GPIO1->FIODIR=0x003C000;
	for(j=0;j<50;j++)
	{
		for(i=0;i<4;i++)
		{
			LPC_GPIO1->FIOPIN=arr1[i]<<14;
			delay(0X50000);
		}
	}
}
*/
