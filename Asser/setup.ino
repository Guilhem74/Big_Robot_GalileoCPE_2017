#include "define.h"

void setup_asservissement()
{
  Serial1.begin(115200);
 Serial1.write('r');
 Serial.begin(115200);
 pinMode(PIN_MOTEUR_DROITE_VITESSE, OUTPUT);
  pinMode(PIN_MOTEUR_DROITE_SENS, OUTPUT);
  pinMode(PIN_MOTEUR_GAUCHE_VITESSE, OUTPUT);
  pinMode(PIN_MOTEUR_GAUCHE_SENS, OUTPUT);
  initialisation_variables();
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

 L_consigne=0;
 A_consigne=0;
 angle_robot=0;

 X_DEST=0,Y_DEST=0,ANGLE_DEST=0,ANGLE_FINAL=0;
 MARCHE_ARRIERE=true;
 close_to_goal=false;
 
 Distance_moyenne =0;
 erreur_angle_radian=0;

 erreur_lineaire=0;
 erreur_precedente_lineaire=0;
 Somme_erreur_lineaire=0;

 erreur_angulaire=0;
 Somme_erreur_angulaire=0;
 erreur_precedente_angulaire=0;

 erreur_vitesseD=0;
 Somme_erreur_vitesseD=0;
 erreur_vitesseG=0;
 Somme_erreur_vitesseG=0;

 Codeuse_Droite=0;//Nbr de tick droite
 Codeuse_Gauche=0;//Nbr de tick gauche
 Codeuse_Droite_PAST=0;//Ancien nbr de tick droite
 Codeuse_Gauche_PAST=0;//Ancien nbr de tick gauche
 t_precedent=0;
 t_actuel=0;
 delta_T=0;
 vitesse_G=0;
 vitesse_D=0;
 X_POS=0,Y_POS=0,ANGLE_POS=0;
 angle_radian=0;

}

