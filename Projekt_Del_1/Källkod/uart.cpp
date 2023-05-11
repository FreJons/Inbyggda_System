#include "UART.h" //Inkluderar en headerfil för UART-funktioner

void USART2_Init(void) { //Deklarerar en funktion för initiering av UART2



RCC->APB1ENR |= 0x20000; //Möjliggör klocktillgång för uart2, detta görs genom att man aktiverar UART2 och sätter bit 17 i APB1ENR till 1.



RCC->AHB1ENR |= 0x01; //Möjliggör klocktillgång för portA genom att aktivera GPIOA och sätta bit 0 i AHB1ENR till 1.


GPIOA->MODER &= ~0x00F0; //Rensar bitarna 4-7 för att förbereda pins PA2 och PA3 för alternativ funktion.
  

GPIOA->MODER |= 0x00A0; //För alternativ funktion på pin PA2 & PA3 sätts bitar 5 och 7 till värde 1 


GPIOA->AFR[0] &= ~0xFF00; //För att förbereda pin PA2 & PA3 för användning av alternativ funktion så rensas bitarna 8-15
GPIOA->AFR[0] |= 0x7700; //Sätter bitarna 8-11 och 12-15 till formatet 0111 för att välja alternativ funktion för pins PA2 och PA3



USART2->BRR = 0x0683; //Hexvärdet 0x0683 sätter baudhastigheten till 9600 bps
USART2->CR1 = 0x000C; //Sätter datastorleken till 8 bitar, ingen paritet och 1 stoppbit
USART2->CR2 = 0x000; //Nollställer CR2
USART2->CR3 = 0x000; //Nollställer CR3
USART2->CR1 |= 0x2000; //Aktiverar UART genom att sätta bit 13 i CR1 till 1

}

int USART2_write(int ch){ //Deklarerar en funktion för att skriva data till UART

  while(!(USART2->SR & 0x0080)){} //Väntar tills överföringen är klar och kan ta emot nästa byte
  USART2->DR = (ch & 0xFF); //Överför data till dataregistret 

  return ch; //Returnerar den överförda datan

}

int USART2_read(void){ //Deklarerar en funktion för att läsa data från UART

  while(!(USART2->SR & 0x0020)){} //Väntar tills det finns mer data att hämta
  return USART2->DR; //Hämtar datan från dataregistret och returnerar den
}