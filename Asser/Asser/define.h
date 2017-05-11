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



float ANGLE_DEST = 0;
float angle_envoye_final = 0;
float Rampe_angle = 0;
float Rampe_distance = 0;
float X_POS = 0, Y_POS = 1070, ANGLE_POS = 90;
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

/*Variable de l'assert*********************************************/
#define DUREE_VALIDATION_ETAT_FINAL                                            \
  \
10 // Nombre de coup d'assert pour valider la position finale
#define TOLERANCE_ANGLE 0.2
float Distance_moyenne = 0;
float erreur_angle_radian = 0;

#define TEMPS_MIN_ASSERT 10 // en ms
// Asservissement linéaire ****
#define P_LINEAIRE 0.39

#define I_LINEAIRE 0.0065
#define D_LINEAIRE 0.001
float erreur_lineaire = 0;
float erreur_precedente_lineaire = 0;

// Asservissement angulaire ****
#define P_ANGULAIRE 42
#define I_ANGULAIRE 0.04
#define D_ANGULAIRE 0.04
float erreur_angulaire = 0;
float erreur_precedente_angulaire = 0;


// Valeur des codeuses
int32_t Codeuse_Droite = 0;      // Nbr de tick droite
int32_t Codeuse_Gauche = 0;      // Nbr de tick gauche
int32_t Codeuse_Droite_PAST = 0; // Ancien nbr de tick droite
int32_t Codeuse_Gauche_PAST = 0; // Ancien nbr de tick gauche

// Variable global
int32_t t_precedent = 0;
int32_t t_actuel = 0;
float delta_T = 0;
int32_t Temps_assert = 0;

float vitesse_G = 0;
float vitesse_D = 0;
#define COEFF_RAMP_ANG 0.001
#define COEFF_RAMP_ANG_FINAL 0.001
#define COEFF_RAMP_LINEAIRE 0.001
#define TAILLE_TABLEAU_SOMME 50
#define SEUIL_I_LINEAIRE 125
struct Consigne {
  float P_ang = P_ANGULAIRE, I_ang = I_ANGULAIRE, D_ang = D_ANGULAIRE;
  float P_lin = P_LINEAIRE, I_lin = I_LINEAIRE, D_lin = D_LINEAIRE;
  float Somme_Erreur_Lin[TAILLE_TABLEAU_SOMME]={},Somme_Erreur_Ang[TAILLE_TABLEAU_SOMME]={};
  float X_DEST = X_POS, Y_DEST = Y_POS;
  float ANGLE_FINAL = ANGLE_POS;
  float coeff_ramp_lin = COEFF_RAMP_LINEAIRE, coeff_ramp_ang = COEFF_RAMP_ANG, Rampe_angle_final=COEFF_RAMP_ANG_FINAL;
  bool New_moove_angle = true;
  bool New_moove_distance = false;
  bool New_moove_angle_final = false;
  bool premier_passage = false;
  bool Consigne_termine=false, Derniere_Consigne=false;
  Consigne *consigne_suivante = NULL;
};
Consigne *Consigne_Actuel;
Consigne ConsigneTemp;
Consigne Consigne[NBR_ETAPE];
float DELTA_Consigne_Init=0;
#endif
