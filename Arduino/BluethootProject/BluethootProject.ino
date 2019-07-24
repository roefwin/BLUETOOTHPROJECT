
#include <SigFox.h>
#include <ArduinoLowPower.h>
char c ;
String message;
int LED = 6; // the on-board LED
int Data;
 
  
void setup() {
  // put your setup code here, to run once:
  Serial1.begin(9600);//maitre
  Serial.begin(9600);//arduino port
  pinMode(LED,OUTPUT);


}

void loop() {
  readSerialPort();

  
  if (message != "")
  { 
  Serial.print("Maître à envoyé :");
    Serial.print(message);
    Serial1.print(message);
    message = "";
  }
  }

  void readSerialPort(){
    while(Serial1.available()){
      delay(10);
     
      if(Serial1.available() > 0){
        Data = Serial1.read();
        if(Data =='1'){
          digitalWrite(LED,1);
          Serial1.print("LED On");
          Serial.print("LED On");
       } 
       else if(Data == '0'){
        digitalWrite(LED,0);
          Serial1.print("LED Of");
          Serial.print("LED Of");
       }else{
        while(Serial1.available()){
          c = Serial1.read();

        message += c ;
        delay(10);
       }
      
       }
       }
        Serial1.flush();
      }
      
    }
    
