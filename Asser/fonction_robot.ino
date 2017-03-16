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
  angle_radian -= ((float)(delta_D - delta_G) / ECARTEMENT_ROUES); //Mise a jour de l'angle pour le prochain déplacement,toutes les distances doivent avoir les mêmes unités!


  X_POS -= localX;
  Y_POS -= localY;
  ANGLE_POS = (angle_radian * 360 / (float)(2 * PI));
//Serial.println(ANGLE_POS);

}
void calcul_erreur()
{

   int32_t dx=X_DEST-X_POS;
   int32_t dy=Y_DEST-Y_POS;
    float angle_dest =-(atan2(dx,dy));
    int i=0;
    int avancer=-1;
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
  
  //mise du robot au bon angle
  float angle_envoye=angle_radian;
  
  if(angle_droite_retenu>angle_robot) angle_envoye=abs(angle_necessaire);
  else angle_envoye=-abs(angle_necessaire);

  if(angle_droite_retenu>angle_robot+180) angle_envoye=-abs(angle_necessaire);
  if(angle_droite_retenu+180<angle_robot) angle_envoye=abs(angle_necessaire);
  if(Y_DEST<Y_POS) avancer=-1;
  else avancer=1;
  if(Y_DEST==Y_POS){
    avancer=1;
  }
  if(sqrt(dx*dx+dy*dy)<100)
  {
    erreur_angle_radian=(angle_radian-ANGLE_FINAL*DEG_TO_RAD);

  }
   else
    erreur_angle_radian=angle_envoye*DEG_TO_RAD;


  //à présent robot dans l'axe de la droite passant par lui et le point
  //coeff directeur droite
  float m=dy/dx;
  //calcul distance entre les deux
   Distance_moyenne=avancer*sqrt(dx*dx+dy*dy)*cos(erreur_angle_radian);
  Serial.print(avancer);
  Serial.print(" ");
Serial.println(erreur_angle_radian);

    
   /*
float angle_calc =abs(abs(angle_radian)-abs(angle_dest));
float angle_calc2 =abs(abs(angle_radian)-abs(angle_dest));
float angle_calc3 =abs(abs(angle_radian)-abs(angle_dest));
if(angle_calc < angle_calc2 && angle_calc <angle_calc3)
{
  angle_dest=angle_calc;
}
else if(angle_calc2 < angle_calc3 && angle_calc2 <angle_calc)
{
  angle_dest=-angle_calc2;
}
else if(angle_calc3 < angle_calc2 && angle_calc3 <angle_calc)
{
  angle_dest=-angle_calc3;
}*/
//      Serial.print("X: ");
//  Serial.print(angle_calc);
//  Serial.print(" Y:  ");
//  Serial.print( angle_calc2);
//   Serial.print(" A:  ");
//  Serial.print( angle_calc3);
//    Serial.print("A_Dest: ");
//    Serial.print( angle_dest);
//    Serial.print("A_Dest deg: ");
//  Serial.print(angle_dest*RAD_TO_DEG);
//  Serial.print("  ");
//  Serial.print("Erreur_A: ");
//  Serial.println(erreur_angle_radian*RAD_TO_DEG);
  
 
//  
//   if(sqrt(dx*dx+dy*dy)<5||(close_to_goal=true&&sqrt(dx*dx+dy*dy)<50))
//   {//je suis arrivé ou je l'étais juste avant et je suis tres proche
//   // Serial.println("Boule arrivé");
//     erreur_angle_radian=angle_radian-ANGLE_FINAL*DEG_TO_RAD;//asservissement sur angle final
//                       Distance_moyenne = (float)sqrt(dx*dx+dy*dy);//J'asservis sur la distance
//                       if(dy<0)
//                        Distance_moyenne=- Distance_moyenne;
//     close_to_goal=1;
//     Compteur_stabilite_final++;
//     if(Compteur_stabilite_final>=DUREE_VALIDATION_ETAT_FINAL)
//     {//je suis stable
//       // Serial.println("Boule Stabilité");
//      At_goal=true;
//     }
//     else
//     {
//      At_goal=false;
//     }
//
//   }
//   else
//   {//Je ne suis pas arrivé
//    Compteur_stabilite_final=0;
//    At_goal=false;
//     //Je ne suis pas arrivé je dois donc m'asservir sur un angle/ou et une distance
//      close_to_goal=false;
//      erreur_angle_radian= (angle_radian - angle_dest) ;
//      if(abs(erreur_angle_radian)<TOLERANCE_ANGLE)//On a le bon angle de destination on doit donc maintenant parcourir la distance
//        Compteur_stabilite_angulaire++;
//      else
//        Compteur_stabilite_angulaire=0;
//        //  Serial.println("Assert angle");
//      if(Compteur_stabilite_angulaire>DUREE_VALIDATION_ETAT_FINAL)//je suis au bon angle
//      {
//                       Distance_moyenne = (float)sqrt(dx*dx+dy*dy)*cos(erreur_angle_radian );//J'asservis sur la distance
//          //Serial.println("Assert distance;"); 
//      }
//      else
//                Distance_moyenne=0;
//      
//     
//    }
     

}

