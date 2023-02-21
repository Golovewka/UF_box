/*
 * UF_box.cpp
 *
 * Created: 20.02.2023 18:08:47
 * Author : xzFle
 */ 
#define F_CPU 20000000

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "main.h"
#include "clock.h"
#include "gpio.h"
#include "adc.h"
#include "timer.h"

int main(void)
{
    
	CLOCK_init();
	GPIO_init();
	ADC0_init();
	ADC1_init();
	TIMERB_init();
	
	port_t *DAC_port;
	DAC_port = &PORTA;
	pin_t DAC_pin = PIN6_bm;
	
	port_t *LED_port;
	LED_port = &PORTA;
	pin_t LED_pin = PIN3_bm;
	
    while (1) 
    {
		
		GPIO_write_pin(*LED_port, LED_pin);
		Timer_ms(500);
		GPIO_write_pin(*LED_port, ~LED_pin);
		Timer_ms(500);
		
    }
	
}


