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
 * @brief ������� ������������
 * ������� ������������ ����������������
 *
 * @note �������� ������� ������� 20 ���
 */
void CLOCK_init(void)
{
	
	CPU_CCP = CCP_IOREG_gc;                       // ������ ������ � ��������
	CLKCTRL.MCLKCTRLB = ~CLKCTRL_PEN_bm;          // ���������� ��������
	while (CLKCTRL.MCLKSTATUS & CLKCTRL_SOSC_bm); // �������� ���������
	
}
