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
        angle_dest =-(PI/2-atan2(dy,dx));
    int i=0;
   



 
  
   if(sqrt(dx*dx+dy*dy)<5||(close_to_goal=true&&sqrt(dx*dx+dy*dy)<50))
   {//je suis arrivé ou je l'étais juste avant et je suis tres proche
    Serial.println("Boule arrivé");
     erreur_angle_radian=angle_radian-ANGLE_FINAL*DEG_TO_RAD;//asservissement sur angle final
                       Distance_moyenne = (float)sqrt(dx*dx+dy*dy);//J'asservis sur la distance
                       if(dy<0)
                        Distance_moyenne=- Distance_moyenne;
     close_to_goal=1;
     Compteur_stabilite_final++;
     if(Compteur_stabilite_final>=DUREE_VALIDATION_ETAT_FINAL)
     {//je suis stable
        Serial.println("Boule Stabilité");
      At_goal=true;
     }
     else
     {
      At_goal=false;
     }

   }
   else
   {//Je ne suis pas arrivé
    Compteur_stabilite_final=0;
    At_goal=false;
     //Je ne suis pas arrivé je dois donc m'asservir sur un angle/ou et une distance
      close_to_goal=false;
      erreur_angle_radian= (angle_radian - angle_dest) ;
      if(abs(erreur_angle_radian)<TOLERANCE_ANGLE)//On a le bon angle de destination on doit donc maintenant parcourir la distance
        Compteur_stabilite_angulaire++;
      else
        Compteur_stabilite_angulaire=0;
          Serial.println("Assert angle");
      if(Compteur_stabilite_angulaire>DUREE_VALIDATION_ETAT_FINAL)//je suis au bon angle
      {
                       Distance_moyenne = (float)sqrt(dx*dx+dy*dy)*cos(erreur_angle_radian );//J'asservis sur la distance
          Serial.println("Assert distance;"); 
      }
      else
                Distance_moyenne=0;
      
     
    }
     

}

