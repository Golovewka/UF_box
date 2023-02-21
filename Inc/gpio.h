/*
 * gpio.h
 *
 * Created: 20.02.2023 18:13:30
 *  Author: xzFle
 */ 


#ifndef GPIO_H_
#define GPIO_H_

typedef uint8_t pin_t;
typedef PORT_t port_t;

void GPIO_init (void);
void GPIO_write_pin(port_t &port, pin_t pin);
void GPIO_write_port(port_t &port, uint8_t value);
void GPIO_touggle(port_t &port, pin_t pin);
uint8_t GPIO_read_pin (port_t &port, pin_t pin);
uint8_t GPIO_read_port (port_t &port);
void GPIO_switch_pin_mode (port_t &port, pin_t pin, uint8_t mode);

#endif /* GPIO_H_ */