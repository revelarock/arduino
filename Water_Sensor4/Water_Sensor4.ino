#include <SoftwareSerial.h>

SoftwareSerial mySerial(11, 10); // Declaramos os pinos RX(11) y TX(10) que vamos a usar

const int waterSens = A0; //define water sensor
const int led = 9;//define led to pin 9
int waterVal; //define the water sensor value
int Buzzer = 8;
int tones[] = {261, 277, 293, 311, 329, 349, 369, 392, 415, 440, 466, 493, 523 , 554};

void setup() {
  pinMode(led, OUTPUT); //set led as an output
  pinMode(waterSens, INPUT);//set water sensor as an input
  Serial.begin(9600);  //start the serial port at 9600 bauds
  pinMode (Buzzer, OUTPUT);
  //Begin serial comunication with Arduino and Arduino IDE (Serial Monitor)
  while (!Serial);
 mySerial.begin(9600);     // Iniciamos uma segunda comunicação serie
  delay(1000);              // Pausa de 1 segundo
}
void loop(){
 
 waterVal = analogRead(waterSens); //read the water sensor

 Serial.println(waterVal); //print the value of the water sensor to the serial monitor

  if (waterVal >= 12) {

    digitalWrite(led, HIGH);//if the water sensor senses water turn the led on
    digitalWrite(Buzzer, HIGH);
    tone(Buzzer, tones[6]);
    delay(200);
    digitalWrite(led, LOW);
    digitalWrite(Buzzer, LOW);
    noTone(Buzzer);
    delay(200);
    digitalWrite(led, HIGH);
    digitalWrite(Buzzer, HIGH);
    tone(Buzzer, tones[16]);
    delay(200);
    digitalWrite(led, LOW);
    digitalWrite(Buzzer, LOW);
    noTone(Buzzer);
    delay(200);
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
    delay(9000);
    
    Serial.println ("AT+CMGF=1");
    delay(500);
    Serial.print("AT+CMGS=");
    Serial.write(byte(34));
    Serial.print("11982058535");
    Serial.write(byte(34));
    Serial.println();
    delay(500);
    Serial.print("Risco Enchente");
    Serial.write(byte(26));
    delay(9000);
   
    }
    else {
      digitalWrite(led, LOW);//if it doesn't sense anything turn the led off
      digitalWrite(Buzzer, LOW);
      noTone(Buzzer);
    }
  }
