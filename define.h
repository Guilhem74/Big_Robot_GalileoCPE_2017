#define TEMPS_MIN_ASSERT 50
  #define PIN_MOTEUR_DROITE_VITESSE 9
  #define PIN_MOTEUR_DROITE_SENS    8
  #define PIN_MOTEUR_GAUCHE_VITESSE 11
  #define PIN_MOTEUR_GAUCHE_SENS 10
 #define TIC_CODEUSES 1024
 #define DIAMETRE_ROUE 41.25
 
    #define TICCODEUSE 1024 //Tick par tour de roue
  #define ETAT_MOTEUR_AVANCE HIGH
    #define ECARTEMENT_ROUES 186 //en mm
  int32_t D=0;
int32_t G=0;
int32_t D_ancien=0;
int32_t G_ancien=0;
int t_precedent=0;
int t_actuel=0;
float delta_T=0;
 long vitesse_G=0;
 long vitesse_D=0;
int L_consigne=4000;
int A_consigne=0;
float erreur_lineaire=0;
float Somme_erreur_lineaire=0;
float erreur_angulaire=0;
float Somme_erreur_angulaire=0;
float X_POS=0,Y_POS=0,ANGLE_POS=0;
float angle_radian=0;
