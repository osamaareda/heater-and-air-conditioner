/* 
 * File:   init.h
 * Author: osama reda
 *
 * Created on february 6, 2024, 4:20 AM
 */

#ifndef ECUAL_INIT_H
#define	ECUAL_INIT_H
/*-------------------includes---------------------*/
#include "MCAL/INTERRUPT/mcal_internal_interrupt.h"
#include "MCAL/ADC/adc.h"
#include "MCAL/USART/usart.h"

/*--------------function declaration--------------*/
void _init(void);
void MY_ADC_ISR(void);
/*--------------------externs---------------------*/
extern usart_config_t uart;
extern adc_config_t adc;


#endif	/* ECUAL_INIT_H */