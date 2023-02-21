/*
 * adc.cpp
 *
 * Created: 20.02.2023 18:13:05
 *  Author: xzFle
 */ 
#include <avr/io.h>

void ADC0_init (void);
void ADC1_init (void);
uint16_t ADC0_read (void);
uint16_t ADC1_read (void);

/*
 * @brief ������� ������������� ���0
 */
void ADC0_init (void)
{
	
	ADC0.CTRLB = ADC_SAMPNUM_ACC2_gc;                   // ���-�� �������������� ���, �� ���� ���������
	ADC0.CTRLC = ADC_SAMPCAP_bm | ADC_REFSEL_VDDREF_gc; // ����� ������� �������, ��������� �������� ���������� (VDD)
	ADC0.MUXPOS = ADC_MUXPOS_AIN4_gc;                   // ����� ������
	ADC0.CTRLA = ADC_ENABLE_bm;                         // ��������� ���
	
}

/*
 * @brief ������� ������������� ���1
 */
void ADC1_init (void)
{
	
	ADC1.CTRLB = ADC_SAMPNUM_ACC2_gc;                   // ���-�� �������������� ���, �� ���� ���������
	ADC1.CTRLC = ADC_SAMPCAP_bm | ADC_REFSEL_VDDREF_gc; // ����� ������� �������, ��������� �������� ���������� (VDD)
	ADC1.MUXPOS = ADC_MUXPOS_AIN1_gc;                   // ����� ������
	ADC1.CTRLA = ADC_ENABLE_bm;                         // ��������� ���
	
}

/*
 * @brief ������� ������ �������� � ���0
 */
uint16_t ADC0_read (void)
{
	
	uint16_t result = 0;
	
	ADC0.COMMAND = ADC_STCONV_bm;            // ��������� �������������� ���
	while(!(ADC0.INTFLAGS & ADC_RESRDY_bm)); // �������� ���������� ��������������
	result = ADC0.RES;
	
	return(result);
	
}

/*
 * @brief ������� ������ �������� � ���0
 */
uint16_t ADC1_read (void)
{
	
	uint16_t result = 0;
	
	ADC1.COMMAND = ADC_STCONV_bm;            // ��������� �������������� ���
	while(!(ADC1.INTFLAGS & ADC_RESRDY_bm)); // �������� ���������� ��������������
	result = ADC1.RES;
	
	return(result);
	
}