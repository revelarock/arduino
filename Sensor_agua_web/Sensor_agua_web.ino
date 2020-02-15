#include <SoftwareSerial.h>
#include <String.h>
 
SoftwareSerial mySerial(RX, TX);                                                // Your pins to the GPRS shield
 
 
int value; 

String token = "A1E-u1caxq0fjhE6e7evKVgGechNmiio7i";// Your Ubidots token
String idvariable = "5c32804bc03f970e98e332ef";                               // Your variable_ID
void setup()
{
  
  mySerial.begin(19200);               
  Serial.begin(19200);   
  delay(10000);
}
 
void loop()
{
  
  
 int value = analogRead(A0);
 save_value();      
 if (mySerial.available())
   Serial.write(mySerial.read());
}
 

// This function will send the A0 sensor data to Ubidots, you can see the new value after executing this function

void save_value()
{
  int num;
  String le;
  String var;
  var="{\"value\":"+ String(value) + "}";
  num=var.length();
  le=String(num);
  
  
  mySerial.println("AT+CGATT?");
  delay(2000);
 
  ShowSerialData();
  mySerial.println("AT+CGATT?");
  delay(2000);
 
  ShowSerialData();
  mySerial.println("AT+CGATT?");
  delay(2000);
 
  ShowSerialData();
  mySerial.println("AT+CGATT?");
  delay(2000);
 
  ShowSerialData();
  mySerial.println("AT+CGATT?");
  delay(2000);
 
  ShowSerialData();
  mySerial.println("AT+CGATT?");
  delay(2000);
 
  ShowSerialData();
 
  mySerial.println("AT+CSTT=\"claro.com.br\"");      // Replace with your APN
  delay(1000);
 
  ShowSerialData();
 
  mySerial.println("AT+CIICR");                        // Bring up the wireless connection
  delay(3000);
 
  ShowSerialData();
 
  mySerial.println("AT+CIFSR");                        // Get IP adress
  delay(2000);
 
  ShowSerialData();
 
  mySerial.println("AT+CIPSPRT=0");
  delay(3000);
 
  ShowSerialData();
 
  mySerial.println("AT+CIPSTART=\"tcp\",\"things.ubidots.com\",\"80\"");    // Start the connection to Ubidots
  delay(3000);
 
  ShowSerialData();
 
  mySerial.println("AT+CIPSEND");                      // Start to send data to remote server
  delay(3000);
  ShowSerialData();
  mySerial.print("POST /api/v1.6/variables/"+idvariable);
  delay(100);
  ShowSerialData();
  mySerial.println("/values HTTP/1.1");
  delay(100);
  ShowSerialData();
  mySerial.println("Content-Type: application/json");
  delay(100);
  ShowSerialData();
  mySerial.println("Content-Length: "+le);
  delay(100);
  ShowSerialData();
  mySerial.print("X-Auth-Token: ");
  delay(100);
  ShowSerialData();
  mySerial.println(token);
  delay(100);
  ShowSerialData();
  mySerial.println("Host: things.ubidots.com");
  delay(100);
  ShowSerialData();
  mySerial.println();
  delay(100);
  ShowSerialData();
  mySerial.println(var);
  delay(100);
  ShowSerialData();
  mySerial.println();
  delay(100);
  ShowSerialData();
  mySerial.println((char)26);                            // Sending the HTTP request
  delay(7000);                                           // Waiting for a reply. Important! tweak this time depending on the latency of your mobile Internet connection
  mySerial.println();
 
  ShowSerialData();
 
  mySerial.println("AT+CIPCLOSE");                      // Close the connection
  delay(1000);
  ShowSerialData();
}

// This function is to show the response in your serial terminal

void ShowSerialData()
{
  while(mySerial.available()!=0)
  
    Serial.write(mySerial.read());
    
}
