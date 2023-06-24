/*
#include<lpc17xx.h>

void cmd_func(unsigned char cmd);
void data_func(unsigned char data);
void delay(unsigned long int x);

int main()
{
	unsigned char cmd[] = {0x38, 0x0E, 0x06, 0x80, 0x01};		// display declaration
	unsigned char msg1[] = "Welcome";
	unsigned char msg2[] = "Sensor is High";
	unsigned char msg3[] = "Sensor is Low";

	unsigned char arr[] = {0x88, 0x44, 0x22, 0x11};
	unsigned char i, j;
	LPC_GPIO1->FIOMASK = 0xFFFC3FFF;
	LPC_GPIO1->FIODIR = 0x003C000;

	unsigned char val;

	SystemInit();

	LPC_GPIO2->FIOMASK0 = 0x00;  // enabling all pins from port 2 for display pin
	LPC_GPIO2->FIODIR0 = 0xFF;  // setting port 2 p1 and p2 as output

	LPC_GPIO1->FIOMASK1 = 0xF8;  // enabling p1,2,3 of port 1
	LPC_GPIO1->FIODIR1 = 0x07;  // setting port 1 p8,9 and 10 as input

	LPC_GPIO1->FIOCLR1 = 0x02;    // RW = 0
	LPC_GPIO1->FIOCLR1 = 0x01;    // RS = 0

	LPC_GPIO0->FIOMASK2 = 0xCF;  // enabling p5,6 from port 1
	LPC_GPIO0->FIODIR2 = 0x20;   // setting p6 as output

	LPC_GPIO0->FIOMASK3 = 0xF7;  // enabling p4 from port 3
	LPC_GPIO0->FIODIR3 = 0x08;   // setting p4 as ouput

	LPC_GPIO1->FIOMASK3 = 0xEF;  // enabling p4 from port 3
	LPC_GPIO1->FIODIR3 = 0x10;   // setting p4 as ouput

	for (i = 0; i < 5; i++)   // for reading array commands to display elements
	{
		LPC_GPIO2->FIOPIN0 = cmd[i];
		LPC_GPIO1->FIOSET1 = 0x04;
		delay(0x500);

		LPC_GPIO1->FIOCLR = 0x04;
		delay(0x5000);
	}

	LPC_GPIO1->FIOSET1 = 0x01;   // RS = 1 to change inputs as data

	for (i = 0; msg1[i] != '\0'; i++)   // for reading array commands to display
	{
		LPC_GPIO2->FIOPIN0 = msg1[i];
		LPC_GPIO1->FIOSET1 = 0x04;
		delay(0x500);

		LPC_GPIO1->FIOCLR = 0x04;
		delay(0x5000);
	}

	while (1)		// for checking state of pin
	{
		val = LPC_GPIO1->FIOPIN1;
		if (val & 0x80) // Checking if switch at p27 is high
		{
			LPC_GPIO1->FIOSET3 = 0x10;  // Turn on LED and buzzer
			LPC_GPIO0->FIOSET2 = 0x20;
			delay(0x5000);
			LPC_GPIO0->FIOCLR2 = 0x20;
			delay(0x5000);

			for (i = 0; i < 4; i++)  // Rotate stepper motor clockwise
			{
				LPC_GPIO1->FIOPIN = arr[i] << 12;
				delay(0x50000);
			}

			// Add a function to stop motor after 90 degrees

			for (j = 0; j < 4; j++)  // Rotate stepper motor anticlockwise
			{
				LPC_GPIO1->FIOPIN = arr[j] << 12;
				delay(0x50000);
			}

			// Stop it after 90 degrees

			// Clear display
			LPC_GPIO1->FIOSET1 = 0x00;   // RS = 0 for command
			LPC_GPIO2->FIOPIN0 = 0x01;
			LPC_GPIO1->FIOSET1 = 0x04;
			delay(0x500);
			LPC_GPIO1->FIOCLR = 0x04;		
			delay(0x5000);

			for (i = 0; i < 5; i++)   // to display msg2
			{
				LPC_GPIO2->FIOPIN0 = cmd[i];
				LPC_GPIO1->FIOSET1 = 0x04;
				delay(0x500);

				LPC_GPIO1->FIOCLR = 0x04;
				delay(0x5000);
			}

			LPC_GPIO1->FIOSET1 = 0x01;   // RS = 1

			for (i = 0; msg2[i] != '\0'; i++)
			{
				LPC_GPIO2->FIOPIN0 = msg2[i];
				LPC_GPIO1->FIOSET1 = 0x04;
				delay(0x500);

				LPC_GPIO1->FIOCLR = 0x04;
				delay(0x5000);
			}
		}
		else  // State is low
		{
			LPC_GPIO1->FIOCLR3 = 0x10;  // Keep buzzer and LED in inactive state
			delay(0x5000);

			LPC_GPIO1->FIOCLR1 = 0x02;    // RW = 0
			LPC_GPIO1->FIOCLR1 = 0x01;    // RS = 0

			// Clear display
			LPC_GPIO1->FIOSET1 = 0x00;   // RS = 0 for command
			LPC_GPIO2->FIOPIN0 = 0x01;
			LPC_GPIO1->FIOSET1 = 0x04;
			delay(0x500);
			LPC_GPIO1->FIOCLR = 0x04;
			delay(0x5000);

			for (i = 0; i < 5; i++)   // to display msg3
			{
				LPC_GPIO2->FIOPIN0 = cmd[i];
				LPC_GPIO1->FIOSET1 = 0x04;
				delay(0x500);

				LPC_GPIO1->FIOCLR = 0x04;
				delay(0x5000);
			}

			LPC_GPIO1->FIOSET1 = 0x01;   // RS = 1

			for (i = 0; msg3[i] != '\0'; i++)
			{
				LPC_GPIO2->FIOPIN0 = msg3[i];
				LPC_GPIO1->FIOSET1 = 0x04;
				delay(0x500);

				LPC_GPIO1->FIOCLR = 0x04;
				delay(0x5000);
			}
		}
	}
}

void delay(unsigned long int x)
{
	unsigned long int i = 0;
	for (i = 0; i < x; i++);
}
*/