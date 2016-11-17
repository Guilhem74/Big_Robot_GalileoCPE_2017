#include "define.h"

char Info[40]={};

void setup() {
setup_asservissement();
  
//  while(!Serial.available());
//  Serial.print("X:");
    delay(1000);
}



void loop() {
 mise_a_jour_robot();
 //Calcul erreur
 //A_consigne= 
 asservissement_robot(((TICCODEUSES)/(PI*DIAMETRE_ROUE))*Distance_moyenne,ANGLE_DEST);
 Reception();
  
}

void serialEvent() {
  while (Serial.available()) {
    // récupérer le prochain octet (byte ou char) et l'enlever du buffer
    char inChar = (char)Serial.read();
    
    if (inChar == '\n') {// caractère de fin pour notre chaine
      stringComplete = true;
    }
    else
    { // concaténation des octets reçus
      inputString += inChar;}
     }
 }

