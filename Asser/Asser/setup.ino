#include <Arduino.h>

#include "define.h"

void Setup_Commande()
{
  /*
  Consigne[0].X_DEST=400;
  Consigne[0].Y_DEST=1070;
  Consigne[0].ANGLE_FINAL=90;
  Consigne[0].Derniere_Consigne=true;
  Consigne[0].consigne_suivante=&Consigne[0];*/
  Consigne_Actuel=&Consigne1;
  int32_t dx=Consigne_Actuel->X_DEST-X_POS;
  int32_t dy=Consigne_Actuel->Y_DEST-Y_POS;
  DELTA_Consigne_Init=Consigne1.ANGLE_FINAL;//sqrt(dx*dx+dy*dy);


}
void setup_asservissement()
{
   Serial.begin(115200);
  Serial3.begin(115200);
  Serial3.print("R\n");

 pinMode(PIN_MOTEUR_DROITE_VITESSE, OUTPUT);
  pinMode(PIN_MOTEUR_DROITE_SENS, OUTPUT);
  pinMode(PIN_MOTEUR_GAUCHE_VITESSE, OUTPUT);
  pinMode(PIN_MOTEUR_GAUCHE_SENS, OUTPUT);
  initialisation_variables();
  Serial.println("INIT Gros Robot");
Consigne_termine=false;
 delay(100);
 

}
void initialisation_variables()
{
 cnt = 0; // nombre de données découpées
  for(int i=0; i<10;i++)
    {
      data[i]="";
    }
 stringComplete = false;  // pour savoir si la chaine est complète
 inputString = "";   // chaine de caractères pour contenir les données


 Codeuse_Droite=0;//Nbr de tick droite
 Codeuse_Gauche=0;//Nbr de tick gauche
 Codeuse_Droite_PAST=0;//Ancien nbr de tick droite
 Codeuse_Gauche_PAST=0;//Ancien nbr de tick gauche

 //X_POS=0,Y_POS=0,ANGLE_POS=0;
 //angle_radian=0;

}
