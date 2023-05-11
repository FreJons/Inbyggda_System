#ifndef LED_H // Start av header guard för att undvika dubbelinkludering av header-filer
#define LED_H // Definierar konstanten LED_H för att användas av header guard
 
#include <stdint.h> //Inkluderar standardbiblioteket som innehåller definitioner av typer med specifik storlek
#include "uart.h" //Inkluderar header-filen för UART-modulen
#include "stm32f4xx.h" //Inkluderar enhetsspecifika angivelser om hårdvaran för STM32F4


#define LED_PORT GPIOB //Definierar en konstant som pekar på GPIOB-porten som ansvarig för LED-funktionen


#define LED_PORT_CLOCK (1U<<1) //Definierar klocksignalen för porten på bitplats 1


#define LED_RED_PIN (1U<<14) //Definierar pin för röd LED på bitplats 14
#define LED_GREEN_PIN (1U<<12) //Definierar pin för grön LED på bitplats 12
#define LED_BLUE_PIN (1U<<15) //Definierar pin för blå LED på bitplats 15
#define LED_YELLOW_PIN (1U<<13) //Definierar pin för gul LED på bitplats 13


#define LED_RED_MODE_BIT (1U<<28) //Definierar mode bits för röd LED på bitplats 28 
#define LED_GREEN_MODE_BIT (1U<<24) //Definierar mode bits för grön LED på bitplats 24
#define LED_YELLOW_MODE_BIT (1U<<26) //Definierar mode bits för gul LED på bitplats 26
#define LED_BLUE_MODE_BIT (1U<<30) //Definierar mode bits för blå LED på bitplats 30

//Definierar en enum-typ som representerar de olika LED-färgerna
typedef enum {
  RED = 0,
  GREEN,
  YELLOW,
  BLUE
}LedColor_Type;

//Definierar en enum-typ som representerar de olika lägena som en LED kan ha, 0 eller 1
typedef enum {
  OFF = 0,
  ON = 1
}LedState_Type;

// Definierar en klass som representerar en LED med attributen color och state samt med funktionerna setState och getState
class Led{

  private:
      LedColor_Type color;
      LedState_Type state;

  public:

      Led(LedColor_Type _color,LedState_Type _state);
      void setState(LedState_Type _state);
      LedState_Type getState() const;

};

#endif // Slut på header guard
