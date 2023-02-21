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
 * @brief Функция инициализации АЦП0
 */
void ADC0_init (void)
{
	
	ADC0.CTRLB = ADC_SAMPNUM_ACC2_gc;                   // Кол-во преобразований АЦП, за одно включение
	ADC0.CTRLC = ADC_SAMPCAP_bm | ADC_REFSEL_VDDREF_gc; // Выбор емкости выборки, источника опорного напряжения (VDD)
	ADC0.MUXPOS = ADC_MUXPOS_AIN4_gc;                   // Выбор канала
	ADC0.CTRLA = ADC_ENABLE_bm;                         // Включение АЦП
	
}

/*
 * @brief Функция инициализации АЦП1
 */
void ADC1_init (void)
{
	
	ADC1.CTRLB = ADC_SAMPNUM_ACC2_gc;                   // Кол-во преобразований АЦП, за одно включение
	ADC1.CTRLC = ADC_SAMPCAP_bm | ADC_REFSEL_VDDREF_gc; // Выбор емкости выборки, источника опорного напряжения (VDD)
	ADC1.MUXPOS = ADC_MUXPOS_AIN1_gc;                   // Выбор канала
	ADC1.CTRLA = ADC_ENABLE_bm;                         // Включение АЦП
	
}

/*
 * @brief Функция чтения значения с АЦП0
 */
uint16_t ADC0_read (void)
{
	
	uint16_t result = 0;
	
	ADC0.COMMAND = ADC_STCONV_bm;            // Включение преобразования АЦП
	while(!(ADC0.INTFLAGS & ADC_RESRDY_bm)); // Ожидание завершения преобразования
	result = ADC0.RES;
	
	return(result);
	
}

/*
 * @brief Функция чтения значения с АЦП0
 */
uint16_t ADC1_read (void)
{
	
	uint16_t result = 0;
	
	ADC1.COMMAND = ADC_STCONV_bm;            // Включение преобразования АЦП
	while(!(ADC1.INTFLAGS & ADC_RESRDY_bm)); // Ожидание завершения преобразования
	result = ADC1.RES;
	
	return(result);
	
}