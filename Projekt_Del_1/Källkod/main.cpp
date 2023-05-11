#include "led.h"

//Skapar variabler för de olika ledlamporna
LedState_Type led1_state;
LedState_Type led2_state;
LedState_Type led3_state;

Led led1(RED,ON); //Skapar en instans av klassen Led med namnet led1, som är en röd LED-lampa som sätts i läge ON

int main(void){ //Startar huvudfunktionen i programmet som konstruerar och hanterar LED-lamporna
  USART2_Init(); //Kallar på funktionen för initiering av USART2 som finns i uart.cpp

  Led led2(BLUE,ON); // Instans led2 i klassen Led med två inparametrar av typen LedColor_Type för definition av färg och LedState_Type som sätter LED i läge ON

  Led *led3 = new Led(YELLOW,ON); //Skapar en pekare till en instans av klassen Led med namnet led3, som sätter gul LED-lampa i läge ON

  led1_state = led1.getState(); //Returnerar status på led1 genom getState funktionen i Led.cpp

  led1.setState(OFF); // Sätter status på led1 till OFF med hjälp av setState funktionen i Led.cpp

  delete led3; //Tar bort led3 instansen och frigör minnet som användes för den

  while(1){} //En evighetsloop som gör att programmet fortsätter att köras utan att avslutas

}
