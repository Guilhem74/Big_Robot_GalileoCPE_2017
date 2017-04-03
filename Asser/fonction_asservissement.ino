void asservissement_robot(float Consigne_Lin, float Consigne_Ang)
{
float Commande_Lin=asservissement_lineaire(Consigne_Lin);
float Commande_Ang=asservissement_angulaire(Consigne_Ang);
//Somme des commandes
if(Commande_Ang>2*LIMIT_PWM_MAX)
{
  Commande_Ang=LIMIT_PWM_MAX;
}
if(Commande_Ang<-2*LIMIT_PWM_MAX)
{
  Commande_Ang=-LIMIT_PWM_MAX;
}
 
float Commande_D=round(Commande_Lin+Commande_Ang);
float Commande_G=round(Commande_Lin-Commande_Ang);


//
//
//if(Commande_D>LIMIT_PWM_MAX&&Commande_Ang>0) 
//{
//  Commande_D=LIMIT_PWM_MAX;//PWM_MAX est 255
//  Commande_G=LIMIT_PWM_MAX-2*Commande_Ang;//PWM_MAX est 255
//  Serial.println("D_max");
//}
//else if(Commande_G>LIMIT_PWM_MAX&&Commande_Ang<0) 
//{
//  Commande_G=LIMIT_PWM_MAX;//PWM_MAX est 255
//  Commande_D=LIMIT_PWM_MAX+2*Commande_Ang;//PWM_MAX est 255
//  Serial.println("G_max");
//}
//else if(Commande_D<-LIMIT_PWM_MAX&&Commande_Ang>0) 
//{
//  Commande_D=-LIMIT_PWM_MAX;//PWM_MAX est 255
//  Commande_G=-LIMIT_PWM_MAX+2*Commande_Ang;//PWM_MAX est 255
//  Serial.println("Darr_max");
//}
//else if(Commande_G<-LIMIT_PWM_MAX&&Commande_Ang<0) 
//{
//  Commande_G=-LIMIT_PWM_MAX;//PWM_MAX est 255
//  Commande_D=-LIMIT_PWM_MAX-2*Commande_Ang;//PWM_MAX est 255
//  Serial.println("Garr_max");
//}

//Analyse du sens des moteurs en fonction des commandes (Commande <0 -> on recule)
bool sens_D=ETAT_MOTEUR_AVANCE;
bool sens_G=ETAT_MOTEUR_AVANCE;
if(Commande_D<0) sens_D=!ETAT_MOTEUR_AVANCE;
if(Commande_G<0) sens_G=!ETAT_MOTEUR_AVANCE;


Commande_D=abs(Commande_D);
Commande_G=abs(Commande_G);

//Envoi des commandes aux moteurs
  digitalWrite(PIN_MOTEUR_DROITE_SENS, sens_D);
  digitalWrite(PIN_MOTEUR_GAUCHE_SENS, sens_G);
  delayMicroseconds(10);
  
  analogWrite(PIN_MOTEUR_DROITE_VITESSE, Commande_D);
  analogWrite(PIN_MOTEUR_GAUCHE_VITESSE, Commande_G);


}
float asservissement_lineaire(float Consigne)
{
  erreur_precedente_lineaire = erreur_lineaire;//Sauvegarde de l'erreur precedente
  erreur_lineaire=Consigne;

  float delta_erreur_lineaire = erreur_lineaire-erreur_precedente_lineaire;//D
  Somme_erreur_lineaire +=erreur_lineaire;//I

  float Commande_lineaire= P_LINEAIRE*erreur_lineaire +I_LINEAIRE*Somme_erreur_lineaire+D_LINEAIRE*delta_erreur_lineaire;//On determine la commande a envoyer aux moteurs;
  return Commande_lineaire;
}

float asservissement_angulaire(float Consigne)
{
  //erreur_angle_radian
  erreur_precedente_angulaire=erreur_angulaire;
  erreur_angulaire=Consigne;
  float delta_erreur_angulaire = erreur_angulaire-erreur_precedente_angulaire;//D
  Somme_erreur_angulaire +=erreur_angulaire;//I

  float Commande_angulaire = erreur_angulaire * P_ANGULAIRE +I_ANGULAIRE*Somme_erreur_angulaire+D_ANGULAIRE*delta_erreur_angulaire;//PID
  return Commande_angulaire;
}

//int asservissement_vitesseD(int Commande)
//{
//  int Commande_vitesseD;
//  float erreur_precedente_vitesseD = erreur_vitesseD;//Sauvegarde de l'erreur precedente
//  erreur_vitesseD = Commande - vitesse_D;
//  
//  float delta_erreur_vitesseD = erreur_vitesseD-erreur_precedente_vitesseD;//Calcul de la difference des erreurs, utile pour la derivee
//    Somme_erreur_vitesseD +=erreur_vitesseD;//Somme des erreurs utile pour l'integrale
//
//Commande_vitesseD = erreur_vitesseD * P_VITESSE +I_VITESSE*Somme_erreur_vitesseD+D_VITESSE*delta_erreur_vitesseD;;
//
//return Commande_vitesseD;
//}
//int asservissement_vitesseG(int Commande)
//{
//  int Commande_vitesseG;
//  float erreur_precedente_vitesseG = erreur_vitesseG;//Sauvegarde de l'erreur precedente
//  erreur_vitesseG = Commande - vitesse_G;
//  float delta_erreur_vitesseG = erreur_vitesseG-erreur_precedente_vitesseG;//Calcul de la difference des erreurs, utile pour la derivee
//    Somme_erreur_vitesseG +=erreur_vitesseG;//Somme des erreurs utile pour l'integrale
//Commande_vitesseG = erreur_vitesseG * P_VITESSE +I_VITESSE*Somme_erreur_vitesseG+D_VITESSE*delta_erreur_vitesseG;;
//return Commande_vitesseG;
//}
