/*
 * clock.cpp
 *
 * Created: 20.02.2023 18:12:36
 *  Author: xzFle
 */
#include <avr/io.h>
#include "clock.h"

void CLOCK_init (void);

/*
 * @brief Функция конфигурации
 * системы тактирования микроконтроллера
 *
 * @note Тактовая частоты системы 20 МГц
 */
void CLOCK_init(void)
{
	
	CPU_CCP = CCP_IOREG_gc;                       // Снятие защиты с регистра
	CLKCTRL.MCLKCTRLB = ~CLKCTRL_PEN_bm;          // Выключение делителя
	while (CLKCTRL.MCLKSTATUS & CLKCTRL_SOSC_bm); // Ожидание включения
	
}
