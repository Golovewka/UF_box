/*
 * adc.h
 *
 * Created: 20.02.2023 18:13:49
 *  Author: xzFle
 */ 


#ifndef ADC_H_
#define ADC_H_

void ADC0_init (void);
void ADC1_init (void);
uint16_t ADC0_read (void);
uint16_t ADC1_read (void);

#endif /* ADC_H_ */