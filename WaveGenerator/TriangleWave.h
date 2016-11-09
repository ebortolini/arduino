#ifndef TRIANGLE_WAVE
#define TRIANGLE_WAVE

#include "IFunctionGenerator.h"
#include <Arduino.h>
class TriangleWave : public IFunctionGenerator{
  void Init(void * data){
      return;
  }

  void Generate(){
    int value = 0;
  
      while(value <= 250){
        *port_register_data = value+=5;
        delay(1);
      }
      value = 255;
      while(value >=5){
        *port_register_data = value-=5;
        delay(1);
      }
      
      //*port_register_data = 0;
  }
};

#endif

