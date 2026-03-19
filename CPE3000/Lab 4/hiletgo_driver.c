#include <hiletgo_driver.h>
#include <stdint.h>
#include <stm32l476xx.h>

/**
 ****************************************************************************************
 * @file     hiletgo-driver.c
 * @brief    API for accessing the HiLetGo multi-function shield resources.
 * @author   Scott Tippens
 * @version  1.0
 * --------------------------------------------------------------------------------------
 *
 *  HiLetGo Driver
 *
 *       This driver provides an interface to the HiLetGo Multi-function shield. The
 *       interface functions are summarized as:
 *
 *           hiletgo_init_shield() ......... initializes ports that interface the board
 *           hiletgo_led_on() .............. turn on the identified LED
 *           hiletgo_led_off() ............. turn of the identified LED
 *           hiletgo_led_toggle() .......... toggle the identified LED
 *           hiletgo_is_button_pressed() ... test the identified button
 *
 *       Use the predefined constants for LED and buttons when calling these functions
 *       since they are not bounds checked. The constants can be seen below in the
 *       array creation or in the hiletgo-driver.h header file.
 *
 *       NOTE: The LED and button functions are declared as static inline and are thus
 *       defined in the hiletgo-driver.h header file.
 *
 ****************************************************************************************
 */

struct led leds[NUM_LEDS] = { [HILETGO_LED_D1]={GPIOA,5},
                              [HILETGO_LED_D2]={GPIOA,6},
                              [HILETGO_LED_D3]={GPIOA,7},
                              [HILETGO_LED_D4]={GPIOB,6} };

struct button buttons[NUM_BUTTONS] = { [HILETGO_BUTTON_S1]={GPIOA,1},
                                       [HILETGO_BUTTON_S2]={GPIOA,4},
                                       [HILETGO_BUTTON_S3]={GPIOB,0} };


//=======================================================================================
//  hiletgo_init_shield()
//
//  @param:   none
//  @return:  none
//
//      Configure the GPIO pin resources for the HiLetGo Multi-function Shield.
//=======================================================================================
void hiletgo_init_shield(void)
{
    //-----------------------------------------------------------------------------------
    //  Enable Ports Used by HiLetGo Board
    //-----------------------------------------------------------------------------------
    RCC->AHB2ENR  |=  RCC_AHB2ENR_GPIOAEN;        // Enable port A
    RCC->AHB2ENR  |=  RCC_AHB2ENR_GPIOBEN;        // Enable port B


    //-----------------------------------------------------------------------------------
    //  Configure LED D1
    //      This LED is different from the other LEDs. Unfortunately it is shared with
    //      the user LED on the Nucleo-L476RG board. It must be push-pull to properly
    //      turn off the D1 LED on the HiLetGo board.
    //-----------------------------------------------------------------------------------
    GPIOA->MODER    = (GPIOA->MODER & ~GPIO_MODER_MODE5)
                      | GPIO_MODER_MODE5_0;                 // output pin
    GPIOA->OTYPER  &= ~ GPIO_OTYPER_OT5;                    // push-pull
    GPIOA->OSPEEDR &= ~(GPIO_OSPEEDR_OSPEED5);              // low speed
    GPIOA->PUPDR   &= ~(GPIO_PUPDR_PUPD5);                  // no pullup,pulldown


    //-----------------------------------------------------------------------------------
    //  Configure LEDs D2, D3, D4
    //      These LEDs connect to an external pull-up resistor so open-drain is
    //      appropriate.
    //-----------------------------------------------------------------------------------
    for (int i=1; i<NUM_LEDS; i++)
    {
        leds[i].port->MODER    =  (leds[i].port->MODER & ~(0x3U << (2U*leds[i].pin)))
                                  | (0x1U << (2U*leds[i].pin));    // output pin
        leds[i].port->OTYPER  |=  (0x1U << leds[i].pin);           // open drain
        leds[i].port->OSPEEDR &= ~(0x3U << (2U*leds[i].pin));      // low speed
        leds[i].port->PUPDR   &= ~(0x3U << (2U*leds[i].pin));      // no pullup,pulldown
    }


    //-----------------------------------------------------------------------------------
    //  Configure Buttons S1, S2, S3
    //-----------------------------------------------------------------------------------
    for (int i=0; i<NUM_BUTTONS; i++)
    {
        buttons[i].port->MODER &= ~(0x3U << (2U*buttons[i].pin));   // input pin
        buttons[i].port->PUPDR &= ~(0x3U << (2U*buttons[i].pin));   // no pullup,pulldown
    }

    //-----------------------------------------------------------------------------------
    //	Configure Buzzer LS1
    //-----------------------------------------------------------------------------------
    GPIOB->MODER    = (GPIOB->MODER & ~GPIO_MODER_MODE3)
                      | GPIO_MODER_MODE3_0;                        // output pin
    GPIOB->OTYPER  |= GPIO_OTYPER_OT3;								// open drain
    GPIOB->OSPEEDR |= (GPIO_OSPEEDR_OSPEED3); 						// very high speed
    GPIOB->PUPDR   &= ~(GPIO_PUPDR_PUPD3);							// no pullup,pulldown
}
