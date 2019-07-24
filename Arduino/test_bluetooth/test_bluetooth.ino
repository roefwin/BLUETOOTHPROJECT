#include <SigFox.h>
#include <ArduinoLowPower.h>



String msg = "poulet braisé";
char c ;
String id; 


void setup() {
  
  
// mettre ici le code qui sera répété qu'une fois:
Serial.begin(9600);
Serial1.begin(9600);// Permet d'initialiser le moniteur série à 9600 bauds
 while (!Serial) {};

  // Uncomment this line and comment begin() if you are working with a custom board
  //if (!SigFox.begin(SPI1, 30, 31, 33, 28, LED_BUILTIN)) {
  if (!SigFox.begin()) {
    
    return;
  }
  // Enable debug led and disable automatic deep sleep
  // Comment this line when shipping your project :)
  SigFox.debug();

 

  // Display module informations
 

  delay(100);

  String message1;
  
  id = SigFox.ID();
   //PAC = SigFox.PAC();
   
  // Send the module to the deepest sleep
  SigFox.end();
//Serial.print("Hello les makers "); //Permet d'afficher Hello les makers sur le moniteur série 

Serial1.print("ID : " + id); //Permet d'afficher Hello les makers sur le moniteur série 



}

void loop() {
// mettre ici le code qui sera répété en boucle:
if (Serial.available())
{        c = Serial.read();
          msg +=c;
          delay(100); 
      //Si un message a été reçu  faire ceci
      Serial.println(msg);
      Serial1.println(msg);  // Lit le message reçu et l'affiche sur le moniteur

      if(c == 'a'){
         id = Serial.write("GGHGYTYJH");
         Serial.print(id);  
        }
     
      
}
else
{
 // Si rien n'est reçu faire cela
}
}
