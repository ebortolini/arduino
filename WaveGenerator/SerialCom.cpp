#include "SerialCom.h"



void SerialCom::Init(int speed){
  Serial.begin(speed);
}


void SerialCom::PrintlnInt(int value){
  Serial.println(value);
}

bool SerialCom::ReadData(char * c){
  if(!Serial.available())
    return false;
  *c = Serial.read() - 0x30;
  return true;
}

bool SerialCom::ReadASCIIData(char * c){
  if(!Serial.available())
    return false;
  *c = Serial.read();
  return true;
}

char SerialCom::ToChar(int value){
  return value + 0x30;
}

