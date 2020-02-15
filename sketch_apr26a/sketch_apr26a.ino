int ledPin = 9;
int ledPin1 = 10;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin,OUTPUT);
  pinMode (ledPin1,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(ledPin,HIGH);
  delay(10); //acende
  digitalWrite(ledPin,LOW);
  delay(30); //apaga
  digitalWrite(ledPin1,HIGH);
  delay(1000); //acende
  digitalWrite(ledPin1,LOW);
  delay(1000); //apaga
  

}
