/*
#include<lpc17xx.h>

void cmd_func(unsigned char cmd);
void data_func(unsigned char data);
void delay(unsigned long int x);

int main()
{
	unsigned char cmd[]={0x38,0x0E,0x06,0x80,0x01};
	unsigned char msg[]="Welcome";
	unsigned char i;
	SystemInit();
	
	
	LPC_GPIO2->FIOMASK0 = 0x00;  // enabling port 2 
	LPC_GPIO2->FIODIR0 = 0xFF;	// setting p1 and p2 as output 
	
	LPC_GPIO1->FIOMASK1=0xF8;	//
	LPC_GPIO1->FIODIR1=0x07; 	// setting p8,9 and 10 as input
	

	LPC_GPIO1->FIOCLR1=0x02;    //RW= 0
	LPC_GPIO1->FIOCLR1=0x01;   //RS=0
	
	
	for(i=0;i<5;i++)   //for reading array commands
	{
		LPC_GPIO2->FIOPIN0=cmd[i];   
		LPC_GPIO1->FIOSET1=0x04;
		delay(0x500);
		
		LPC_GPIO1->FIOCLR=0x04;
		delay(0x5000);
	}
	
	
	LPC_GPIO1->FIOSET1=0x01;   //RS=1
	
	for(i=0;msg[i]!='\0';i++)   //for reading array commands
	{
		LPC_GPIO2->FIOPIN0=msg[i];   
		LPC_GPIO1->FIOSET1=0x04;
		delay(0x500);
		
		LPC_GPIO1->FIOCLR=0x04;
		delay(0x5000);
	}
	
}

void delay(unsigned long int x)
	{
 		unsigned long int i=0;
 		for(i=0;i<x;i++);	
	}
	*/