/* 
 * File:   app.c
 * Author: osama reda
 * 
 * Created on february 6, 2024, 4:20 AM
 */
 
 
#include"app.h"

Std_ReturnType ret=E_NOT_OK;
volatile uint16 adc_value;


/*=============================main code===============================*/
void MY_ADC_ISR(void){
    ret=ADC_GetConversionResult(&adc,&adc_value);
    ret=EUSART_ASYNC_WriteByteNonBlocking(adc_value*4.88/10);
}

int main() {
    
    _init();
    
    
while(1)
{
    ret=ADC_StartConversion_Interrupt(&adc,ADC_CHANNEL_AN0);
}
    return (EXIT_SUCCESS);
}
