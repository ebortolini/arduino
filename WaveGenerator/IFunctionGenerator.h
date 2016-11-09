#ifndef IFUNCTION_GENERATOR
#define IFUNCTION_GENERATOR
#include <Arduino.h>
class IFunctionGenerator{
  public:
    uint8_t * port_register_data;
    uint8_t * direction_register_data;
    void SetPort(uint8_t * dir, uint8_t * data){
      port_register_data = data;
      direction_register_data = dir;
      *direction_register_data = 255;
    }
    virtual void Init(void * data);
    virtual void Generate();
    
};

#endif

