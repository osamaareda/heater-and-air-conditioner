/* 
 * File:   init.c
 * Author: osama reda
 *
 * Created on february 6, 2023, 1:10 AM
 */
#include "init.h"

/*============================uart configuration===========================*/
usart_config_t uart={
    .baudrate=9600,
    .baudrate_gen_gonfig=BAUDRATE_ASYN_8BIT_lOW_SPEED,
    .usart_rx_cfg.usart_rx_enable=EUSART_ASYNCHRONOUS_RX_ENABLE,
    .usart_rx_cfg.usart_rx_9bit_enable=EUSART_ASYNCHRONOUS_9Bit_RX_DISABLE,
    .usart_rx_cfg.usart_rx_interrupt_enable=EUSART_ASYNCHRONOUS_INTERRUPT_RX_ENABLE,
    .EUSART_RxDefaultInterruptHandler=MY_EUSART_RX_ISR
};
/*============================lcd configuration===========================*/
lcd_config_t lcd={.lcd_rs.port=PORTC_INDEX,.lcd_rs.pin=PIN4,
                  .lcd_en.port=PORTC_INDEX,.lcd_en.pin=PIN5,
                  .lcd_pins[0].port=PORTC_INDEX,.lcd_pins[0].pin=PIN0,
                  .lcd_pins[1].port=PORTC_INDEX,.lcd_pins[1].pin=PIN1,
                  .lcd_pins[2].port=PORTC_INDEX,.lcd_pins[2].pin=PIN2,
                  .lcd_pins[3].port=PORTC_INDEX,.lcd_pins[3].pin=PIN3};

/*============================motor configuration===========================*/
//air conditioners
dc_motor_config_t air_conditioners={.dc_motor_pin0.port=PORTD_INDEX,.dc_motor_pin0.pin=PIN0,
                          .dc_motor_pin1.port=PORTD_INDEX,.dc_motor_pin1.pin=PIN1};
//heater
dc_motor_config_t heater={.dc_motor_pin0.port=PORTD_INDEX,.dc_motor_pin0.pin=PIN2,
                          .dc_motor_pin1.port=PORTD_INDEX,.dc_motor_pin1.pin=PIN3};

/*============================led configuration===========================*/
led_config_t led_red={.led_pin.port=PORTD_INDEX,.led_pin.pin=PIN4};
led_config_t led_white={.led_pin.port=PORTD_INDEX,.led_pin.pin=PIN5};
led_config_t led_blue={.led_pin.port=PORTD_INDEX,.led_pin.pin=PIN6};

void _init(void){
    Std_ReturnType ret=E_NOT_OK;
    ret=EUSART_ASYNC_Init(&uart);
    ret=lcd_init(&lcd);
    ret=dc_motor_init(&air_conditioners);
    ret=dc_motor_init(&heater);
    led_init(&led_red);
    led_init(&led_white);
    led_init(&led_blue);
}
