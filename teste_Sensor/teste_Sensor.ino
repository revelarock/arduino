#include <UbidotsArduinoGPRS.h>
#include <SoftwareSerial.h> 

//Serial Relay - Arduino will patch a 
//serial link between the computer and the GPRS Shield
//at 19200 bps 8-N-1
//Computer is connected to Hardware UART
//GPRS Shield is connected to the Software UART 
#define APN "claro.com.br" // Assign the APN 
#define USER "claro"  // If your apn doesnt have username just put ""
#define PASS "claro"  // If your apn doesnt have password just put ""
#define TOKEN "A1E-u1caxq0fjhE6e7evKVgGechNmiio7i"  // Replace it with your Ubidots token
#define VARIABLE_LABEL "Normal" // Assign the variable label 

Ubidots client(TOKEN);
SoftwareSerial gprs = SoftwareSerial(7, 8);
SoftwareSerial *GPRSSerial = &gprs;

void setup() {
  Serial.begin(115200);
  GPRSSerial->begin(19200);
  if (! client.init(*GPRSSerial)) {
    Serial.println(F("Couldn't find FONA"));
    while (1);
  }
  client.setApn(APN,USER,PASS);
  //client.setDebug(false);
}

void loop() {
  float value = analogRead(A0);  // Reading analog pin A0
  client.add(VARIABLE_LABEL, value);  
  client.sendAll();
}
