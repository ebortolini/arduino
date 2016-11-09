#ifndef SWATOOTH_WAVE
#define SWATOOTH_WAVE

#include "IFunctionGenerator.h"
#include <Arduino.h>

class Sawtooth : public IFunctionGenerator{
  public:
    int delayTime;
    void Init(void * data){
      return;
    }

    void Generate(){
      int value = 0;
  
      while(value <= 255){
        *port_register_data = value+=5;
        delay(1);
      }
      
      *port_register_data = 0;
    }
};

#endif
