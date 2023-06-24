/*
#include <LPC17xx.h>
#include <stdint.h>

void delay(unsigned long int x);

int main() {
	int i;
	unsigned char arr[] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
                          0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F};
    SystemInit();
	
    LPC_GPIO0->FIOMASK3 = 0xEF;  // 1110 1111, setting port 0.8, 0.9, 0.10, and 0.11 as outputs
    LPC_GPIO0->FIODIR3 = 0xF0;  // 1111 0000
    
    

    while(1) {
        for(i = 0; i < 16; i++) {
            unsigned char hexValue = arr[i];

            // Set the state of each LED based on the bits of the hex value
            LPC_GPIO0->FIOSET3 = (hexValue << 4) & 0xF0;
            
            delay(0x500000);
            
            LPC_GPIO0->FIOCLR3 = 0xF0;
            
            delay(0x500000);
        }
    }
}

void delay(unsigned long int x) {
    unsigned long int i = 0;
    for(i = 0; i < x; i++);
}
*/