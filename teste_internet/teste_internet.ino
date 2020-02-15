#include <SoftwareSerial.h>

#define TX_PIN 11
#define RX_PIN 10
#define TIMEOUT 5000

SoftwareSerial softSerial(TX_PIN, RX_PIN);

int timeout(long _delay){
 int flag = 0;//marca se o modulo respondeu antes do timeout Acabar
 _delay = _delay/50;
  for(int i = 0; i<50; font= "" i="">
  if(!softSerial.available())delay(_delay)
  else flag = 1;
  Serial.print('.');
 }
 Serial.print('\n');
 return flag;
}

void sendAtCmd(char* str){
  int i = 0;
 softSerial.println(str);

 //aguarda a resposta do modulo
 while (!softSerial.available()){
    delay(500);
    i++;
    if(i>=TIMEOUT/500){
      Serial.print(str);
      Serial.println(" REACHED TIMEOUT!");
      break;
    }
 }

 Serial.print(">>");
 while (softSerial.available()){
    Serial.write(softSerial.read());
 }
}

void initSim800(){
  Serial.println("Sim800L Auto Test Running...");
  sendAtCmd("AT+SAPBR=3,1,\"Contype\",\"GPRS\"");
  sendAtCmd("AT+SAPBR=3,1,\"APN\",\"claro.com.br\"");
  sendAtCmd("AT+SAPBR=1,1");
  timeout(2000);
  sendAtCmd("AT+SAPBR=2,1");
  timeout(2000);
  sendAtCmd("AT+HTTPINIT");
  sendAtCmd("AT+HTTPPARA=\"CID\",1");
  sendAtCmd("AT+HTTPPARA=\"URL\",\"http://date.jsontest.com\"");
  sendAtCmd("AT+HTTPACTION=0");
  timeout(15000);
  sendAtCmd("AT+HTTPREAD");
  timeout(2000);
  Serial.println("Sim800L Auto Test Done!");
}

void setup(){
  //Terminal para debug
  Serial.begin(9600);
  while (!Serial);

  //Comunicacao com o SIM800L
  softSerial.begin(4800);
  delay(1000);

  Serial.println("Debugging SIM800L!");
}

void loop(){
  //Print dos dados recebidos pelo modulo
  if (softSerial.available()){
    Serial.write(softSerial.read());
  }

  //Envio de comandos AT para o modulo
  if (Serial.available()){
    char ch = Serial.read();
    if(ch == '*'){
        initSim800();
    }
    else softSerial.write(ch);
  }
}
