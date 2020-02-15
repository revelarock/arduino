#include <Ultrasonic.h>


#include <AFMotor.h>

#include <Servo.h>
Servo myservo;
int pos = 90;  //posição inicial do servo "original 90"
int echopin = 9; // a saido echo do SRF05 liga no pin 9
int trigerpin = 8; // a saida triger do SRFo5 liga no pin 8
int in1 = 2; // pino 1 do motor 1
int in2 = 3; // pino 2 do motor 1
int in3 = 4; // pino 1 do motor 2
int in4 = 7; // pinto 2 do motor 2
int enable1 = 5; // define a velociadade do motor 1
int enable2 = 6; // define a velocidade do motor 2
unsigned long pulsetime = 0; // Variavel que faz a leitura do pulso
unsigned long distancia = 0; //Variavel que que armazena a distancia
void stopMotor() {
  //para os motores
  analogWrite(enable1, 0);
  analogWrite(enable2, 0); 
}
void setup()
{
  myservo.attach(10); // anexa o servo lógico ao fisico no pino 10
  pinMode(enable1, OUTPUT); // define todos os pinos como saída
  pinMode(enable2, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(trigerpin, OUTPUT); // define o pino triger como saída
  pinMode(echopin, INPUT); // define o pino echo como entrada
}
void loop()
{
  digitalWrite(trigerpin, HIGH);
  delayMicroseconds(50);
  digitalWrite(trigerpin,LOW);
  pulsetime = pulseIn(echopin, HIGH);
  distancia = pulsetime/58; // converte para cm
  if (distancia > 16) // se a distancia for maior que 16 cm
  {
    analogWrite(enable1, 255); // velocidade do motor 1
    analogWrite(enable2, 255); // velocidade do motor 2
    digitalWrite(in1, LOW); // apenas pinos secundarios em HiGH, definindo o movimento para frente
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);

  }
  if (distancia <= 15) // se a distancia for menor ou igual a 15
  {
    stopMotor();  //para o motor por 1 segundo
    delay(1000);
  }
  for (pos = 90; pos < 180; pos += 5) // para posição 90 girar o servo em pulsos de 5 graus até 175
  {
    myservo.write(pos);
    delay(150);

    if (distancia > 16) // se a distancia for maior que 16 cm
    {
      analogWrite(enable1, 255);
      analogWrite(enable2, 0); // gira para esquerda
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
    }  
  }
  if (distancia <= 15) // se a distancia for menor ou igual que 15 cm
  {
    for (pos = 180; pos >= 1; pos -= 5) // girar o servo para o outro lado, no mesmo ritmo 
    {
      myservo.write(pos);
      delay(150);

      if (distancia > 16) // se a distancia for maior que 16 cm
      {
          analogWrite(enable1, 0); // girar a direta
        analogWrite(enable2, 255);
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
      }
    }
  }
  if (distancia > 16); // se a distancia for maior que 16
  {
    myservo.write(pos);  // servo volta a posição inicial e anda para frente
     analogWrite(enable1, 255);
        analogWrite(enable2, 255);
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
  }
}

 
