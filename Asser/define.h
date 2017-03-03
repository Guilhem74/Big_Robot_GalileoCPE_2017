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
bool MARCHE_ARRIERE=true;
bool close_to_goal=false;
bool At_goal=false;
int Compteur_stabilite_final=0;
int Compteur_stabilite_angulaire=0;
float X_POS=0,Y_POS=0,ANGLE_POS=0;
float angle_radian=0;
//Paramètre constant du robot
#define TICCODEUSES 1024 //Tick par tour de roue
#define ETAT_MOTEUR_AVANCE HIGH

//PINS
#define PIN_MOTEUR_GAUCHE_VITESSE 11
#define PIN_MOTEUR_GAUCHE_SENS 10
#define PIN_MOTEUR_DROITE_VITESSE 9
#define PIN_MOTEUR_DROITE_SENS    8

#define LIMIT_PWM_MAX 255
//Variable du robot
#define DIAMETRE_ROUE 41.25 //en mm
#define ECARTEMENT_ROUES 230//en mm
#define TICS2MM ((PI*DIAMETRE_ROUE)/(TICCODEUSES))
#define MM2TICS ((TICCODEUSES)/(PI*DIAMETRE_ROUE))

/*Variable de l'assert*********************************************/
#define DUREE_VALIDATION_ETAT_FINAL 10// Nombre de coup d'assert pour valider la position finale 
#define TOLERANCE_ANGLE 0.04
float Distance_moyenne =0;
float erreur_angle_radian=0;

#define TEMPS_MIN_ASSERT 10// en ms
//Asservissement linéaire ****
#define  P_LINEAIRE 0.05
#define I_LINEAIRE 0
#define D_LINEAIRE 0
float erreur_lineaire=0;
float erreur_precedente_lineaire=0;
float Somme_erreur_lineaire=0;

//Asservissement angulaire ****
#define P_ANGULAIRE 40
#define I_ANGULAIRE 0.1
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
int32_t Codeuse_Droite=0;//Nbr de tick droite
int32_t Codeuse_Gauche=0;//Nbr de tick gauche
int32_t Codeuse_Droite_PAST=0;//Ancien nbr de tick droite
int32_t Codeuse_Gauche_PAST=0;//Ancien nbr de tick gauche

//Variable global
int32_t t_precedent=0;
int32_t t_actuel=0;
float delta_T=0;
int32_t Temps_assert=0;

float vitesse_G=0;
float vitesse_D=0;

#endif
