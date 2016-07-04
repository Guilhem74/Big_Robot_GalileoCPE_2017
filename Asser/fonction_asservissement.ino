void asservissement_robot()
{
//Lancement des asservissements
int Commande_Lin=asservissement_lineaire();
int Commande_Ang=asservissement_angulaire();
//Somme des commandes

Serial.println(Commande_Lin);


int Commande_D=asservissement_vitesseD(Commande_Lin+Commande_Ang);
int Commande_G=asservissement_vitesseD(Commande_Lin-Commande_Ang);


//Analyse du sens des moteurs en fonction des commandes (Commande <0 -> on recule)
bool sens_D=ETAT_MOTEUR_AVANCE;
bool sens_G=ETAT_MOTEUR_AVANCE;
if(Commande_D<0) sens_D=!ETAT_MOTEUR_AVANCE;
if(Commande_G<0) sens_G=!ETAT_MOTEUR_AVANCE;
Commande_D=abs(Commande_D);//PWM est toujours positif
Commande_G=abs(Commande_G);//PWM est toujours positif

if(Commande_D>255) Commande_D=255;//PWM_MAX est 255
if(Commande_G>255) Commande_G=255;//PWM_MAX est 255


//Envoi des commandes aux moteurs
  digitalWrite(PIN_MOTEUR_DROITE_SENS, sens_D);
  digitalWrite(PIN_MOTEUR_GAUCHE_SENS, sens_G);
  delayMicroseconds(10);
  analogWrite(PIN_MOTEUR_DROITE_VITESSE, Commande_D);
  analogWrite(PIN_MOTEUR_GAUCHE_VITESSE, Commande_G);
if((millis()-t_actuel)>TEMPS_MIN_ASSERT)
{
  Serial.println("Assert trop lent");
}

while((millis()-t_actuel)<TEMPS_MIN_ASSERT);//Afin d'avoir un asservissement régulier a constante de temps connu

}
int asservissement_lineaire()
{
 
  int Commande_lineaire;
  float erreur_precedente_lineaire = erreur_lineaire;//Sauvegarde de l'erreur precedente
  erreur_lineaire=L_consigne-0.5*(D+G);//Calcul de l'erreur actuel
  float delta_erreur_lineaire = erreur_lineaire-erreur_precedente_lineaire;//Calcul de la difference des erreurs, utile pour la derivee
  Somme_erreur_lineaire +=erreur_lineaire;//Somme des erreurs utile pour l'integrale

  Commande_lineaire=P_LINEAIRE*erreur_lineaire+I_LINEAIRE*Somme_erreur_lineaire+D_LINEAIRE*delta_erreur_lineaire;//On determine la commande a envoyer aux moteurs;
return Commande_lineaire;
}

int asservissement_angulaire()
{
  int Commande_angulaire;
  int32_t orientation = D-G;
  float erreur_precedente_angulaire = erreur_angulaire;//Sauvegarde de l'erreur precedente
  erreur_angulaire = A_consigne - orientation;
  float delta_erreur_angulaire = erreur_angulaire-erreur_precedente_angulaire;//Calcul de la difference des erreurs, utile pour la derivee
    Somme_erreur_angulaire +=erreur_angulaire;//Somme des erreurs utile pour l'integrale

Commande_angulaire = erreur_angulaire * P_ANGULAIRE +I_ANGULAIRE*Somme_erreur_angulaire+D_ANGULAIRE*delta_erreur_angulaire;;
return Commande_angulaire;
}

int asservissement_vitesseD(int Commande)
{
  int Commande_vitesseD;
  float erreur_precedente_vitesseD = erreur_vitesseD;//Sauvegarde de l'erreur precedente
  erreur_vitesseD = Commande - vitesse_D;
  float delta_erreur_vitesseD = erreur_vitesseD-erreur_precedente_vitesseD;//Calcul de la difference des erreurs, utile pour la derivee
    Somme_erreur_vitesseD +=erreur_vitesseD;//Somme des erreurs utile pour l'integrale

Commande_vitesseD = erreur_vitesseD * P_VITESSE +I_VITESSE*Somme_erreur_vitesseD+D_VITESSE*delta_erreur_vitesseD;;

return Commande_vitesseD;
}
int asservissement_vitesseG(int Commande)
{
  int Commande_vitesseG;
  float erreur_precedente_vitesseG = erreur_vitesseG;//Sauvegarde de l'erreur precedente
  erreur_vitesseG = Commande - vitesse_G;
  float delta_erreur_vitesseG = erreur_vitesseG-erreur_precedente_vitesseG;//Calcul de la difference des erreurs, utile pour la derivee
    Somme_erreur_vitesseG +=erreur_vitesseG;//Somme des erreurs utile pour l'integrale
Commande_vitesseG = erreur_vitesseG * P_VITESSE +I_VITESSE*Somme_erreur_vitesseG+D_VITESSE*delta_erreur_vitesseG;;
return Commande_vitesseG;
}
