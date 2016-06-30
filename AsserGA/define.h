#ifndef DEFINE_H
#define DEFINE_H

//Paramètre constant du robot
#define TICCODEUSES 1024 //Tick par tour de roue
#define ETAT_MOTEUR_AVANCE HIGH

//PINS
#define PIN_MOTEUR_GAUCHE_VITESSE 11
#define PIN_MOTEUR_GAUCHE_SENS 10
#define PIN_MOTEUR_DROITE_VITESSE 9
#define PIN_MOTEUR_DROITE_SENS    8


//Variable du robot
#define DIAMETRE_ROUE 41.25 //en mm
#define ECARTEMENT_ROUES 186 //en mm

/*Variable de l'assert*********************************************/
#define TEMPS_MIN_ASSERT 100 // en m
//Asservissement linéaire ****
#define P_lineaire 0.1
#define I_lineaire 0.0020
#define D_lineaire 0.0020
float erreur_lineaire=0;
float Somme_erreur_lineaire=0;

//Asservissement linéaire ****
#define P_angulaire 0.1
#define I_angulaire 0.0020
#define D_angulaire 0.0020
float erreur_angulaire=0;
float Somme_erreur_angulaire=0;

//Valeur des codeuses
int32_t D=0;//Nbr de tick droite
int32_t G=0;//Nbr de tick gauche
int32_t D_ancien=0;//Ancien nbr de tick droite
int32_t G_ancien=0;//Ancien nbr de tick gauche

//Variable global
int t_precedent=0;
int t_actuel=0;
float delta_T=0;


long vitesse_G=0;
long vitesse_D=0;

//Consigne du robot (En tick)
int L_consigne=4000;
int A_consigne=0;


float X_POS=0,Y_POS=0,ANGLE_POS=0;
float angle_radian=0;

#endif
