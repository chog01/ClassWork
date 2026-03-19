#include <stdint.h>
#include "stm32l476xx.h"
#include "hiletgo_driver.h"
/**************************************************************************************************
* @file main.c
* @Lab_4
* @author Noah Marchman
* @version 1.0
* ------------------------------------------------------------------------------------------------
* The purpose of this lab is to interact with the on-board buzzer included with the HiLetGo board
* I created 3 different tones based on the button pressed
* S1 = high pitch
* S2 = medium pitch
* S3 = low pitch
***************************************************************************************************/
#include "hiletgo_driver.h"
#include "stm32l476xx.h"

//Delay function to control tone
void delay(volatile uint32_t count) {
    while (count--)
    {
        __NOP(); //Do nothing
    }
}

int main(void) {
    // Initialize the HiLetGo shield
    hiletgo_init_shield();

    //Turn Buzzer off on startup
    GPIOB->ODR |= GPIO_ODR_OD3;

    // Delay values for the three tones
    // Smaller delay = higher frequency (higher pitch)
    uint32_t tone1_delay = 300;
    uint32_t tone2_delay = 2000;
    uint32_t tone3_delay = 7500;

    while (1)
    {
        // Check if Button S1 is pressed
        if (hiletgo_is_button_pressed(HILETGO_BUTTON_S1))
        {
            hiletgo_buzzer();      // Toggle the buzzer pin
            delay(tone1_delay);    // Wait to create the frequency
        }
        // Check if Button S2 is pressed
        else if (hiletgo_is_button_pressed(HILETGO_BUTTON_S2))
        {
            hiletgo_buzzer();
            delay(tone2_delay);
        }
        // Check if Button S3 is pressed
        else if (hiletgo_is_button_pressed(HILETGO_BUTTON_S3))
        {
            hiletgo_buzzer();
            delay(tone3_delay);
        }
        else
        {
            //Turning the buzzer off
        	GPIOB->ODR |= GPIO_ODR_OD3;
        }
    }
}
