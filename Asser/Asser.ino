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
 //Droit_Au_But();
}



void loop() {

// Where_Is_Robot();
 //Are_U_Wrong();
 //Calcul erreur
 //A_consigne= 
 if((millis()-Temps_assert )>TEMPS_MIN_ASSERT)
{
   mise_a_jour_robot();
calcul_erreur();
Temps_assert=millis();
 asservissement_robot(Distance_moyenne,erreur_angle_radian);
}

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

