#include <Arduino.h>
#include "define.h"
void mise_a_jour_robot()
{
  //Sauvegarde des codeuses
Codeuse_Droite_PAST=Codeuse_Droite;
Codeuse_Gauche_PAST=Codeuse_Gauche;
//Maj des codeuses
recuperer(0);
recuperer(1);

//Maj de la position
mise_a_jour_POS();
}
void mise_a_jour_POS()
{
  float delta_D = (Codeuse_Droite_PAST - Codeuse_Droite)*TICS2MM; //En tic puis converti en mm
  float delta_G = (Codeuse_Gauche_PAST - Codeuse_Gauche)*TICS2MM; //En tic puis converti en mm
  float localX = 0, localY = 0;
  localY = (float)(((delta_D + delta_G) / 2.0f) * cos(angle_radian +(delta_D - delta_G) / (2* ECARTEMENT_ROUES)));//on parcourt cette distance avec l'angle initial
  localX = (float)(((delta_D + delta_G) / 2.0f) * sin(angle_radian +(delta_D - delta_G) / (2* ECARTEMENT_ROUES)));
  angle_radian += ((float)(delta_D - delta_G) / ECARTEMENT_ROUES); //Mise a jour de l'angle pour le prochain déplacement,toutes les distances doivent avoir les mêmes unités!

  X_POS += localX;
  Y_POS -= localY;
  ANGLE_POS = (angle_radian * RAD_TO_DEG);
//Serial.println(ANGLE_POS);
}
void calcul_erreur()
{
   float dx=X_DEST-X_POS;
   float dy=Y_DEST-Y_POS;
   if(dx==0)
   {
     dx=0.00001;
   }
   /*Serial.println("\n Dx;Dy :");
   Serial.println(X_DEST);
   Serial.println(Y_DEST);*/
    ///float angle_dest =-(atan2(dx,dy));

static int cpt=0;
    int i=0;
    int avancer=0;
   //mise au bon angle du robot avant déplacement
  float angle_robot=angle_radian*RAD_TO_DEG;
//conversion angle entre 0 et 360 car angle droite entre 0 et 360
  if(angle_robot<0) angle_robot+=360;

  //calcul angle de la droite
  float angle_droite1=-(atan2(dx,dy))*RAD_TO_DEG;
  if(angle_droite1<0) angle_droite1+=180;
  float angle_droite2=angle_droite1+180;
  if(angle_droite2>360) angle_droite2=angle_droite1-180;
  //Calcul angle minimum à faire pour s'aligner sur la droite
  float angle_necessaire=abs(angle_droite1-angle_robot);
  int angle_droite_retenu=angle_droite1;
  if(abs(angle_necessaire)>abs(angle_droite2-angle_robot)){
    angle_necessaire=abs(angle_droite2-angle_robot);
    angle_droite_retenu=angle_droite2;

  }
  if(abs(360-angle_robot+angle_droite1)<abs(angle_necessaire)){
    angle_necessaire=abs(360-angle_robot+angle_droite1);
    angle_droite_retenu=angle_droite1;

  }
  if(abs(360-angle_robot+angle_droite2)<abs(angle_necessaire)){
    angle_necessaire=abs(360-angle_robot+angle_droite2);
    angle_droite_retenu=angle_droite2;

  }
  if(abs(360-angle_droite2+angle_robot)<abs(angle_necessaire)){
    angle_necessaire=abs(360-angle_droite2+angle_robot);
    angle_droite_retenu=angle_droite2;

  }
  if(abs(360-angle_droite1+angle_robot)<abs(angle_necessaire)){
    angle_necessaire=abs(360-angle_droite1+angle_robot);
    angle_droite_retenu=angle_droite1;
  }
//  Serial.print("   ");
  //mise du robot au bon angle
  float angle_envoye=angle_radian;
  if(angle_droite_retenu>angle_robot) angle_envoye=abs(angle_necessaire);
  else angle_envoye=-abs(angle_necessaire);
  if(angle_droite_retenu>angle_robot+180) angle_envoye=-abs(angle_necessaire);
  if(angle_droite_retenu+180<angle_robot) angle_envoye=abs(angle_necessaire);
  /*if(angle_envoye>=0) angle_envoye=-angle_envoye;
  else angle_envoye=abs(angle_envoye);*/
  if(abs(dy)<2&&dx>0&&abs(angle_robot+angle_envoye)-90<=3) avancer=-1;
  else if((((abs(angle_robot+angle_envoye)<=90 || angle_robot+angle_envoye>=270) && Y_DEST>Y_POS) || (angle_robot+angle_envoye>90 && angle_robot+angle_envoye<270 && Y_DEST<Y_POS)) || (((angle_robot+angle_envoye>-180 && angle_robot+angle_envoye<0) || angle_robot+angle_envoye>=180) && X_DEST>X_POS) || (angle_robot+angle_envoye>90 && angle_robot+angle_envoye<270 && Y_DEST<Y_POS)|| (((angle_robot+angle_envoye>0 && angle_robot+angle_envoye<180) || angle_robot+angle_envoye<-180) && X_DEST<X_POS)) avancer=1;
  else avancer=-1;//



  static float Rampe_Angle=0;
  static float Rampe_Distance=0;
  float erreur_angle=angle_envoye;
  #define TOLERANCE_ANGLE_RAMPE 8
  #define TOLERANCE_DISTANCE_RAMPE 20
  #define TOLERANCE_DISTANCE_BOULE_ANGLE_FINAL 20
  #define TOLERANCE_DISTANCE 30
  #define TOLERANCE_ANGLE_FINAL 3
  static bool Mise_A_Angle=true;

  static bool Mise_A_Angle_Final=false;
if(sqrt(dx*dx+dy*dy)<TOLERANCE_DISTANCE_BOULE_ANGLE_FINAL)
{
  erreur_angle=-(angle_radian*RAD_TO_DEG-ANGLE_FINAL);//Asservissement a l'angle_Final
  Mise_A_Angle_Final=true;
}
else
{
   erreur_angle=angle_envoye ;//Asservissement a l'angle pour effectuer notre destination
   Mise_A_Angle_Final=false;

}


float Erreur_Distance=avancer*sqrt(dx*dx+dy*dy)*abs(cos(erreur_angle*DEG_TO_RAD));
  if(abs(Erreur_Distance)>TOLERANCE_DISTANCE_RAMPE&&Consigne_Actuel->Rampe_Distance_Active==true)
  {

      Rampe_Distance+=COEFF_RAMP_LINEAIRE;
      if(Rampe_Distance>1) Rampe_Distance=1;
      Erreur_Distance*=Rampe_Distance;
  }
  else
  {

      Rampe_Distance=0;
      Erreur_Distance=avancer*sqrt(dx*dx+dy*dy)*abs(cos(erreur_angle*DEG_TO_RAD));
      if(abs(Erreur_Distance)<TOLERANCE_DISTANCE&&Mise_A_Angle_Final==true &&Consigne_Actuel->Action==Deplacement&& abs(erreur_angle)<TOLERANCE_ANGLE_FINAL)
      {
          Consigne_termine=true;
          Rampe_Distance=0;
          Rampe_Angle=0;
          Mise_A_Angle_Final=false;
          Mise_A_Angle=true;
      }

  }

  float Erreur_Angulaire_Degres=erreur_angle;
  if(abs(Erreur_Angulaire_Degres)>TOLERANCE_ANGLE_RAMPE)
  {//L'erreur est trop grande il faut ramper
    if(abs(Erreur_Angulaire_Degres)>45)Rampe_Angle+=COEFF_RAMP_ANG/10;
    else Rampe_Angle+=COEFF_RAMP_ANG;
       if (Rampe_Angle > 1 ) Rampe_Angle=1 ;
       Erreur_Angulaire_Degres*=Rampe_Angle;
  }
  else
  {
    Rampe_Angle=0;
    Erreur_Angulaire_Degres=erreur_angle;//Pas de rampe
    if(abs(Erreur_Angulaire_Degres)<5&&Mise_A_Angle==true)Mise_A_Angle=false;

  }

  erreur_angle_radian=Erreur_Angulaire_Degres*DEG_TO_RAD;
(Mise_A_Angle==true/*&&sqrt(dx*dx+dy*dy)<50*/)? Distance_moyenne=0:Distance_moyenne=Erreur_Distance;



if(Consigne_Actuel->Action!=Deplacement){
  erreur_angle_radian=-(angle_radian-ANGLE_FINAL*DEG_TO_RAD);
//  Distance_moyenne=avancer*sqrt(dx*dx+dy*dy)*abs(cos(erreur_angle_radian));
}

/*Cas de detection*/
if(Obstacle_devant==true && Distance_moyenne>0&& (millis()-Temp_debut_match)>20000){
  Distance_moyenne=0;
  Rampe_Distance=0;
  Rampe_Angle=0;
  /*Rampe_angle=0;
  Rampe_distance=0;*/
}
else if(Obstacle_derriere==true && Distance_moyenne<0&&(millis()-Temp_debut_match)>20000){
  Distance_moyenne=0;
  Rampe_Distance=0;
  Rampe_Angle=0;
  /*Rampe_angle=0;
  Rampe_distance=0;*/
}



}

