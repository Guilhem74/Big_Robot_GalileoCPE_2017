#include "define.h"


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
}

