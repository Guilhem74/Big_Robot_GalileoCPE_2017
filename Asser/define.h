#ifndef DEFINE_H
#define DEFINE_H
/*Communication*/
#define SEPARATEUR ';'
int cnt = 0; // nombre de données découpées
String data[10]; // stockage des données découpées
bool stringComplete = false;  // pour savoir si la chaine est complète
String inputString = "";   // chaine de caractères pour contenir les données

//Consigne du robot (En tick)
int L_consigne=0;
int A_consigne=0;
int angle_robot=0;

float X_DEST=0,Y_DEST=0,ANGLE_DEST=0,ANGLE_FINAL=0;
bool MARCHE_ARRIERE=false;
bool close_to_goal=false;
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
#define TICS2MM ((PI*DIAMETRE_ROUE)/(TICCODEUSES))
#define MM2TICS ((TICCODEUSES)/(PI*DIAMETRE_ROUE))
#define RAD2DEG 360/(2*PI)
#define DEG2RAD (2*PI)/360
/*Variable de l'assert*********************************************/


float Distance_moyenne =0;
float erreur_angle_radian=0;

#define TEMPS_MIN_ASSERT 10// en ms
//Asservissement linéaire ****
#define P_LINEAIRE 0.04
#define I_LINEAIRE 0.000025
#define D_LINEAIRE 0
float erreur_lineaire=0;
float erreur_precedente_lineaire=0;
float Somme_erreur_lineaire=0;

//Asservissement angulaire ****
#define P_ANGULAIRE 150
#define I_ANGULAIRE 0.00
#define D_ANGULAIRE 0.00
float erreur_angulaire=0;
float Somme_erreur_angulaire=0;
float erreur_precedente_angulaire=0;

//Asservissement vitesse ****
#define P_VITESSE 2
#define I_VITESSE 0
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


float vitesse_G=0;
float vitesse_D=0;



float X_POS=0,Y_POS=0,ANGLE_POS=0;
float angle_radian=0;

#endif
