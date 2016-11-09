#ifndef SINE_WAVE
#define SINE_WAVE
#define s 500
#include "IFunctionGenerator.h"
#include <Arduino.h>
class SineWave : public IFunctionGenerator{
  public:
    
    short buffer[s];;
    void Init(void * data){
      int sampleRate = s;
  
      double amplitude = 120;
      int frequency = *((int*)data);
      for (int n = 0; n < s; n++)
      {
          buffer[n] = (short)(amplitude * (sin((2 * PI * n * frequency) / sampleRate) +1));
      }
    }

    void Generate(){
      for (int i = 0; i < s; i++){
      *port_register_data = buffer[i];
      delay(2);
      }
    }
};

#endif
