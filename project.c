#include<lpc17xx.h>

//void cmd_func(unsigned char cmd);
//void data_func(unsigned char data);
void delay(unsigned long int x);

int main()
{
	unsigned char cmd[]={0x38,0x0E,0x06,0x80,0x01};		//display commands
	unsigned char msg1[]="Welcome";
	unsigned char msg2[]="Sensor is High";
	unsigned char msg3[]="Sensor is Low";
		
	unsigned char a;
	
	unsigned char val;		//To store the state of switch
	
	unsigned char arr[]={0x88,0x44,0x22,0x11},i;		//stepper motor declaration
	unsigned char arr1[]={0x11,0x22,0x44,0x88},j;
	LPC_GPIO1->FIOMASK=0xFFFC3FFF;
	LPC_GPIO1->FIODIR=0x0003C000;
	
	

	SystemInit();
	
	//LCD
	LPC_GPIO2->FIOMASK0 |= 0x00;  // enabling all pins from port 2 for display pin
	LPC_GPIO2->FIODIR0 |= 0xFF;	// setting all pins as output
	
	LPC_GPIO1->FIOMASK1 |=0xF8;	// enabling p1,2,3 of port 1
	LPC_GPIO1->FIODIR1 |=0x07; 	// setting port 1 p8,9 and 10 as input
	
	LPC_GPIO1->FIOCLR1=0x02;    //RW= 0 ,write 
	LPC_GPIO1->FIOCLR1=0x01;   //RS=0  to take inputs as command 
	
	//buzzer
	LPC_GPIO0->FIOMASK2=0XDF;  //enabling p5,6 from port 1  for Buzzer
 	LPC_GPIO0->FIODIR2=0X20; 	//setting p6 as output
   
 	LPC_GPIO0->FIOMASK3=0XF7;	//enabling p4 from port 3		
	LPC_GPIO0->FIODIR3=0X00;	//setting p4 as input

	//LED
	LPC_GPIO1->FIOMASK3=0XEF;	//enabling p5 from port 1
  LPC_GPIO1->FIODIR3=0X10;	//setting p5 as output
	
	for(i=0;i<5;i++)   //for reading array commands  to display elements 
	{
		LPC_GPIO2->FIOPIN0=cmd[a];   
		LPC_GPIO1->FIOSET1=0x04;
		delay(0x500);
		
		LPC_GPIO1->FIOCLR=0x04;
		delay(0x5000);
	}
	
	
	LPC_GPIO1->FIOSET1=0x01;   //RS=1 to change inputs as data 
	
	for(a=0;msg1[a]!='\0';a++)   //for reading array commands to display
	{
		LPC_GPIO2->FIOPIN0=msg1[a];   //display welcome
		LPC_GPIO1->FIOSET1=0x04;
		delay(0x500);
		
		LPC_GPIO1->FIOCLR=0x04;
		delay(0x5000);
	}
	
	
	//for checking for checking state of pin 


    val=LPC_GPIO0->FIOPIN3;
    if(val==0X08)			//state is high
        {
            LPC_GPIO1->FIOSET3=0X10;	//turn on LED and buzzer
            LPC_GPIO0->FIOSET2=0X20;
            delay(0x5000);
            LPC_GPIO0->FIOCLR2=0X20;
						delay(0x5000);
						
				while(1)
				{
					for(i=0;i<12.5;i++)			//rotate stepper motor clockwise
					{
						LPC_GPIO1->FIOPIN=arr[i]<<12;
						delay(0x50000);
					}
					delay(0x50000);		//stop it after 90 degrees
					break;
					
			
					for(j=0;j<12.5;j++)			//rotate stepper motor anticlockwise
					{
						LPC_GPIO1->FIOPIN0=arr1[j]<<12;
						delay(0x50000);
					}
					delay(0x50000);		//stop it after 90 degrees
					break;
				}	
			
				//clear display print msg1
				
				LPC_GPIO1->FIOCLR1=0x01;  //setting RS=0
				
				for(a=0;a<5;a++)   //to display msg2
				{
					LPC_GPIO2->FIOPIN0=cmd[a];   
					LPC_GPIO1->FIOSET1=0x04;
					delay(0x500);
		
					LPC_GPIO1->FIOCLR=0x04;
					delay(0x5000);
				}
		
	
				LPC_GPIO1->FIOSET1=0x01;   //RS=1
	
				for(a=0;msg1[a]!='\0';a++)   
				{
					LPC_GPIO2->FIOPIN0=msg2[a];   
					LPC_GPIO1->FIOSET1=0x04;
					delay(0x500);
		
					LPC_GPIO1->FIOCLR=0x04;
					delay(0x5000);
				}	
			}
		
        
       else			//state is 
       {
            	
					LPC_GPIO1->FIOCLR3=0X10;	//keep buzzer and led in inactive state
					delay(0x5000);
			
					LPC_GPIO1->FIOCLR1=0x02;    //RW= 0
					LPC_GPIO1->FIOCLR1=0x01;   //RS=0
	
	
					LPC_GPIO1->FIOCLR1=0x01;  //setting RS=0	
				 
					for(i=0;i<5;i++)   //to display msg3
					{
						LPC_GPIO2->FIOPIN0=cmd[i];   
						LPC_GPIO1->FIOSET1=0x04;
						delay(0x500);
		
						LPC_GPIO1->FIOCLR=0x04;
						delay(0x5000);
					}
		
	
					LPC_GPIO1->FIOSET1=0x01;   //RS=1
	
					for(a=0;msg2[a]!='\0';a++)   
					{
						LPC_GPIO2->FIOPIN0=msg3[a];   
						LPC_GPIO1->FIOSET1=0x04;
						delay(0x500);
		
						LPC_GPIO1->FIOCLR=0x04;
						delay(0x5000);
					}
			
				}
		}
}

void delay(unsigned long int x)
	{
 		unsigned long int i=0;
 		for(i=0;i<x;i++);	
	}
	