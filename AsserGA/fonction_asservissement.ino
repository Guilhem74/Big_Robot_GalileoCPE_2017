void asservissement_robot()
{
//Lancement des asservissements
int Commande_Lin=asservissement_lineaire();
int Commande_Ang=asservissement_angulaire();
//Somme des commandes
int Commande_D=Commande_Lin+Commande_Ang;
int Commande_G=Commande_Lin-Commande_Ang;

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
  delay(1);
  analogWrite(PIN_MOTEUR_DROITE_VITESSE, Commande_D);
  analogWrite(PIN_MOTEUR_GAUCHE_VITESSE, Commande_G);

while((millis()-t_actuel)<TEMPS_MIN_ASSERT);//Afin d'avoir un asservissement régulier a constante de temps connu
}
int asservissement_lineaire()
{
 
  int Commande_lineaire;
  float erreur_precedente_lineaire = erreur_lineaire;//Sauvegarde de l'erreur precedente
  erreur_lineaire=L_consigne-0.5*(D+G);//Calcul de l'erreur actuel
  float delta_erreur_lineaire = erreur_lineaire-erreur_precedente_lineaire;//Calcul de la difference des erreurs, utile pour la derivee
  Somme_erreur_lineaire +=erreur_lineaire;//Somme des erreurs utile pour l'integrale
  
  
  
  Commande_lineaire=P_lineaire*erreur_lineaire+I_lineaire*Somme_erreur_lineaire+D_lineaire*delta_erreur_lineaire;//On determine la commande a envoyer aux moteurs;
if(Commande_lineaire>255) Commande_lineaire=255;//PWM <255, Ecretage
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

Commande_angulaire = erreur_angulaire * P_angulaire +I_angulaire*Somme_erreur_angulaire+D_angulaire*delta_erreur_angulaire;;
if(Commande_angulaire>255) Commande_angulaire=255;//PWM <255, Ecretage
return Commande_angulaire;
}