void Routine_Robot()
{


  if ((millis() - Temps_assert) > TEMPS_MIN_ASSERT) {
    Mise_A_Jour_Action_Robot();
    Mise_a_jour_bras();
    mise_a_jour_robot();
    calcul_erreur();
    Temps_assert = millis();
    asservissement_robot(Distance_moyenne, erreur_angle_radian);
//Serial.println(X_DEST);
  }
  Reception();
  Mise_a_jour_detection();
}
void Mise_A_Jour_Action_Robot()
{
  static bool First_Passage_Action=true;
  if(Consigne_termine==true)
  {
    if(Consigne_Actuel->Derniere_Consigne==false)
    {

      //Serial.println("Next Step");
      Consigne_Actuel=Consigne_Actuel->consigne_suivante;
      for(int i=0;i<TAILLE_TABLEAU_SOMME;i++)
      {
        Somme_Erreur_Lin[i]=0;
        Somme_Erreur_Ang[i]=0;
      }
        First_Passage_Action=true;
         New_moove_angle = true;
         New_moove_distance = false;
         New_moove_angle_final = false;
         premier_passage_A = false;
         Consigne_termine=false;
       }
      else
      {
        Robot_Principal=Fin;
      }
       Temps_Base_Systeme=millis();
    }

  switch (Consigne_Actuel->Action) {
    case Deplacement:
          X_DEST=Consigne_Actuel->X_DEST;
          Y_DEST=Consigne_Actuel->Y_DEST;
          ANGLE_FINAL=Consigne_Actuel->ANGLE_FINAL;
    break;
    case Pince_V:

      if(Consigne_Actuel->Information_Supplementaire==Pince_V_UP)
      {

        Pince_UP();

      }

      else if(Consigne_Actuel->Information_Supplementaire==Pince_V_DOWN)
          Pince_DOWN();
      else if(Consigne_Actuel->Information_Supplementaire==Pince_V_Bourrage)
          Pince_V_Bourre();
      else if(Consigne_Actuel->Information_Supplementaire==Pince_V_Pousse)
          Pince_V_Pousse_Action();
      else if(Consigne_Actuel->Information_Supplementaire==Pince_V_droite_up)
          Pince_V_d_up();
          else if(Consigne_Actuel->Information_Supplementaire==Pince_V_gauche_up)
              Pince_V_g_up();
    break;
    case Pince_H:
      if(Consigne_Actuel->Information_Supplementaire==Pince_H_Desserre)
        Pince_OPEN();
      else if(Consigne_Actuel->Information_Supplementaire==Pince_H_Pousse)
        Pince_WAIT();
      else if(Consigne_Actuel->Information_Supplementaire==Pince_H_Serre)
        Pince_CLOSE();
        else if(Consigne_Actuel->Information_Supplementaire==Pince_H_Droite_Desserre)
          Pince_D_OPEN();
        else if(Consigne_Actuel->Information_Supplementaire==Pince_H_Gauche_Desserre)
          Pince_G_OPEN();
          else if(Consigne_Actuel->Information_Supplementaire==Pince_H_Dechargement)
            Pince_H_Decharge();
    break;
    case Chargeur_Cylindre:
      if(Consigne_Actuel->Information_Supplementaire==Chargeur_Down&&First_Passage_Action==true)
        {Quart++;
        Chargeur_Pret=false;
      First_Passage_Action=false;}
      else if(Consigne_Actuel->Information_Supplementaire==Chargeur_UP&&First_Passage_Action==true)
        {Quart++;
        Chargeur_Pret=false;
        First_Passage_Action=false;}
    break;
    case Bras:
      if(Consigne_Actuel->Information_Supplementaire==Bras_Pousse)
        Etat_bras_voulu=1;
      else if(Consigne_Actuel->Information_Supplementaire==Bras_Retracte)
        Etat_bras_voulu=0;
    break;
  }
  //Actionneur Du bras Correct
  if(Consigne_Actuel->Action==Bras&&Etat_bras_voulu==Etat_bras)
  {
    Consigne_termine=true;
    //Serial.println("Bras poussé");
  }
  //gestion Du chargeur de Cylindre
  if(Consigne_Actuel->Action==Chargeur_Cylindre&&  Chargeur_Pret)
  {
    Consigne_termine=true;
    //Serial.println("Chargeur OK");
  }
//Gestion du Timeout
if (Consigne_Actuel->TimeOut != -1) {
  if ((millis() - Temps_Base_Systeme) > Consigne_Actuel->TimeOut) {
    Consigne_termine = true;
    //Serial.println("TimeOut");
  }
}
}
