#include <stdint.h>
#include "stm32l476xx.h"
#include "hiletgo_driver.h"
/**************************************************************************************************
* @file main.c
* @Lab_3
* @author Noah Marchman
* @version 1.0
* ------------------------------------------------------------------------------------------------
* The purpose of this lab is to interact with the HiLetGo Shield for the first time. The goal is to
* move the lit LED up and down the block of LEDs using the included user buttons with S1 being used
* to move the LED up and S3 being used to move the LED down. The middle button was used to invert the
* mode making the target LED the only on off instead of the only one on.
* I used the 3 user buttons and 4 LED included in the HiLetGo Shield to complete this lab.
***************************************************************************************************/


//Software Delay for debounce
void delay(volatile uint32_t count) {
	while(count--){
		__NOP();
	}
}


int main(void)
{
	//Initializing the HILetG Shield
	hiletgo_init_shield();

	int current_led = HILETGO_LED_D1; // starting with the first LED
	int inverse_mode = 0; // 0 = normal, 1 = inverse

	//Storing previous button states to detect moment of a press
	int prev_btn1 = 0;
    int prev_btn2 = 0;
	int prev_btn3 = 0;

	//Main Loop
	while(1)
	{

		//Read the current button states
		int curr_btn1 = hiletgo_is_button_pressed(HILETGO_BUTTON_S1);
		int curr_btn2 = hiletgo_is_button_pressed(HILETGO_BUTTON_S2);
		int curr_btn3 = hiletgo_is_button_pressed(HILETGO_BUTTON_S3);

		//Left Button(S1) - Move Up
		if (curr_btn1 && !prev_btn1) {
			if (current_led > HILETGO_LED_D1) {
				current_led--; //Move LED Down
			}
		}

		//Right Button(S3) - Move Down
		if (curr_btn3 && !prev_btn3) {
			if (current_led < HILETGO_LED_D4) {
				current_led++; //Move LED Up
			}
		}

		//Center Button(S2) - Invert Mode
		if (curr_btn2 && !prev_btn2) {
			inverse_mode = !inverse_mode;
		}

		for (int i = 0; i < NUM_LEDS; i++) {
			if(!inverse_mode) {
				//Normal Mode: Only the target LED is lit
				if (i == current_led) {
					hiletgo_led_on(i);
				}
				else {
					hiletgo_led_off(i);
				}
			}
			else {
				//Inverted Mode: All LEDS are lit but target LED
				if (i == current_led) {
					hiletgo_led_off(i);
				}
				else {
					hiletgo_led_on(i);
				}
			}

		}

		//Saveing the current states
		prev_btn1 = curr_btn1;
        prev_btn2 = curr_btn2;
		prev_btn3 = curr_btn3;

		delay(2000);
	}

}
