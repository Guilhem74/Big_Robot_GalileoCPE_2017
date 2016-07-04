#ifndef DEFINE_H
#define DEFINE_H
//Consigne du robot (En tick)
int L_consigne=10;
int A_consigne=0;

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
#define TEMPS_MIN_ASSERT 10// en ms
//Asservissement linéaire ****
#define P_LINEAIRE 0.01
#define I_LINEAIRE 0.0020*0
#define D_LINEAIRE 0.0020*0
float erreur_lineaire=0;
float Somme_erreur_lineaire=0;

//Asservissement linéaire ****
#define P_ANGULAIRE 0.1
#define I_ANGULAIRE 0.00
#define D_ANGULAIRE 0.00
float erreur_angulaire=0;
float Somme_erreur_angulaire=0;

#define P_VITESSE 4
#define I_VITESSE 0.5
#define D_VITESSE 0
float erreur_vitesseD=0;
float Somme_erreur_vitesseD=0;
float erreur_vitesseG=0;
float Somme_erreur_vitesseG=0;


//Valeur des codeuses
int32_t D=0;//Nbr de tick droite
int32_t G=0;//Nbr de tick gauche
int32_t D_ancien=0;//Ancien nbr de tick droite
int32_t G_ancien=0;//Ancien nbr de tick gauche

//Variable global
int32_t t_precedent=0;
int32_t t_actuel=0;
float delta_T=0;


int32_t vitesse_G=0;
int32_t vitesse_D=0;



float X_POS=0,Y_POS=0,ANGLE_POS=0;
float angle_radian=0;

#endif
