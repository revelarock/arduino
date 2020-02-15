
#include <GSM.h>

GSM gsmAccess(true); 

void setup (){
  
  Serial.begin(9600);
  Serial.println("Testing GSM Shield Orange Switzerland");
  connectToGSMNetwork();
}

void loop(){
  
}  

void connectToGSMNetwork(){

  unsigned long myTimeout = 30000; // YOUR LIMIT IN MILLISECONDS 
  boolean notConnected = true;
  unsigned long timeConnect = millis();

  Serial.println("Trying to connect...");
  theGSM3ShieldV1ModemCore.println("AT");
  gsmAccess.begin("2290",true,false); //Use async mode and requires that GSM debug mode has been set on GSM object creation
  while(notConnected) 
  {
    int ok = 0;
    gsmAccess.ready(); //Call this if debugging is on. Otherwise we will never reach GSM_READY...?!?
    delay(1000); //might not call ready too often.??? See GSM3ShieldV1AccessProvider.cpp, GSM3ShieldV1AccessProvider::begin
    ok = gsmAccess.getStatus();
    if (ok != GSM_READY){
      Serial.print(F("GSM status: "));
      Serial.println(ok);
    } else {
      notConnected = false;
    }
  }
  
  if(notConnected)
    Serial.println("Error in connection");
  else
    Serial.println("Connected to GSM network");
}
