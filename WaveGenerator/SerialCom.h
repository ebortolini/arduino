#ifndef SERIAL_COMM
#define SERIAL_COMM
#include <arduino.h>


class SerialCom
{
  public:
    void Init(int speed);
    void PrintlnInt(int value);
    bool ReadData(char * c);
    template <typename T>
    void println(T t){Serial.println(t);}

    template <typename T>
    void print(T t){Serial.print(t);}

    bool ReadASCIIData(char * c);
  private:
    char ToChar(int value);
};
#endif
