#include <stdint.h>
#include "stm32l476xx.h"
/*************************************************************************************************
* @file main.c
* @Lab_2
* @author Noah Marchman
* @version 1.0
* ------------------------------------------------------------------------------------------------
* The purpose of this lab is to blink the on-board LED at different rates. To change these rates
* we hit the user button provided on the board to cycle through 3 predetermined rates.
**************************************************************************************************/


//Approximate delay cycles
#define slow   75000  // 1Hz
#define medium 50000  // 2Hz
#define fast   25000  // 4Hz

//This is how I control time between blinks
void delay(int count) {
    for (int i = 0; i < count; i++) {
        __NOP(); // No operation
    }
}

int main(void) {
    // 1. Enable Clock for GPIOA(LED) and GPIOC(Button)
    RCC->AHB2ENR |= (RCC_AHB2ENR_GPIOAEN | RCC_AHB2ENR_GPIOCEN);

    // 2. Configure PA5(LD2) as Output
    GPIOA->MODER &= ~(GPIO_MODER_MODE5_1); // Clear bit 1
    GPIOA->MODER |=  (GPIO_MODER_MODE5_0); // Set bit 0 to 01 (Output)

    // 3. Configure PC13(User Button) as Input
    GPIOC->MODER &= ~(GPIO_MODER_MODE13); // 00 is Input mode

    int Setting = 0; // 0: Slow, 1: Medium, 2: Fast
    int current_delay = slow;
    int button_pressed = 0;

    while (1) {
        // Toggle the LED on PA5
        GPIOA->ODR ^= GPIO_ODR_OD5;

        // Check for button press (PC13 is active LOW)
        // Check the IDR
        if (!(GPIOC->IDR & GPIO_IDR_ID13)) {
        	if (!button_pressed) {
				// Advance Setting and wrap around
				Setting = (Setting + 1) % 3;

				// Update blink rate based on setting
				if (Setting == 0) current_delay = slow;
				else if (Setting == 1) current_delay = medium;
				else if (Setting == 2) current_delay = fast;

				button_pressed = 1;
        	}
        }
        else button_pressed = 0;

        // Apply selected delay
        delay(current_delay);
    }
}
