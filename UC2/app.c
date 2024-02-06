/* 
 * File:   app.c
 * Author: osama reda
 * 
 * Created on february 6, 2024, 4:20 AM
 */
 
 
#include"app.h"

Std_ReturnType ret=E_NOT_OK;
volatile uint8 uart_value;

/*=============================main code===============================*/
void MY_EUSART_RX_ISR(void){
    EUSART_ASYNC_ReadByteNonBlocking(&uart_value);
    lcd_send_number_pos(&lcd,1,10,uart_value);
    if(uart_value>=30){
        ret=dc_motor_move_right(&air_conditioners);
        ret=led_on(&led_blue);
        ret=led_off(&led_white);
        ret=led_off(&led_red);
    }
    else if(uart_value<30 && uart_value>20 ){
        ret=dc_motor_stop(&air_conditioners);
        ret=dc_motor_stop(&heater);
        ret=led_off(&led_blue);
        ret=led_on(&led_white);
        ret=led_off(&led_red);
    }
    else if(uart_value<=20){
        ret=dc_motor_move_right(&heater);
        ret=led_off(&led_blue);
        ret=led_off(&led_white);
        ret=led_on(&led_red);
    }
}

int main() {
    
    _init();
    
    
while(1)
{
  
}
    return (EXIT_SUCCESS);
}
