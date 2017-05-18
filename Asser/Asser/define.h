#ifndef DEFINE_H
#define DEFINE_H
/*Communication*/
#define SEPARATEUR ';'
#define NBR_ETAPE 4


bool Etat_bras_voulu = 0;
bool Etat_bras = 0;
int cnt = 0;                 // nombre de données découpées
String data[10];             // stockage des données découpées
bool stringComplete = false; // pour savoir si la chaine est complète
String inputString = "";     // chaine de caractères pour contenir les données
bool Chargeur_Pret=false;
int Quart=0;
int Quart_Reel=0;
float ANGLE_DEST = 0;
float angle_envoye_final = 0;
float Rampe_angle = 0;
float Rampe_distance = 0;
float X_POS = 0, Y_POS = 1070, ANGLE_POS = 90;
float X_DEST=X_POS, Y_DEST=Y_POS, ANGLE_FINAL=ANGLE_POS;
float angle_radian = ANGLE_POS * DEG_TO_RAD;
// Paramètre constant du robot
#define TICCODEUSES 1024 // Tick par tour de roue
#define ETAT_MOTEUR_AVANCE HIGH

// PINS
#define PIN_MOTEUR_GAUCHE_VITESSE 9
#define PIN_MOTEUR_GAUCHE_SENS 8
#define PIN_MOTEUR_DROITE_VITESSE 11
#define PIN_MOTEUR_DROITE_SENS 10

#define LIMIT_PWM_MAX 255
// Variable du robot
#define DIAMETRE_ROUE 41.25  // en mm
#define ECARTEMENT_ROUES 230 // en mm
#define TICS2MM ((PI * DIAMETRE_ROUE) / (TICCODEUSES))
#define MM2TICS ((TICCODEUSES) / (PI * DIAMETRE_ROUE))


#define TOLERANCE_ANGLE 0.2
float Distance_moyenne = 0;
float erreur_angle_radian = 0;

#define TEMPS_MIN_ASSERT 10 // en ms
// Asservissement linéaire ****
#define P_LINEAIRE 0.50
// 0.64 pour 40 .
#define I_LINEAIRE 0.015
#define D_LINEAIRE 0.000047
float erreur_lineaire = 0;
float erreur_precedente_lineaire = 0;

// Asservissement angulaire ****
#define P_ANGULAIRE 8//5
#define I_ANGULAIRE 10//5//0.95
#define D_ANGULAIRE 1800//1000
float erreur_angulaire = 0;
float erreur_precedente_angulaire = 0;


// Valeur des codeuses
int32_t Codeuse_Droite = 0;      // Nbr de tick droite
int32_t Codeuse_Gauche = 0;      // Nbr de tick gauche
int32_t Codeuse_Droite_PAST = 0; // Ancien nbr de tick droite
int32_t Codeuse_Gauche_PAST = 0; // Ancien nbr de tick gauche

int32_t Temps_Base_Systeme=0;
int32_t Temps_assert = 0;
int32_t Temp_debut_match=0;
#define TEMPS_MATCH 90000
#define COEFF_RAMP_ANG 0.001
#define COEFF_RAMP_ANG_FINAL 0.001
#define COEFF_RAMP_LINEAIRE 0.001
#define TAILLE_TABLEAU_SOMME 50
#define TAILLE_TABLEAU_SOMME_ANGULAIRE 10
#define SEUIL_I_LINEAIRE 125
#define SEUIL_I_ANGULAIRE 50000//1000//700
float Somme_Erreur_Lin[TAILLE_TABLEAU_SOMME]={};
float Somme_Erreur_Ang[TAILLE_TABLEAU_SOMME]={};
  bool New_moove_angle = true;
  bool New_moove_distance = false;
  bool New_moove_angle_final = false;
  bool premier_passage = false;
  bool Consigne_termine=false;

