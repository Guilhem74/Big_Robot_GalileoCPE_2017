#include <Arduino.h>

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

char Info[40] = {};

void setup() {

   Setup_Actionneur();
  setup_asservissement();
  delay(1000);
//Tourner_Moteur_G();
  // Droit_Au_But();
}

void loop() {

  Where_Is_Robot();
Mise_a_jour_bras();
/*if(Etat_bras==1&&Etat_bras_voulu!=0)
{
  Pince_CLOSE();
  delay(1500);
  Etat_bras_voulu=0;
}
else if (Etat_bras==0&&Etat_bras_voulu!=1)
{
  Pince_UP();
  delay(1000);
  Pince_OPEN();
  delay(500);
  Pince_WAIT();
  delay(1000);
  Pince_DOWN();
  delay(500);
  digitalWrite(45, LOW);
  Etat_bras_voulu=1;
}*/
  if ((millis() - Temps_assert) > TEMPS_MIN_ASSERT) {
    mise_a_jour_robot();
    calcul_erreur();
    Temps_assert = millis();
    asservissement_robot(Distance_moyenne, erreur_angle_radian);
  }

  Reception();
}

void serialEvent() {
  while (Serial.available()) {
    // récupérer le prochain octet (byte ou char) et l'enlever du buffer
    char inChar = (char)Serial.read();

    if (inChar == '\n') { // caractère de fin pour notre chaine
      stringComplete = true;
    } else { // concaténation des octets reçus
      inputString += inChar;
    }
  }
}
