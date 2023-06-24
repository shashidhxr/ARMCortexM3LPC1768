/*
#include <LPC17xx.H>
void delay(unsigned long int x);
int main()
	{	SystemInit ();
 		LPC_GPIO1->FIOMASK3=0XEF;  // 1110 1111 
 		LPC_GPIO1->FIODIR3=0X10;	 // 0001 0000
	while(1)
  		{
   			LPC_GPIO1->FIOSET3=0X10;	
   			delay(0x500000);	
   			LPC_GPIO1->FIOCLR3=0X10;	
   			delay(0x500000);
  		}
	}

void delay(unsigned long int x)
	{
 		unsigned long int i=0;
 		for(i=0;i<x;i++);	
	}
*/