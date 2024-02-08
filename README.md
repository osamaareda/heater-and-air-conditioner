# heater-and-air-conditioner
The first MCU gets the temperature reading from LM35 by the ADC module, then sends it to the second MCU using the UART module, the second MCU controls the operation as following:-
1) if the temperature is between 20 and 30 degrees, no operation happens.
2) if the temperature is higher than 30 degrees, the air conditioner turns on.
3) if the temperature is lower than 20 degrees, the heater turns on.
