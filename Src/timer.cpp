/*
 * timer.cpp
 *
 * Created: 20.02.2023 18:12:56
 *  Author: xzFle
 */ 
#include <avr/io.h>
#include "timer.h"

#define TCB_VALUE_MS     10000
#define TCB_VALUE_US     10
#define TCB_VALUE_MS_MAX 65535
#define TCB_VALUE_US_MAX 6553

void TIMERB_init(void);
void Timer_us (uint16_t us);
void Timer_ms (uint16_t ms);

/*
 * @brief Функция инициализации TIMERB (Используется как delay, для счёта времени)
 */
void TIMERB_init (void)
{
	
	TCB0.CTRLA = TCB_CLKSEL_CLKDIV2_gc; // Делитель таймера: 2
	TCB0.CTRLB = TCB_CNTMODE_SINGLE_gc; // Режим работы: одиночный
	
}

/*
 * @breif Функция включения таймера мкс
 *
 * @param us время в микросекундах
 */
void Timer_us (uint16_t us)
{
	
	if (us > TCB_VALUE_US_MAX) us = TCB_VALUE_US_MAX;
	
	TCB0.CNT = 0;
	TCB0.CCMP = TCB_VALUE_MS*us;
	TCB0.CTRLA |= TCB_ENABLE_bm;           // Включение таймера
	while(!(TCB0.INTFLAGS & TCB_CAPT_bm)); // Ожидание поднятия флага
	TCB0.INTFLAGS = TCB_CAPT_bm;           // Сброс флага прерывания
	
}

/*
 * @brief Функция включения таймера в мс
 *
 * @param ms время в милисекундах
 */
void Timer_ms (uint16_t ms)
{
	
	uint16_t cnt = 0;
	
	if (ms > TCB_VALUE_MS_MAX) ms = TCB_VALUE_MS_MAX;
	TCB0.CCMP = TCB_VALUE_MS;              // Запись значения, до которого считает таймер
	
	while (cnt < ms)
	{
		
		TCB0.CNT = 0;
		TCB0.CTRLA |= TCB_ENABLE_bm;           // Включение таймера
		while(!(TCB0.INTFLAGS & TCB_CAPT_bm)); // Ожидание поднятия флага
		TCB0.INTFLAGS = TCB_CAPT_bm;           // Сброс флага прерывания
		cnt++;
		
	}
	
}




