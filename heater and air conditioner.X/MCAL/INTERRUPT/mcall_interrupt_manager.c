/* 
 * File:   mcall_interrupt_manager.c
 * Author: osama reda
 *
 * Created on October 8, 2023, 12:14 AM
 */

#include"mcall_interrupt_manager.h"
static volatile uint8 RB4_Flag = 1, RB5_Flag = 1, RB6_Flag = 1, RB7_Flag = 1;
#if INTERRUPT_PRIORITY_LEVELS==ENABLE
void __interrupt() InterruptManagerHigh(void){
    
    
    /* ================ ADC Interrupt Start ================= */
    if((INTERRUPT_ENABLE == PIE1bits.ADIE) && (INTERRUPT_OCCUR == PIR1bits.ADIF)){
        ADC_ISR();
    }
    /* ================ TIMER0 Interrupt Start ================= */
    if((INTERRUPT_ENABLE == INTCONbits.T0IE) && (INTERRUPT_OCCUR == INTCONbits.T0IF)){
        TMR0_ISR();
    }
}

void __interrupt(low_priority) InterruptManagerLow(void){
    /* ============ INTx External Interrupt Start ============ */
    if((INTERRUPT_ENABLE == INTCON3bits.INT1E) && (INTERRUPT_OCCUR == INTCON3bits.INT1F)){
        INT1_ISR();
    }
    /* ============ INTx External Interrupt End ============ */
    
     /* ============ PortB External Interrupt Start ============ */
    
    /* ============ PortB External Interrupt END ============ */
    
    /* ================ ADC Interrupt Start ================= */
    
    /* ================= TIMER0 Interrupt Start ================== */
}

#else
void __interrupt() InterruptManager(void){
    
    /* ================ ADC Interrupt Start ================= */
    if((INTERRUPT_ENABLE == PIE1bits.ADIE) && (INTERRUPT_OCCUR == PIR1bits.ADIF)){
        ADC_ISR();
    }
    /* ================ EUSART_TX Interrupt Start ================= */
    if((INTERRUPT_ENABLE == PIE1bits.TXIE) && (INTERRUPT_OCCUR == PIR1bits.TXIF)){
        EUSART_TX_ISR();
    }
    
    /* ================ EUSART_RX Interrupt Start ================= */
    if((INTERRUPT_ENABLE == PIE1bits.RCIE) && (INTERRUPT_OCCUR == PIR1bits.RCIF)){
        EUSART_RX_ISR();
    }
    
}
#endif