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
  Somme_Erreur_Lin[i%TAILLE_TABLEAU_SOMME]= erreur_lineaire;         // I
  float Somme_Erreur_Lineaire_Local=0;
  for(int j=0;j<TAILLE_TABLEAU_SOMME;j++)
  {
    Somme_Erreur_Lineaire_Local+=  Somme_Erreur_Lin[j%TAILLE_TABLEAU_SOMME];
  }
  i++;
  if(I_LINEAIRE * Somme_Erreur_Lineaire_Local>SEUIL_I_LINEAIRE/TAILLE_TABLEAU_SOMME) Somme_Erreur_Lineaire_Local=SEUIL_I_LINEAIRE/(TAILLE_TABLEAU_SOMME*I_LINEAIRE);
  else if(I_LINEAIRE * Somme_Erreur_Lineaire_Local<-SEUIL_I_LINEAIRE/TAILLE_TABLEAU_SOMME) Somme_Erreur_Lineaire_Local=-SEUIL_I_LINEAIRE/(TAILLE_TABLEAU_SOMME*I_LINEAIRE);
  float Commande_lineaire =
      P_LINEAIRE * erreur_lineaire + I_LINEAIRE * Somme_Erreur_Lineaire_Local  +
      D_LINEAIRE * delta_erreur_lineaire; // On determine la commande a envoyer

  return Commande_lineaire;
}

float asservissement_angulaire(float Consigne) {
  // erreur_angle_radian
  erreur_precedente_angulaire = erreur_angulaire;
  erreur_angulaire = Consigne;
  float delta_erreur_angulaire =
      erreur_angulaire - erreur_precedente_angulaire; // D
      static int32_t i=0;
  Somme_Erreur_Ang[i%TAILLE_TABLEAU_SOMME]= erreur_angulaire;         // I
  float Somme_Erreur_Angulaire_Local=0;
  for(int j=0;j<TAILLE_TABLEAU_SOMME;j++)
  {
    Somme_Erreur_Angulaire_Local+= Somme_Erreur_Ang[j%TAILLE_TABLEAU_SOMME];
  }
  i++;
  float Commande_angulaire = erreur_angulaire * P_ANGULAIRE +
                             I_ANGULAIRE * Somme_Erreur_Angulaire_Local +
                             D_ANGULAIRE * delta_erreur_angulaire; // PID
  return Commande_angulaire;
}
void Arreter_Robot()
{

  analogWrite(PIN_MOTEUR_DROITE_VITESSE, 0);
  analogWrite(PIN_MOTEUR_GAUCHE_VITESSE, 0);
  analogWrite(PIN_Chargeur_Cylindre_PWM, 0);
  analogWrite(PIN_Bras_PWM, 0);
}
