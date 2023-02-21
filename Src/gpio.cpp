/*
 * gpio.cpp
 *
 * Created: 20.02.2023 18:12:45
 *  Author: xzFle
 */
#include <avr/io.h>
#include "gpio.h"

void GPIO_init (void);
void GPIO_write_pin(port_t &port, pin_t pin);
void GPIO_write_port(port_t &port, uint8_t value);
void GPIO_touggle(port_t &port, pin_t pin);
uint8_t GPIO_read_pin (port_t &port, pin_t pin);
uint8_t GPIO_read_port (port_t &port);
void GPIO_switch_pin_mode (port_t &port, pin_t pin, uint8_t mode);

/*
 * @brief Функция инициализации портов
 */
void GPIO_init(void)
{
	
	PORTA.DIR = PIN3_bm | PIN6_bm | PIN7_bm;                               // LED, DAC, RS_pin
	PORTB.DIR = PIN0_bm | PIN1_bm | PIN2_bm | PIN3_bm | PIN4_bm | PIN5_bm; // D3_pin, D2_pin, D1_pin, D0_pin, EN_pin, RW_pin
	PORTC.DIR = PIN0_bm | PIN1_bm | PIN2_bm | PIN3_bm;                     // D4_pin, D5_pin, D6_pin, D7_pin
	
}

/*
 * @bruef Функция записи значения в пин
 *
 * @param port наименования порта
 * @param pin битовая маска пина
 */
void GPIO_write_pin(port_t &port, pin_t pin)
{
	
	uint8_t tmp = ~pin;
	
	if (pin < tmp)
	{
		
		if (pin == 0x7F) port.OUTCLR = tmp;
		else port.OUTSET = pin;
		
	}
	else
	{
		
		if (pin == 0x80) port.OUTSET = pin;
		else port.OUTCLR = tmp;
		
	}
	
}

/*
 * @brief Функция записи значения в порт
 *
 * @param port наименования порта
 * @param value записываемое значение
 */
void GPIO_write_port(port_t &port, uint8_t value)
{
	
	port.OUT = value;
	
}

/*
 * @brief Функция переключения порта
 *
 * @param port наименования порта
 * @param pin битовая маска пина
 */
void GPIO_touggle(port_t &port, pin_t pin)
{
	
	port.OUTTGL = pin;
	
}

/*
 * @brief Функция чтения пина
 *
 * @param port наименование порта
 * @param pin битовая маска порта
 * 
 * @return значение на пине
 * @retval 0 и pin
 */
uint8_t GPIO_read_pin (port_t &port, pin_t pin)
{
	
	pin_t temp = 0;
	
	temp = port.IN;
	temp = temp & pin;
	
	return(temp);	
	
}

/*
 * @brief Функция чтения порта
 * 
 * @param port наименование порта
 *
 * @return значение на порте
 */
uint8_t GPIO_read_port (port_t &port)
{
	
	return(port.IN);
	
}

/*
 * @brief Функция смены режима
 * работы пина: вход-выход,
 * выход-вход
 *
 * @param port наименование порта
 * @param pin битовая маска порта
 * @param mode выбор режима вход (0)
 * выход (1)
 */
void GPIO_switch_pin_mode (port_t &port, pin_t pin, uint8_t mode)
{
	
	switch(mode)
	{
		
		case 0: // OUT->IN
		
			port.OUT &= ~pin;
			port.DIR &= ~pin;
			port.IN &= ~pin;
		
		break;
		
		case 1: // IN->OUT
		
			port.IN &= ~pin;
			port.DIR |= pin;
			port.OUT &= ~pin;
		
		break;
		
		default: break;
		
	}
	
}