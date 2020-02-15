// Hardware: Arduino UNO

int sensor_input=7;
int led = 13;
int val= analogRead(0);
float cm = (val*4.0) /600.0;
int X=abs(cm);
analogWrite(LED,map(x,0,4,0,255);
Serial.println(cm);

BT.println(cm);
delay(100);

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(sensor_input,INPUT);
pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

 if(digitalRead(sensor_input)--HIGH){
     digitalWrite(led,HIGH);
     Serial.println("Fluxo da  Água em ");
     
  }
else  if(digitalRead(sensor_input)--LOW
     digitalWrite(led,LOW);
     Serial.println("Fluxo de Água Normal");
}

}
