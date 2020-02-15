byte ledPinos[]= {13,12,11,10,9,8,7,6,5,4};
void setup() {
  // put your setup code here, to run once:

  //fazendo com laço de repetições e veto 

  for (int pino=0;pino <=9; pino++)
    pinMode(ledPinos[pino],OUTPUT);
    
    for (int pino=0;pino<=9;pino++)
      
      {
        digitalWrite(ledPinos[pino],HIGH); //Ascende a luz
        delay(500);
      }
      

    for (int pino=0;pino <=9;pino++)
     
      
      {digitalWrite(ledPinos[pino],LOW);
      delay(500);
      }
}

void loop() {
  // put your main code here, to run repeatedly:
  
  for (int pino=0;pino <=9; pino++)
    pinMode(ledPinos[pino],OUTPUT);
    
    for (int pino=0;pino<=9;pino++)
      
      {
        digitalWrite(ledPinos[pino],HIGH); //Ascende a luz
        delay(500);
      }
      

    for (int pino=0;pino <=9;pino++)
     
      
      {digitalWrite(ledPinos[pino],LOW);
      delay(500);
      }


}
