/* 
 * File:   mcal_internal_interrupt.h
 * Author: osama reda
 *
 * Created on October 8, 2023, 12:13 AM
 */

#ifndef MCAL_INTERNAL_INTERRUPT_H
#define	MCAL_INTERNAL_INTERRUPT_H

/*-----------------------includes-------------------------*/
#include"mcall_interrupt_cfg.h"

/* ----------------- Macro Functions Declarations -----------------*/
//==========ADC INTERRUPT========//
#if ADC_INTERRUPT_FEATURE==ENABLE
//enable the ADC interrupt 
#define ADC_InterruptEnable()        (PIE1bits.ADIE=1)
//disable the ADC interrupt
#define ADC_InterruptDisable()       (PIE1bits.ADIE=0)       
//clears the interrupt flag for the ADC interrupt
#define ADC_InterruptFlagClear()     (PIR1bits.ADIF=0);

#if INTERRUPT_PRIORITY_LEVELS==ENABLE
//set the ADC interrupt Priority to be High  
#define ADC_HighPrioritySet()        (IPR1bits.ADIP=1)
//set the ADC interrupt Priority to be low
#define ADC_LowPrioritySet()         (IPR1bits.ADIP=0)
#endif
#endif

//==========EUSART_TX INTERRUPT========//
#if EUSART_TX_INTERRUPT_FEATURE==ENABLE
/* This routine sets the interrupt enable for the EUSART Module */
#define EUSART_TX_InterruptEnable()          (PIE1bits.TXIE = 1)
/* This routine clears the interrupt enable for the EUSART Module */
#define EUSART_TX_InterruptDisable()         (PIE1bits.TXIE = 0)
#if INTERRUPT_PRIORITY_LEVELS==ENABLE 
/* This routine set the EUSART Module Interrupt Priority to be High priority */
#define EUSART_TX_HighPrioritySet()          (IPR1bits.TXIP = 1)
/* This routine set the EUSART Module Interrupt Priority to be Low priority */
#define EUSART_TX_LowPrioritySet()           (IPR1bits.TXIP = 0)
#endif
#endif

//==========EUSART_RX INTERRUPT========//
#if EUSART_RX_INTERRUPT_FEATURE==ENABLE
/* This routine sets the interrupt enable for the EUSART Module */
#define EUSART_RX_InterruptEnable()          (PIE1bits.RCIE = 1)
/* This routine clears the interrupt enable for the EUSART Module */
#define EUSART_RX_InterruptDisable()         (PIE1bits.RCIE = 0)
#if INTERRUPT_PRIORITY_LEVELS==ENABLE 
/* This routine set the EUSART Module Interrupt Priority to be High priority */
#define EUSART_RX_HighPrioritySet()          (IPR1bits.RCIP = 1)
/* This routine set the EUSART Module Interrupt Priority to be Low priority */
#define EUSART_RX_LowPrioritySet()           (IPR1bits.RCIP = 0)
#endif
#endif



#endif	/* MCAL_INTERNAL_INTERRUPT_H */