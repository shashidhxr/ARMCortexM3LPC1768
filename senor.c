/*
#include<lpc17xx.h>

void delay(unsigned long int x);

int main()
{
    unsigned char val;
    SystemInit();


    LPC_GPIO0->FIOMASK2=0XDF;  //0xCF
    LPC_GPIO0->FIODIR2=0X20;
    LPC_GPIO0->FIOMASK3=0XF7;
    LPC_GPIO0->FIODIR3=0X08;

    LPC_GPIO1->FIOMASK3=0XEF;
    LPC_GPIO1->FIOMASK3=0X10;

    while(1)					
    {
        val=LPC_GPIO0->FIOPIN3;
        if(val==0X08)
        {
            LPC_GPIO1->FIOSET3=0X10;	
            LPC_GPIO0->FIOSET2=0X20;
            delay(0x5000);
            LPC_GPIO0->FIOCLR2=0X20;
						delay(0x5000);
        }
        else
        {
            	
   			LPC_GPIO1->FIOCLR3=0X10;	
   			delay(0x5000);
        }
    }

}
void delay(unsigned long int x)
	{
 		unsigned long int i=0;
 		for(i=0;i<x;i++);	
	}
	*/
	