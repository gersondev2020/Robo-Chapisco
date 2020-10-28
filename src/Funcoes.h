#define DI_STEP 13
#define DI_DIR 10
#define DI_ARAME_1 11
#define DI_ARAME_2 12
int contaFio = 0;

void hold(const unsigned int &ms) {
  unsigned long m = millis();
  while (millis() - m < ms) {
    yield();
  }
}

int DRIVER(int STEP, int SPEED, boolean DIR){
  int pulses = 0;
  digitalWrite(DI_DIR, DIR); 
  for(int i = 0; i < STEP; i++){
  digitalWrite(DI_STEP, HIGH);   
  hold(SPEED);            
  digitalWrite(DI_STEP, LOW);    
  hold(SPEED); 
  }   
  return pulses;
}

boolean chapisco(
  int qtdFio,                                 // quantidade de fio de solda 
  int larguraFio,                             // largura de fio de solda 
  int RPM,                                    // Rotação da moenda 
  int pontoInicial                            // Pinto para inicio do chapisco
  ){
  if(contaFio <= qtdFio){
    float tempGiro = (60/RPM)*1000;             // Calcula o tempo de cada vouta da moenda
    digitalWrite(DI_ARAME_1, HIGH);             // Liga alimentador de arame 1
    digitalWrite(DI_ARAME_2, HIGH);             // Liga alimentador de arame 2
    hold(tempGiro);                             // Espera a um giro da moenda
    DRIVER(larguraFio,1,true);               // Roda o driver direção reversa
  }else{
    digitalWrite(DI_ARAME_1, LOW);             // Desliga alimentador de arame 1
    digitalWrite(DI_ARAME_2, LOW);             // Desliga alimentador de arame 2
    return true;                               // Retorna Chapisco concruido
  }
  contaFio++;
}