#ifndef SQUARE_WAVE_GENERATOR
#define SQUARE_WAVE_GENERATOR

#include <Arduino.h>
#include "IFunctionGenerator.h"

class SquareWaveGenerator : public IFunctionGenerator{
  public:
    int delayTime;
    void Init(void * data){
      delayTime = *((int *)data);
    }

    void Generate(){
      *port_register_data = 255;
      delay(delayTime);
      *port_register_data = 0;
      delay(delayTime);
    }
};

#endif
