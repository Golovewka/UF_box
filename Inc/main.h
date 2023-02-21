/*
 * main.h
 *
 * Created: 20.02.2023 18:11:23
 *  Author: xzFle
 */ 


#ifndef MAIN_H_
#define MAIN_H_

typedef enum
{

	STATUS_IDLE = 0x00U,
	STATUS_OK = 0x01U,
	STATUS_ERROR = 0x02U,
	STATUS_BUSY = 0x03U,
	STATUS_TIMEOUT = 0x04U

} status_t;

#endif /* MAIN_H_ */