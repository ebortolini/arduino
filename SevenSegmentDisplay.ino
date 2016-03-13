#include<Arduino.h>
#include "Display.h"

Display display_7((uint8_t *)&PORTB, (uint8_t *)&DDRB);
uint8_t value = 0;

void setup() {
}

void loop() {
  display_7.write_digit(value);
  value = value >= 9 ? 0 : value +1;
  delay(500);
  
}
