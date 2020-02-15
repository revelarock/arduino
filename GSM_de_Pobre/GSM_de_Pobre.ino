void setup() {
  Serial.begin (9600);
}

void loop() {

 delay(500);
 Serial.println ("AT+CMGF=1");
 delay(500);
 Serial.print("AT+CMGS=");
 Serial.write(byte(34));
 Serial.print("11985815730");
 Serial.write(byte(34));
 Serial.println();
 delay(500);
 Serial.print("Risco Enchente");
 Serial.write(byte(26));
 while(1);

}
