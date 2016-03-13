#include <Arduino.h>
#include "Display.h"
#define MAX 9
#define MIN 0
/*
 * dr -> Data register 
 * dd -> data direction register
 */
Display::Display(uint8_t *dr, uint8_t * dd){
  port_register = dr;
  direction_register = dd;

  *dd = 0b11111111;
}


void Display::write_digit(uint8_t digit){
  if(digit > MAX || digit < MIN)
    return;
   *port_register = display_values[digit];
}

