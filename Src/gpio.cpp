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
 * @brief ������� ������������� ������
 */
void GPIO_init(void)
{
	
	PORTA.DIR = PIN3_bm | PIN6_bm | PIN7_bm;                               // LED, DAC, RS_pin
	PORTB.DIR = PIN0_bm | PIN1_bm | PIN2_bm | PIN3_bm | PIN4_bm | PIN5_bm; // D3_pin, D2_pin, D1_pin, D0_pin, EN_pin, RW_pin
	PORTC.DIR = PIN0_bm | PIN1_bm | PIN2_bm | PIN3_bm;                     // D4_pin, D5_pin, D6_pin, D7_pin
	
}

/*
 * @bruef ������� ������ �������� � ���
 *
 * @param port ������������ �����
 * @param pin ������� ����� ����
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
 * @brief ������� ������ �������� � ����
 *
 * @param port ������������ �����
 * @param value ������������ ��������
 */
void GPIO_write_port(port_t &port, uint8_t value)
{
	
	port.OUT = value;
	
}

/*
 * @brief ������� ������������ �����
 *
 * @param port ������������ �����
 * @param pin ������� ����� ����
 */
void GPIO_touggle(port_t &port, pin_t pin)
{
	
	port.OUTTGL = pin;
	
}

/*
 * @brief ������� ������ ����
 *
 * @param port ������������ �����
 * @param pin ������� ����� �����
 * 
 * @return �������� �� ����
 * @retval 0 � pin
 */
uint8_t GPIO_read_pin (port_t &port, pin_t pin)
{
	
	pin_t temp = 0;
	
	temp = port.IN;
	temp = temp & pin;
	
	return(temp);	
	
}

/*
 * @brief ������� ������ �����
 * 
 * @param port ������������ �����
 *
 * @return �������� �� �����
 */
uint8_t GPIO_read_port (port_t &port)
{
	
	return(port.IN);
	
}

/*
 * @brief ������� ����� ������
 * ������ ����: ����-�����,
 * �����-����
 *
 * @param port ������������ �����
 * @param pin ������� ����� �����
 * @param mode ����� ������ ���� (0)
 * ����� (1)
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