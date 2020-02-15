/*int ledPin = 13;
int ledPin1 = 12;
int ledPin2= 11;
int ledPin3 = 10;
int ledPin4 = 9;
int ledPin5 = 8;
int ledPin6 = 7;
int ledPin7 = 6;
int ledPin8 = 5;
*/


void setup() {
  // put your setup code here, to run once:
 /* pinMode(ledPin,OUTPUT);
  pinMode (ledPin1,OUTPUT);
  pinMode (ledPin2,OUTPUT);
  pinMode (ledPin3,OUTPUT);
  pinMode (ledPin4,OUTPUT);
  pinMode (ledPin5,OUTPUT);
  pinMode (ledPin6,OUTPUT);
  pinMode (ledPin7,OUTPUT);
  pinMode (ledPin8,OUTPUT);
  */
 for(int pino=13;pino >=1;pino=pino-2)
  pinMode(pino,OUTPUT);
 for(int pino=13;pino >=1;pino=pino-2)
  digitalWrite (pino,HIGH); //Acende a luz Envia Corrente
  delay(5000);

  for (int pino=13;pino >=1;pino=pino-2)
  digitalWrite (pino,LOW); //Apaga a Luz
  delay(5000); 
}

void loop() {
  // put your main code here, to run repeatedly:

  /*digitalWrite(ledPin,HIGH);
  delay(10); //acende
  digitalWrite(ledPin,LOW);
  delay(30); //apaga

    digitalWrite(ledPin1,HIGH);
  delay(20); //acende
  digitalWrite(ledPin1,LOW);
  delay(40); //apaga

    
digitalWrite(ledPin2,HIGH);
  delay(30); //acende
  digitalWrite(ledPin2,LOW);
  delay(50); //apaga

  digitalWrite(ledPin3,HIGH);
  delay(40); //acende
  digitalWrite(ledPin3,LOW);
  delay(60); //apaga

  digitalWrite(ledPin4,HIGH);
  delay(50); //acende
  digitalWrite(ledPin4,LOW);
  delay(70); //apaga

  digitalWrite(ledPin5,HIGH);
  delay(60); //acende
  digitalWrite(ledPin5,LOW);
  delay(80); //apaga

  digitalWrite(ledPin6,HIGH);
  delay(70); //acende
  digitalWrite(ledPin6,LOW);
  delay(90); //apaga

  digitalWrite(ledPin7,HIGH);
  delay(80); //acende
  digitalWrite(ledPin7,LOW);
  delay(100); //apaga
*/
}
