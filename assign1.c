#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

// Define the LED pin mappings
#define LED_PIN_0 0x08  // P0.8
#define LED_PIN_1 0x09  // P0.9
#define LED_PIN_2 0x0A  // P0.10
#define LED_PIN_3 0x0B  // P0.11

// Function to set the state of a specific LED
void setLEDState(uint8_t pin, bool state) {
    if (state) {
        // Set the pin HIGH
        // Write your code here to set the GPIO pin to HIGH
    } else {
        // Set the pin LOW
        // Write your code here to set the GPIO pin to LOW
    }
}

int main() {
    uint8_t hexArray[] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
                          0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F};

    while (1) {
        for (int i = 0; i < 16; i++) {
            uint8_t hexValue = hexArray[i];

            // Set the state of each LED based on the bits of the hex value
            setLEDState(LED_PIN_0, (hexValue & 0x01) != 0);
            setLEDState(LED_PIN_1, (hexValue & 0x02) != 0);
            setLEDState(LED_PIN_2, (hexValue & 0x04) != 0);
            setLEDState(LED_PIN_3, (hexValue & 0x08) != 0);

            // Delay for a short period of time before changing the LEDs
            // Write your code here to add a delay
        }
    }

    return 0;
}
