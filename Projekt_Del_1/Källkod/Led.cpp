#include "LED.h" //Inkluderar LED.h headerfilen för att ge klassen information om LED-beteckningar och funktioner

//Konstruktorn för LED-lamporna tar två parametrar: färg och status
Led::Led(LedColor_Type _color, LedState_Type _state)
{
  //Sätter instansvariablerna color och state i klassen till de värden som har skickats in som parametrar
  this->color = _color;
  this->state = _state;

  //Aktiverar klockan för GPIO-porten som LED-lamporna är kopplade till
  RCC->AHB1ENR |= LED_PORT_CLOCK;

  //Switchen nedan konfigurerar GPIO-pinnarna för den valda LED-lampan baserat på dess färg och status genom att sätta portläget för LED-konfigurationen till output.
  //Om önskad status är ON, sätter man GPIO-portens output-pinnar till hög för att tända LED-lampan. Annars sätts pinnarna till låg för att släcka LED-lampan
  switch(_color){

    case RED: //Sätta portläget till output
      LED_PORT->MODER |= LED_RED_MODE_BIT;
      if(this->state == ON){
        //Tända LED
        LED_PORT->ODR |= LED_RED_PIN;
      }
      else{
        //Släcka LED
        LED_PORT->ODR &= ~LED_RED_PIN;
      }
      break;

      case YELLOW: //Sätta portläget till output
      LED_PORT->MODER |= LED_YELLOW_MODE_BIT;
      if(this->state == ON){
        //Tända LED
        LED_PORT->ODR |= LED_YELLOW_PIN;
      }
      else{
        //Släcka LED
        LED_PORT->ODR &= ~LED_YELLOW_PIN;
      }
      break;

      case BLUE: //Sätta portläget till output
      LED_PORT->MODER |= LED_BLUE_MODE_BIT;
      if(this->state == ON){
        //Tända LED
        LED_PORT->ODR |= LED_BLUE_PIN;
      }
      else{
        //Släcka LED
        LED_PORT->ODR &= ~LED_BLUE_PIN;
      }
      break;

      case GREEN: //Sätta portläget till output
      LED_PORT->MODER |= LED_GREEN_MODE_BIT;
      if(this->state == ON){
        //Tända LED
        LED_PORT->ODR |= LED_GREEN_PIN;
      }
      else{
        //Släcka LED
        LED_PORT->ODR &= ~LED_GREEN_PIN;
      }
      break;

  }


}

void Led::setState(LedState_Type _state){

  //Om statusen på en LED-lampa ska ändras, används funktionen setState() för att sätta den nya statusen
  this->state = _state;

  //Kontrollera att rätt LED ändras genom att kolla färgen på LED
  switch(this->color){

      //om LED Röd
    case RED:
      //Konfigurerar GPIO-pinnarna för den valda LED-lampan baserat på dess färg och status genom att sätta portläget för LED-konfigurationen till output
      LED_PORT->MODER |= LED_RED_MODE_BIT;
      //Om önskad status är ON, sätter man GPIO-portens output-pinnar till hög för att tända LED-lampan. Annars sätts pinnarna till låg för att släcka LED-lampan
      if(this->state == ON){
        //Aktiverar pin output 
        LED_PORT->ODR |= LED_RED_PIN;
      }
      else{
        //Inaktiverar pin output
        LED_PORT->ODR &= ~LED_RED_PIN;
      }
      break;

      case YELLOW:
      //Konfigurerar GPIO-pinnarna för den valda LED-lampan baserat på dess färg och status genom att sätta portläget för LED-konfigurationen till output
      LED_PORT->MODER |= LED_YELLOW_MODE_BIT;
      //Om önskad status är ON, sätter man GPIO-portens output-pinnar till hög för att tända LED-lampan. Annars sätts pinnarna till låg för att släcka LED-lampan
      if(this->state == ON){
        //Aktiverar pin output
        LED_PORT->ODR |= LED_YELLOW_PIN;
      }
      else{
        //Inaktiverar pin output
        LED_PORT->ODR &= ~LED_YELLOW_PIN;
      }
      break;

      case BLUE:
      //Konfigurerar GPIO-pinnarna för den valda LED-lampan baserat på dess färg och status genom att sätta portläget för LED-konfigurationen till output
      LED_PORT->MODER |= LED_BLUE_MODE_BIT;
      //Om önskad status är ON, sätter man GPIO-portens output-pinnar till hög för att tända LED-lampan. Annars sätts pinnarna till låg för att släcka LED-lampan
      if(this->state == ON){
        //Aktiverar pin output
        LED_PORT->ODR |= LED_BLUE_PIN;
      }
      else{
        //Inaktiverar pin output
        LED_PORT->ODR &= ~LED_BLUE_PIN;
      }
      break;

      case GREEN:
      //Konfigurerar GPIO-pinnarna för den valda LED-lampan baserat på dess färg och status genom att sätta portläget för LED-konfigurationen till output
      LED_PORT->MODER |= LED_GREEN_MODE_BIT;
      //Om önskad status är ON, sätter man GPIO-portens output-pinnar till hög för att tända LED-lampan. Annars sätts pinnarna till låg för att släcka LED-lampan
      if(this->state == ON){
        //Aktiverar pin output
        LED_PORT->ODR |= LED_GREEN_PIN;
      }
      else{
        //Inaktiverar pin output
        LED_PORT->ODR &= ~LED_GREEN_PIN;
      }
      break;
  }

}

LedState_Type Led::getState(void)const{

  //Om man vill kontrollera statusen för en LED-lampa, används funktionen getState() för att returnera statusen
  switch(this->color){

    case RED:
      break;

    case YELLOW:
      break;

    case BLUE:
      break;

    case GREEN:
      break;
  }
             //Funktionen getState() kontrollerar färgen på den efterfrågade LED-lampan och returnerar dess status
             return this->state;
}
