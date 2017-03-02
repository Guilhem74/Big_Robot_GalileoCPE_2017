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
calcul_erreur();
}

void mise_a_jour_POS()
{
  float delta_D = (Codeuse_Droite_PAST - Codeuse_Droite)*TICS2MM; //En tic puis converti en mm
  float delta_G = (Codeuse_Gauche_PAST - Codeuse_Gauche)*TICS2MM; //En tic puis converti en mm

  float localX = 0, localY = 0;
  localY = (float)(((delta_D + delta_G) / 2.0f) * cos(angle_radian +(delta_D - delta_G) / (2* ECARTEMENT_ROUES)));//on parcourt cette distance avec l'angle initial
  localX = (float)(((delta_D + delta_G) / 2.0f) * sin(angle_radian +(delta_D - delta_G) / (2* ECARTEMENT_ROUES)));
  angle_radian += ((float)(delta_G - delta_D) / ECARTEMENT_ROUES); //Mise a jour de l'angle pour le prochain déplacement,toutes les distances doivent avoir les mêmes unités!


  X_POS += localX;
  Y_POS -= localY;
  ANGLE_POS = (angle_radian * 360 / (float)(2 * PI));


}
void calcul_erreur()
{

   int32_t dx=X_DEST-X_POS;
   int32_t dy=Y_DEST-Y_POS;
    float angle_dest=0;
if(dx==0&&dy==0)
       angle_dest=0;
else
        angle_dest =-(PI/2-atan2(dy,dx));
    int i=0;
    static int close_to_goal=0;

     erreur_angle_radian= (angle_radian - angle_dest) ;
   

     Distance_moyenne = (float)sqrt(dx*dx+dy*dy)*cos(erreur_angle_radian );


 
  
   if(sqrt(dx*dx+dy*dy)<15)
   {//Si je suis dans la boule d'arrivée
     erreur_angle_radian=angle_radian-ANGLE_FINAL*DEG2RAD;
     Distance_moyenne=0;//asservissement uniquement en angle
     close_to_goal=1;
     Serial.println("D1");
   }
   else
   {//Si je n'y suis pas
  if(close_to_goal=true&&sqrt(dx*dx+dy*dy)<30)
     {//Mais que j'y était avant et que je suis dans la boule de sortie
      erreur_angle_radian=angle_radian-ANGLE_FINAL*DEG2RAD;//Asservissement uniquement sur la disatnce et mon angle final
    
     }
     else
     {//je suis en dehors de la boule de sortie ou je ne suis pas encore passé par la boule d'arrivée
      close_to_goal=false;
     }
    }

}

