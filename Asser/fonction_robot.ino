#include "define.h"

void mise_a_jour_robot()
{
  //Sauvegarde des codeuses
D_ancien=D;
G_ancien=G;
  //Maj du tems
t_precedent=t_actuel;
t_actuel=millis();
delta_T=t_actuel-t_precedent;//en ms
//Maj des codeuses
recuperer(0);
recuperer(1);
//Maj des vitesses;
vitesse_D=(D-D_ancien)/delta_T;//Vitesse par s
vitesse_G=(G-G_ancien)/delta_T;//Vitesse 

//Maj de la position
mise_a_jour_POS();
calcul_erreur();
}


void mise_a_jour_POS()
{
  float delta_D = (D_ancien - D)*TICS2MM; //En tic puis converti en mm
  float delta_G = (G_ancien - G)*TICS2MM; //En tic puis converti en mm
  
  float localX = 0, localY = 0;
  localY = (float)(((delta_D + delta_G) / 2.0f) * cos(angle_radian +(delta_D - delta_G) / float(2* ECARTEMENT_ROUES)));//on parcourt cette distance avec l'angle initial
  localX = (float)(((delta_D + delta_G) / 2.0f) * sin(angle_radian +(delta_D - delta_G) / float(2* ECARTEMENT_ROUES)));
  angle_radian += ((float)(delta_D - delta_G) / ECARTEMENT_ROUES); //Mise a jour de l'angle pour le prochain déplacement,toutes les distances doivent avoir les mêmes unités!
  while (angle_radian >= 2*PI)angle_radian -= 2 * PI;
  while (angle_radian < -2*PI)angle_radian += 2 * PI;

  X_POS -= localX;
  Y_POS -= localY;
  ANGLE_POS = (angle_radian * 360 / (float)(2 * PI));


}
void calcul_erreur()
{

  float dx=X_DEST-X_POS;
  float dy=Y_DEST-Y_POS;
  
  ANGLE_DEST=(atan2(dx,dy));
  
//if(ANGLE_DEST==3.14)
//{
//  ANGLE_DEST=0;
//}
//if(ANGLE_DEST>1.57)
//{
//  ANGLE_DEST=ANGLE_DEST-3.14;
//}

//TO DO MARCHE ARRIERE
   erreur_angle_radian= angle_radian - ANGLE_DEST  ;
  
   
   Distance_moyenne = (float)sqrt(dx*dx+dy*dy)*(float)cos(erreur_angle_radian -PI*MARCHE_ARRIERE);
   if(erreur_angle_radian*RAD2DEG>90 ||erreur_angle_radian*RAD2DEG<-90)
   {
     Distance_moyenne = -(float)sqrt(dx*dx+dy*dy)*(float)cos(erreur_angle_radian -PI);
     erreur_angle_radian= angle_radian - ANGLE_DEST  -PI;
     
   }
 
   if(sqrt(dx*dx+dy*dy)<5)
   {//Si je suis dans la boule d'arrivée
     erreur_angle_radian=angle_radian-ANGLE_FINAL*DEG2RAD;
     Distance_moyenne=0;//asservissement uniquement en angle
     close_to_goal=true;
     
   }
   else 
   {//Si je n'y suis pas
    if(close_to_goal=true&&sqrt(dx*dx+dy*dy)<50)
     {//Mais que j'y était avant et que je suis dans la boule de sortie
      erreur_angle_radian=angle_radian-ANGLE_FINAL*DEG2RAD;//Asservissement uniquement sur la disatnce et mon angle final
     }
     else
     {//je suis en dehors de la boule de sortie ou je ne suis pas encore passé par la boule d'arrivée
      close_to_goal=false;
     }
   } 


   

   
}

