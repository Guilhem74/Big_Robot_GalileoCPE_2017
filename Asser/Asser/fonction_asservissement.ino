#include <Arduino.h>

void asservissement_robot(float Consigne_Lin, float Consigne_Ang) {
  float Commande_Lin = asservissement_lineaire(Consigne_Lin);
  float Commande_Ang = asservissement_angulaire(Consigne_Ang);

  float Commande_D = round(Commande_Lin + Commande_Ang);
  float Commande_G = round(Commande_Lin - Commande_Ang);

  bool sens_D = ETAT_MOTEUR_AVANCE;
  bool sens_G = !ETAT_MOTEUR_AVANCE;

  if (Commande_D < 0)
    sens_D = !ETAT_MOTEUR_AVANCE;
  if (Commande_G < 0)
    sens_G = ETAT_MOTEUR_AVANCE;

  Commande_D = abs(Commande_D);
  Commande_G = abs(Commande_G);
  if (Commande_D > 255)
    Commande_D = 255;
  if (Commande_G > 255)
    Commande_G = 255;

  // Envoi des commandes aux moteurs
  digitalWrite(PIN_MOTEUR_DROITE_SENS, sens_D);
  digitalWrite(PIN_MOTEUR_GAUCHE_SENS, sens_G);
  delayMicroseconds(10);

  analogWrite(PIN_MOTEUR_DROITE_VITESSE, Commande_D);
  analogWrite(PIN_MOTEUR_GAUCHE_VITESSE, Commande_G);
}
float asservissement_lineaire(float Consigne) {
  erreur_precedente_lineaire =
      erreur_lineaire; // Sauvegarde de l'erreur precedente
  erreur_lineaire = Consigne;

  float delta_erreur_lineaire =
      erreur_lineaire - erreur_precedente_lineaire; // D
      static int32_t i=0;
  Consigne_Actuel->Somme_Erreur_Ang[i%TAILLE_TABLEAU_SOMME]= erreur_angulaire;         // I
  float Somme_Erreur_Lineaire_Local=0;
  for(int j=0;j<TAILLE_TABLEAU_SOMME;j++)
  {
    Somme_Erreur_Lineaire_Local+=  Consigne_Actuel->Somme_Erreur_Ang[j%TAILLE_TABLEAU_SOMME];
  }
  i++;
  float Commande_lineaire =
      P_LINEAIRE * erreur_lineaire + I_LINEAIRE * Somme_Erreur_Lineaire_Local  +
      D_LINEAIRE * delta_erreur_lineaire; // On determine la commande a envoyer
                                          // aux moteurs;
  return Commande_lineaire;
}

float asservissement_angulaire(float Consigne) {
  // erreur_angle_radian
  erreur_precedente_angulaire = erreur_angulaire;
  erreur_angulaire = Consigne;
  float delta_erreur_angulaire =
      erreur_angulaire - erreur_precedente_angulaire; // D
      static int32_t i=0;
  Consigne_Actuel->Somme_Erreur_Ang[i%TAILLE_TABLEAU_SOMME]= erreur_angulaire;         // I
  float Somme_Erreur_Angulaire_Local=0;
  for(int j=0;j<TAILLE_TABLEAU_SOMME;j++)
  {
    Somme_Erreur_Angulaire_Local+=  Consigne_Actuel->Somme_Erreur_Ang[j%TAILLE_TABLEAU_SOMME];
  }
  i++;
  float Commande_angulaire = erreur_angulaire * P_ANGULAIRE +
                             I_ANGULAIRE * Somme_Erreur_Angulaire_Local +
                             D_ANGULAIRE * delta_erreur_angulaire; // PID
  return Commande_angulaire;
}

// int asservissement_vitesseD(int Commande)
//{
//  int Commande_vitesseD;
//  float erreur_precedente_vitesseD = erreur_vitesseD;//Sauvegarde de l'erreur
//  precedente
//  erreur_vitesseD = Commande - vitesse_D;
//
//  float delta_erreur_vitesseD =
//  erreur_vitesseD-erreur_precedente_vitesseD;//Calcul de la difference des
//  erreurs, utile pour la derivee
//    Somme_erreur_vitesseD +=erreur_vitesseD;//Somme des erreurs utile pour
//    l'integrale
//
// Commande_vitesseD = erreur_vitesseD * P_VITESSE
// +I_VITESSE*Somme_erreur_vitesseD+D_VITESSE*delta_erreur_vitesseD;;
//
// return Commande_vitesseD;
//}
// int asservissement_vitesseG(int Commande)
//{
//  int Commande_vitesseG;
//  float erreur_precedente_vitesseG = erreur_vitesseG;//Sauvegarde de l'erreur
//  precedente
//  erreur_vitesseG = Commande - vitesse_G;
//  float delta_erreur_vitesseG =
//  erreur_vitesseG-erreur_precedente_vitesseG;//Calcul de la difference des
//  erreurs, utile pour la derivee
//    Somme_erreur_vitesseG +=erreur_vitesseG;//Somme des erreurs utile pour
//    l'integrale
// Commande_vitesseG = erreur_vitesseG * P_VITESSE
// +I_VITESSE*Somme_erreur_vitesseG+D_VITESSE*delta_erreur_vitesseG;;
// return Commande_vitesseG;
//}
