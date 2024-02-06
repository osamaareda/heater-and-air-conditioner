/* 
 * File:   mcall_interrupt_manager.h
 * Author: osama reda
 *
 * Created on October 8, 2023, 12:14 AM
 */

#ifndef MCALL_INTERRUPT_MANAGER_H
#define	MCALL_INTERRUPT_MANAGER_H

/*-----------------------includes-------------------------*/
#include"mcall_interrupt_cfg.h"

/*----------------function declaration-----------------*/

void ADC_ISR(void);
void EUSART_TX_ISR(void);
void EUSART_RX_ISR(void);
#endif	/* MCALL_INTERRUPT_MANAGER_H */