#include <Sim800L.h>
#include <SoftwareSerial.h>  

#define comandoAT;

void iniciar(){
       comandoAT("AT","OK",3000); // Comprueba que el modulo SIM800L esta arrancado
       Serial.println("Conectando a la red...");
       delay(3000);
       while(!comandoAT("AT+CREG?","+CREG: 0,1",1000)); //Espera hasta estar conectado a la red movil
       Serial.println("Conectado a la red.");
       comandoAT("AT+CGATT=1", "OK", 1000); //Iniciamos la conexión GPRS
       comandoAT("AT+CSTT=\"claro.com.br\",\"claro\",\"claro\"", "OK", 3000); //Definimos el APN, usuario y clave a utilizar
       comandoAT("AT+CIICR", "OK", 3000); //Activamos el perfil de datos inalámbrico
       comandoAT("AT+CIFSR", "", 3000); //Obtenemos nuestra IP
  }

  void peticion(){
      char aux_str[50];
      char direccion[] = "GET /asciilogo.txt HTTP/1.1\r\nHost: arduino.cc\r\nConnection: close\r\n\r\n";
      if(comandoAT("AT+CREG?","+CREG: 0,1",1000)){ //Comprueba la conexion a la red
          comandoAT("AT+CIPSTART=\"TCP\",\"arduino.cc\",\"80\"","CONNECT OK",5000); //Inicia una conexión TCP
          // Envíamos datos a través del TCP
          sprintf(aux_str, "AT+CIPSEND=%d", strlen(direccion));
          if (comandoAT(aux_str,">",10000))
          {
            comandoAT(direccion, "OK", 10000);
          }
      }else{
          Serial.print("Reiniciando...");
          iniciar();
      }
  }
