// Acende e apaga LED com interrruprot

int ledPin=13;
int botaoLigar=8;
int ligado = 0; //armazena estado pino de entrada

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin,OUTPUT);
  pinMode (botaoLigar,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
ligado = digitalRead (botaoLigar);

//verificar se o notao esta pressionado

if (ligado==HIGH)
  digitalWrite(ledPin,HIGH);

  else
    digitalWrite(ledPin,LOW);

}