enum Etat_Robot{ Prechauff, En_Route,Fin};
enum Type_Action {Deplacement, Pince_V, Pince_H, Chargeur_Cylindre,Bras};
enum Deplacement {Detection_Active, Detection_Inactive};
enum Pince_V_Action{Pince_V_UP,Pince_V_DOWN,Pince_V_Bourrage};
enum Pince_H_Action{Pince_H_Serre,Pince_H_Pousse,Pince_H_Desserre,Pince_H_Droite_Desserre,Pince_H_Gauche_Desserre};
enum Bras_Action{Bras_Retracte,Bras_Pousse};
enum Chargeur_Cylindre_Action{Chargeur_UP, Chargeur_Down};
Etat_Robot Robot_Principal=Prechauff;

 struct Consigne {
  Type_Action Action=Deplacement;

  float X_DEST = X_POS, Y_DEST = Y_POS, ANGLE_FINAL = ANGLE_POS;
  int32_t TimeOut=-1;//En ms
  int Information_Supplementaire=Detection_Active;
  bool Derniere_Consigne=false;
  Consigne *consigne_suivante = NULL;
  Consigne(Type_Action Action2,int32_t Time, int Inf):Action(Action2), TimeOut(Time),Information_Supplementaire((int)Inf),Derniere_Consigne(true){}
  Consigne(Type_Action Action2,int32_t Time, int Inf,Consigne *Next ):Action(Action2), TimeOut(Time),Information_Supplementaire((int)Inf),Derniere_Consigne(false),consigne_suivante(Next) {}
  Consigne(): Action( Deplacement), X_DEST(X_POS),Y_DEST(Y_POS),ANGLE_FINAL(ANGLE_POS) {}
  Consigne(float X,float Y,float A,Consigne *Next ):Action( Deplacement),X_DEST(X),Y_DEST(Y),ANGLE_FINAL(A),Derniere_Consigne(false),consigne_suivante(Next) {}
  Consigne(float X,float Y,float A ):Action(Deplacement),X_DEST(X),Y_DEST(Y),ANGLE_FINAL(A),Derniere_Consigne(true) {}
};
//RAZ des Tableaux et des news moove
/*
float Somme_Erreur_Lin[TAILLE_TABLEAU_SOMME]={};
float Somme_Erreur_Ang[TAILLE_TABLEAU_SOMME]={};
  bool New_moove_angle = true;
  bool New_moove_distance = false;
  bool New_moove_angle_final = false;
  bool premier_passage = false;
  bool Consigne_termine=false,*/
Consigne *Consigne_Actuel;
Consigne ConsigneTemp;

float DELTA_Consigne_Init=0;

//ACTIONNEUR

#define GPIO_PINCE_SERRAGE_DROITE 4
#define GPIO_PINCE_SERRAGE_GAUCHE 2
#define GPIO_PINCE_LEVAGE_DROITE 3
#define GPIO_PINCE_LEVAGE_GAUCHE 5
#define GPIO_FUNNY_ACTION 12

#define GPIO_TIRRETTE 22
#define GPIO_COULEUR_JAUNE 26
#define GPIO_COULEUR_BLEU 24


#define Servo_S_D_OPEN 70
#define Servo_S_G_OPEN 100
#define Servo_S_D_CLOSE 168
#define Servo_S_G_CLOSE 10
#define Servo_S_D_UP 165
#define Servo_S_G_UP 1
#define Servo_S_D_DOWN 73
#define Servo_S_G_DOWN 77
#define Servo_S_D_BOURRE 100
#define Servo_S_G_BOURRE 60

#define Servo_S_D_WAIT 150
#define Servo_S_G_WAIT 45
#define GPIO_Fourche_Optique 45

#define Fin_Course_Retracte 51
#define Fin_Course_Pousse 53

#define PIN_Chargeur_Cylindre_DIR 49
#define PIN_Chargeur_Cylindre_PWM 7
#define Vitesse_MIN_Chargeur_Cylindre 80
#define PIN_Bras_DIR 47
#define PIN_Bras_PWM 6
#define VITESSE_BRAS_AVANCE 220
#define VITESSE_BRAS_RECULE 220
#define ETAT_BRAS_AVANCE HIGH
#define ETAT_BRAS_RECULE LOW
//Consigne Consigne1 = {Deplacement,400,1070,90,-1,Detection_Active,true,NULL};
//Consigne Consigne1 = {.Type_Action=Deplacement,.X_DEST=400,.Y_DEST=1070,.ANGLE_FINAL=90,.TimeOut=-1,.Information_Supplementaire=1,.Derniere_Consigne=true,.consigne_suivante=&ConsigneTemp};
#endif
