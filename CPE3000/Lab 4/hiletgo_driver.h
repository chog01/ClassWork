#include <stdint.h>
#include <stm32l476xx.h>

/**
  ***************************************************************************************
  *  @file    hiletgo-driver.h
  *  @author  Scott Tippens
  *  		  Noah Marchman
  *  @brief   Header for hiletgo-driver.c module
  *
  *      Defines identifiers useful when interacting with the HiLetGo driver functions.
  *      Also defines the structures used for grouping buttons and leds into arrays so
  *      that processing each resource can be streamlined.
  *
  *      NOTE: static inline functions provide the most efficient interface for simple
  *      accesses to the resources and are defined here. The hiletgo_init_shield function
  *      is defined in the hiletgo-driver.c file
  *
  ***************************************************************************************
  */
#ifndef __HILETGO_DRIVER_H
#define __HILETGO_DRIVER_H


    //--identifiers-for-board-leds-------------------------------------------------------
    #define HILETGO_LED_D1  0
    #define HILETGO_LED_D2  1
    #define HILETGO_LED_D3  2
    #define HILETGO_LED_D4  3


    //--identifiers-for-board-buttons----------------------------------------------------
    #define HILETGO_BUTTON_S1  0
    #define HILETGO_BUTTON_S2  1
    #define HILETGO_BUTTON_S3  2


    void hiletgo_init_shield(void);
    static inline void hiletgo_led_on(int theLed);
    static inline void hiletgo_led_off(int theLed);
    static inline void hiletgo_led_toggle(int theLed);
    static inline int  hiletgo_is_button_pressed(int theButton);
    static inline void hiletgo_buzzer(void);

    //--leds-----------------------------------------------------------------------------
    #define  NUM_LEDS  4
    struct led
    {
        GPIO_TypeDef  *port;
        uint32_t       pin;
    };
    extern struct led leds[NUM_LEDS];


    //--buttons--------------------------------------------------------------------------
    #define  NUM_BUTTONS  3
    struct button
    {
        GPIO_TypeDef  *port;
        uint32_t       pin;
    };
    extern struct button buttons[NUM_BUTTONS];



    //===================================================================================
    //  hiletgo_led_on(theLed)
    //
    //  @param:   int  theLed  -  Identifies the led to turn on.
    //                            WARNING: Only use constants in hiletgo-driver.h
    //  @return:  none
    //===================================================================================
    static inline void hiletgo_led_on(int theLed)
    {
        leds[theLed].port->ODR  &=  ~(1U << leds[theLed].pin);
    }



    //===================================================================================
    //  hiletgo_led_off(theLed)
    //
    //  @param:   int  theLed  -  Identifies the led to turn off.
    //                            WARNING: Only use constants in hiletgo-driver.h
    //  @return:  none
    //===================================================================================
    static inline void hiletgo_led_off(int theLed)
    {
        leds[theLed].port->ODR  |=  1U << leds[theLed].pin;
    }



    //===================================================================================
    //  hiletgo_led_toggle(theLed)
    //
    //  @param:   int  theLed  -  Identifies the led to toggle.
    //                            WARNING: Only use constants in hiletgo-driver.h
    //  @return:  none
    //===================================================================================
    static inline void hiletgo_led_toggle(int theLed)
    {
        leds[theLed].port->ODR  ^=  1U << leds[theLed].pin;
    }



    //===================================================================================
    //  hiletgo_is_button_pressed(theButton)
    //
    //  @param:   int  theButton  -  Identifies the button to test.
    //  @return:  int  !0 = pressed (true)
    //                  0 = not pressed (false)
    //===================================================================================
    static inline int hiletgo_is_button_pressed(int theButton)
    {
        return !(buttons[theButton].port->IDR & (1U << buttons[theButton].pin));
    }

    //===================================================================================
    //	hiletgo_buzzer(void)
    //
    //	@param:	none
    //	@return: none
    //===================================================================================
    static inline void hiletgo_buzzer(void)
    {
    	GPIOB->ODR ^= GPIO_ODR_OD3;
    }

#endif /* __HILETGO_DRIVER_H */

