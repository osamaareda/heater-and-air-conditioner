/* 
 * File:   init.h
 * Author: osama reda
 *
 * Created on february 6, 2024, 4:20 AM
 */

#ifndef ECUAL_INIT_H
#define	ECUAL_INIT_H
/*-------------------includes---------------------*/
#include "ECUAL/LED/led.h"
#include "ECUAL/DC_MOTOR/dc_motor.h"
#include "ECUAL/LCD/lcd.h"
#include "MCAL/INTERRUPT/mcal_internal_interrupt.h"
#include "MCAL/USART/usart.h"

/*--------------function declaration--------------*/
void _init(void);
void MY_EUSART_RX_ISR(void);
/*--------------------externs---------------------*/
extern usart_config_t uart;
extern lcd_config_t lcd;
extern dc_motor_config_t air_conditioners;
extern dc_motor_config_t heater;
extern led_config_t led_red;
extern led_config_t led_white;
extern led_config_t led_blue;
#endif	/* ECUAL_INIT_H */