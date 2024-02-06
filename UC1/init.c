/* 
 * File:   init.c
 * Author: osama reda
 *
 * Created on february 6, 2024, 4:20 AM
 */
#include "init.h"

/*============================uart configuration===========================*/
usart_config_t uart={
    .baudrate=9600,
    .baudrate_gen_gonfig=BAUDRATE_ASYN_8BIT_lOW_SPEED,
    .usart_tx_cfg.usart_tx_enable=EUSART_ASYNCHRONOUS_TX_ENABLE,
    .usart_tx_cfg.usart_tx_9bit_enable=EUSART_ASYNCHRONOUS_9Bit_TX_DISABLE,
    .usart_tx_cfg.usart_tx_interrupt_enable=EUSART_ASYNCHRONOUS_INTERRUPT_TX_ENABLE,
};
/*============================adc configuration===========================*/
adc_config_t adc={
    .ADC_InterruptHandler=MY_ADC_ISR,
    .acquisition_time=ADC_12_TAD,
    .adc_channel=ADC_CHANNEL_AN0,
    .result_format=ADC_RESULT_RIGHT,
    .voltage_reference=ADC_VOLTAGE_REFERENCE_DISABLED,
    .conversion_clock=ADC_CONVERSION_CLOCK_FOSC_DIV_16
};


void _init(void){
    Std_ReturnType ret=E_NOT_OK;
    ret=EUSART_ASYNC_Init(&uart);
    ret=ADC_Init(&adc);
    
}
