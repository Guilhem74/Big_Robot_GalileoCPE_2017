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
DESACTIVER_FUNNY_ACTION();
  Setup_Actionneur();

  setup_asservissement();
  Setup_Commande();

  Pince_CLOSE();
Pince_UP();
  Quart=1;
  delay(1000);
}

void loop() {
  if( Robot_Principal==Prechauff)
    {//Tirette attaché
        Mise_A_Jour_Tirette();

        Temp_debut_match=millis();
    }
    else
    {

      if( millis()-Temp_debut_match > TEMPS_MATCH)
      {//Fin du match
        Robot_Principal=Fin;
        Serial.println("Fin du match");
        ACTIVER_FUNNY_ACTION();

        Arreter_Robot();
        while(1);
      }
      else
      {//routine du robot
        Routine_Robot();

      }
      
    }


}


/*sif(Etat_bras==1&&Etat_bras_voulu!=0)
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
 Pince_DOWN();
 delay(500);
 Quart++;
 while( Chargeur_Pret==false)
 {
   Mise_a_jour_bras();
 }
 Pince_WAIT();
 delay(1000);

 delay(500);
 digitalWrite(45, LOW);
 Etat_bras_voulu=1;
}*/
