#ifndef __UART_H //"include guard" som ser till att koden i header-filen inte inkluderas mer än en gång i en kompilering
#define __UART_H //Definierar en konstant __UART_H som indikerar att header-filen har inkluderats i koden

#include "stm32f4xx.h" //Inkluderar filen stm32f4xx.h, som innehåller deklarationer av register och funktioner för användning med STM32F4-mikrokontrollern 
#include <stdio.h> //Inkluderar standard biblioteket stdio.h som definierar standard in och ut funktioner

void USART2_Init(void); // Funktionsdeklaration som kallar på och refererar till deklarationen av UART-funktionen
void test_setup(void); //Funktionsdeklaration som kallar på och refererar till testfunktionen som var i UART.c, denna används dock inte i detta fall
#endif // Markerar slutet av include guard
