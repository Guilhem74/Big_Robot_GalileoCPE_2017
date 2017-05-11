#include <Arduino.h>

#include "define.h"
void mise_a_jour_robot()
{
  //Sauvegarde des codeuses
Codeuse_Droite_PAST=Codeuse_Droite;
Codeuse_Gauche_PAST=Codeuse_Gauche;
  //Maj du tems
t_precedent=t_actuel;
t_actuel=millis();
delta_T=t_actuel-t_precedent;//en ms
//Maj des codeuses
recuperer(0);
recuperer(1);
//Maj des vitesses;
vitesse_D=(Codeuse_Droite-Codeuse_Droite_PAST)/delta_T;//Vitesse par s
vitesse_G=(Codeuse_Gauche-Codeuse_Gauche_PAST)/delta_T;//Vitesse

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
  angle_radian += ((float)(delta_D - delta_G) / ECARTEMENT_ROUES)*0; //Mise a jour de l'angle pour le prochain déplacement,toutes les distances doivent avoir les mêmes unités!


  X_POS += localX;
  Y_POS -= localY;
  ANGLE_POS = (angle_radian * 360 / (float)(2 * PI));
//Serial.println(ANGLE_POS);

}
void calcul_erreur()
{

   int32_t dx=Consigne_Actuel->X_DEST-X_POS;
   int32_t dy=Consigne_Actuel->Y_DEST-Y_POS;
    float angle_dest =-(atan2(dx,dy));


    int i=0;
    int avancer=0;
   //mise au bon angle du robot avant déplacement
  float angle_robot=angle_radian*RAD_TO_DEG;

//conversion angle entre 0 et 360 car angle droite entre 0 et 360
  if(angle_robot<0) angle_robot+=360;
//  Serial.print("Angle robot: ");
//  Serial.print(angle_robot);
//  Serial.print("   ");
  //calcul angle de la droite
  float angle_droite1=-(atan2(dx,dy))*RAD_TO_DEG;
  if(angle_droite1<0) angle_droite1+=180;
//  Serial.print("Angle droite 1 : ");
//  Serial.print(angle_droite1);
//  Serial.print("   ");
  float angle_droite2=angle_droite1+180;
  if(angle_droite2>360) angle_droite2=angle_droite1-180;
//  Serial.print("Angle droite 2: ");
//  Serial.print(angle_droite2);
//  Serial.print("    ");
  //Calcul angle minimum à faire pour s'aligner sur la droite
  float angle_necessaire=abs(angle_droite1-angle_robot);
  int angle_droite_retenu=angle_droite1;
  if(abs(angle_necessaire)>abs(angle_droite2-angle_robot)){
    angle_necessaire=abs(angle_droite2-angle_robot);
    angle_droite_retenu=angle_droite2;
//    Serial.print(" 2 ");
//    Serial.print(" ");
  }
  if(abs(360-angle_robot+angle_droite1)<abs(angle_necessaire)){
    angle_necessaire=abs(360-angle_robot+angle_droite1);
    angle_droite_retenu=angle_droite1;
//    Serial.print(" 3 ");
//    Serial.print(" ");
  }
  if(abs(360-angle_robot+angle_droite2)<abs(angle_necessaire)){
    angle_necessaire=abs(360-angle_robot+angle_droite2);
    angle_droite_retenu=angle_droite2;
//    Serial.print(" 4 ");
//    Serial.print(" ");
  }
  if(abs(360-angle_droite2+angle_robot)<abs(angle_necessaire)){
    angle_necessaire=abs(360-angle_droite2+angle_robot);
    angle_droite_retenu=angle_droite2;
//    Serial.print(" 5 ");
//    Serial.print(" ");
  }
  if(abs(360-angle_droite1+angle_robot)<abs(angle_necessaire)){
    angle_necessaire=abs(360-angle_droite1+angle_robot);
    angle_droite_retenu=angle_droite1;
//    Serial.print(" 6 ");
//    Serial.print(" ");
  }
//  Serial.print("Angle droite retenu: ");
//  Serial.print(angle_droite_retenu);
//  Serial.print("   ");
  //mise du robot au bon angle
  float angle_envoye=angle_radian;

  if(angle_droite_retenu>angle_robot) angle_envoye=abs(angle_necessaire);
  else angle_envoye=-abs(angle_necessaire);

  if(angle_droite_retenu>angle_robot+180) angle_envoye=-abs(angle_necessaire);
  if(angle_droite_retenu+180<angle_robot) angle_envoye=abs(angle_necessaire);

  /*if(angle_envoye>=0) angle_envoye=-angle_envoye;
  else angle_envoye=abs(angle_envoye);*/
  if(abs(dy)<2&&dx>0&&abs(angle_robot+angle_envoye)-90<=2) avancer=-1;
  else if((((abs(angle_robot+angle_envoye)<=90 || angle_robot+angle_envoye>=270) && Consigne_Actuel->Y_DEST>Y_POS) || (angle_robot+angle_envoye>90 && angle_robot+angle_envoye<270 && Consigne_Actuel->Y_DEST<Y_POS)) || (((angle_robot+angle_envoye>-180 && angle_robot+angle_envoye<0) || angle_robot+angle_envoye>=180) && Consigne_Actuel->X_DEST>X_POS) || (angle_robot+angle_envoye>90 && angle_robot+angle_envoye<270 && Consigne_Actuel->Y_DEST<Y_POS)|| (((angle_robot+angle_envoye>0 && angle_robot+angle_envoye<180) || angle_robot+angle_envoye<-180) && Consigne_Actuel->X_DEST<X_POS)) avancer=1;
  else avancer=-1;//


   /*Distance_moyenne=avancer*sqrt(dx*dx+dy*dy)*abs(cos(angle_envoye*DEG_TO_RAD));*/


    if(abs(angle_envoye)>5 && Consigne_Actuel->New_moove_angle==true){

      Distance_moyenne=0;
      if(angle_envoye>=0){
          Rampe_angle+=Consigne_Actuel->coeff_ramp_ang*TEMPS_MIN_ASSERT*angle_envoye/2; //temps_min_assert en ms, vaut actuellement 10, donc on atteint notre consigne d'angle au bout de 5s
          if(Rampe_angle>=angle_envoye) Rampe_angle=angle_envoye;
      }
      if(angle_envoye<0){
        Rampe_angle+=Consigne_Actuel->coeff_ramp_ang*TEMPS_MIN_ASSERT*angle_envoye/2; //temps_min_assert en ms, vaut actuellement 10, donc on atteint notre consigne d'angle au bout de 5s
        if(Rampe_angle<=angle_envoye) Rampe_angle=angle_envoye;
      }



      angle_envoye=Rampe_angle;
    }
    else if(Consigne_Actuel->New_moove_angle==true){
      Consigne_Actuel->New_moove_angle=false;
      Consigne_Actuel->New_moove_distance=true;
    }

/*
    if(abs(Distance_moyenne)>=50 && Consigne_Actuel->New_moove_distance==true){
        if(Distance_moyenne>=0){
          Rampe_distance+=Consigne_Actuel->coeff_ramp_lin*TEMPS_MIN_ASSERT*Distance_moyenne/2; //temps_min_assert en ms, vaut actuellement 10, donc on atteint notre consigne distance au bout de 2s
          if(Rampe_distance>=Distance_moyenne) Rampe_distance=Distance_moyenne;
        }
        if(Distance_moyenne<0){
          Rampe_distance+=Consigne_Actuel->coeff_ramp_lin*TEMPS_MIN_ASSERT*Distance_moyenne/2; //temps_min_assert en ms, vaut actuellement 10, donc on atteint notre consigne distance au bout de 2s
          if(Rampe_distance<=Distance_moyenne) Rampe_distance=Distance_moyenne;
        }
        Distance_moyenne=Rampe_distance;
    }else if(Consigne_Actuel->New_moove_distance==true){
      Consigne_Actuel->New_moove_distance=false;
      Consigne_Actuel->New_moove_angle_final=true;
      Consigne_Actuel->premier_passage=true;
    }*/

    if(sqrt(dx*dx+dy*dy)>=50 && Consigne_Actuel->New_moove_distance==true){
        Rampe_distance+=Consigne_Actuel->coeff_ramp_lin*TEMPS_MIN_ASSERT*sqrt(dx*dx+dy*dy)/2;
        if(Rampe_distance>=sqrt(dx*dx+dy*dy)) Rampe_distance=sqrt(dx*dx+dy*dy);
        }
    else if(Consigne_Actuel->New_moove_distance==true){
      Consigne_Actuel->New_moove_distance=false;
      Consigne_Actuel->New_moove_angle_final=true;
      Consigne_Actuel->premier_passage=true;
    }
    Distance_moyenne=avancer*Rampe_distance*abs(cos(angle_envoye*DEG_TO_RAD));
    Serial.print("X;");
    Serial.print(DELTA_Consigne_Init+Distance_moyenne);
    Serial.print(";");
    Serial.println(DELTA_Consigne_Init);

  /* if(sqrt(dx*dx+dy*dy)<50 && Consigne_Actuel->New_moove_angle_final==true){
      if(Consigne_Actuel->premier_passage==true){
        angle_robot=angle_radian*RAD_TO_DEG;
        if(angle_robot<0) angle_robot+=360;
        if(Consigne_Actuel->ANGLE_FINAL<0) Consigne_Actuel->ANGLE_FINAL+=360;
        Distance_moyenne=0;
        Rampe_angle=0;
        Consigne_Actuel->premier_passage==false;
      }
      if(angle_robot<=Consigne_Actuel->ANGLE_FINAL){
          Rampe_angle+=Consigne_Actuel->Rampe_angle_final*TEMPS_MIN_ASSERT*Consigne_Actuel->ANGLE_FINAL/2; //temps_min_assert en ms, vaut actuellement 10, donc on atteint notre consigne d'angle au bout de 5s
          erreur_angle_radian=angle_envoye*DEG_TO_RAD;
          if(Rampe_angle+angle_robot>=Consigne_Actuel->ANGLE_FINAL){
            erreur_angle_radian=-(angle_radian-Consigne_Actuel->ANGLE_FINAL*DEG_TO_RAD);
            Consigne_Actuel->New_moove_angle_final=false;
          }
      }
      if(angle_robot>Consigne_Actuel->ANGLE_FINAL){
          Rampe_angle-=Consigne_Actuel->Rampe_angle_final*TEMPS_MIN_ASSERT*Consigne_Actuel->ANGLE_FINAL/2; //temps_min_assert en ms, vaut actuellement 10, donc on atteint notre consigne d'angle au bout de 5s
          erreur_angle_radian=angle_envoye*DEG_TO_RAD;
          if(Rampe_angle+angle_robot<=Consigne_Actuel->ANGLE_FINAL){
            erreur_angle_radian=-(angle_radian-Consigne_Actuel->ANGLE_FINAL*DEG_TO_RAD);
            Consigne_Actuel->New_moove_angle_final=false;
          }
      }
      //angle_envoye=Rampe_angle;
      erreur_angle_radian=-(angle_radian-Consigne_Actuel->ANGLE_FINAL*DEG_TO_RAD);

    }

   if(sqrt(dx*dx+dy*dy)<50){

        erreur_angle_radian=-(angle_radian-Consigne_Actuel->ANGLE_FINAL*DEG_TO_RAD);
        if(abs(erreur_angle_radian*RAD_TO_DEG)<5)
        {
           Consigne_Actuel->Consigne_termine=true;
           Serial.println("Fin etape");
         }


   }
   else     erreur_angle_radian=angle_envoye*DEG_TO_RAD;*/

/*
   Serial.print("D_moy");
   Serial.println (Distance_moyenne);
   Serial.println(avancer);

   Serial.println(angle_envoye);
   Serial.println(angle_robot);*/
   /*
   Serial.print("\nx_pos y_pos");
   Serial.print(X_POS);
   Serial.print("  ");
   Serial.print(Y_POS);
   Serial.print("\navancer");
   Serial.print(avancer);
   Serial.print("\nangle");
   Serial.print(angle_robot);*/
}
