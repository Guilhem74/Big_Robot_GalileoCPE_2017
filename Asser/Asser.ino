#include "define.h"
/*Fonction de test*/
/*
void Tourner_Moteur_D()
void Droit_Au_But()
void Je_Paye_Ma_Tournee()
void Tourner_Moteur_G()
void Plz_Share_What_U_Know_About_Encoder()
void Where_Is_Robot()
*/

char Info[40]={};

void setup() {
setup_asservissement();
delay(1000);
 
}



void loop() {
 mise_a_jour_robot();
 Where_Is_Robot();
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

