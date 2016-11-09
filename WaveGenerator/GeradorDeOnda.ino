#include "IFunctionGenerator.h"
#include "SerialCom.h"
#include "SquareWaveGenerator.h"
#include "Sawtooth.h"
#include "TriangleWave.h"
#include "SineWave.h"

#define TYPEWAVES 4
SerialCom * serialCom;
IFunctionGenerator * generators[TYPEWAVES];
IFunctionGenerator * curretGenerator;

void setup() {
    serialCom = new SerialCom();
    serialCom->Init(20000);
   //instantiate specific types
    generators[0] = new SquareWaveGenerator();
    generators[1] = new Sawtooth();
    generators[2] = new TriangleWave();
    generators[3] = new SineWave();

    //set output port to write
    for(int i = 0; i < TYPEWAVES; i++)
      generators[i]->SetPort((uint8_t *)&DDRB, (uint8_t *)&PORTB);

  //Set Square wave generator
    int timeToWait = 500;
      generators[0]->Init((void *)&timeToWait);

    int frequency = 10;
    generators[3]->Init((void*)&frequency);

     printMenu();
     curretGenerator = generators[0];
}
char  data;
void loop() {
  
  if (serialCom->ReadData(&data)){
    curretGenerator = generators[data < TYPEWAVES ? data : 0 ];
    //serialCom->print<int>(data);
    printOption(data);
    delay(100);
    printMenu();
  }
  curretGenerator->Generate();

}

void printMenu(){
  serialCom->println<String>("Escolha um gerador: ");
  serialCom->println<String>("0 - Onda quadrada, ");
  serialCom->println<String>("1 - Onda Dente de serra, ");
  serialCom->println<String>("2 - Onda triangular; ");
  serialCom->println<String>("3 - Onda senoidal; ");
  serialCom->print<String>(": ");
}

void printOption(int op){
  switch(op){
    case 0: serialCom->println<String>("Você escolheu, onda quadrada");
      break;
    case 1: serialCom->println<String>("Você escolheu, onda dente de serra");
      break;
    case 2: serialCom->println<String>("Você escolheu, onda triangular");
      break;
    case 3: serialCom->println<String>("Você escolheu, onda senoidal");
      break;
  }
}
