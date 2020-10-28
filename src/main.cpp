#include <Arduino.h>
#include "Funcoes.h"
void setup() {
  pinMode(DI_STEP, OUTPUT);
  pinMode(DI_DIR, OUTPUT);
  pinMode(DI_ARAME_1, OUTPUT);
  pinMode(DI_ARAME_2, OUTPUT);
}

void loop() { 
  if(chapisco(10,300,6,1)){
     hold(5000);
     contaFio=0;
  }
      
}