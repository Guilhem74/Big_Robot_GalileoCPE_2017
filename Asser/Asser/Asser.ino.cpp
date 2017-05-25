# 1 "c:\\users\\guilhem\\appdata\\local\\temp\\tmpwnal4r"
#include <Arduino.h>
# 1 "F:/Guilhem/Documents/GitHub/ProjetRobot2017/Asser/Asser/Asser.ino"
#include <Arduino.h>

#include "define.h"
# 13 "F:/Guilhem/Documents/GitHub/ProjetRobot2017/Asser/Asser/Asser.ino"
char Info[40] = {};
void setup();
void loop();
void Setup_Actionneur();
void Pince_CLOSE();
void Pince_UP();
void Pince_OPEN();
void Pince_D_OPEN();
void Pince_G_OPEN();
void Pince_DOWN();
void Pince_WAIT();
void Pince_V_Bourre();
void Pince_H_Decharge();
void ACTIVER_FUNNY_ACTION();
void DESACTIVER_FUNNY_ACTION();
void Pince_V_Pousse_Action();
void Mise_a_jour_bras();
void Mise_A_Jour_Tirette();
void Lecture_Fourche_Optique();
void splitString(String message, char separator, String *data);
void Reception();
void Traitement();
void serialEvent();
void Tourner_Moteur_D();
void Droit_Au_But();
void Je_Paye_Ma_Tournee();
void Tourner_Moteur_G();
void Plz_Share_What_U_Know_About_Encoder();
void Where_Is_Robot();
void Are_U_Wrong();
void asservissement_robot(float Consigne_Lin, float Consigne_Ang);
float asservissement_lineaire(float Consigne);
float asservissement_angulaire(float Consigne);
void Arreter_Robot();
void recuperer(byte A);
void mise_a_jour_robot();
void mise_a_jour_POS();
void calcul_erreur();
void Routine_Robot();
void Mise_A_Jour_Action_Robot();
void Setup_Commande();
void setup_asservissement();
void initialisation_variables();
#line 15 "F:/Guilhem/Documents/GitHub/ProjetRobot2017/Asser/Asser/Asser.ino"
void setup() {
DESACTIVER_FUNNY_ACTION();
  Setup_Actionneur();

  setup_asservissement();
  Setup_Commande();

  Pince_CLOSE();
Pince_UP();
  Quart=1;
  delay(100);
  Etat_bras_voulu=0;

}

void loop() {
  Where_Is_Robot();
  if( Robot_Principal==Prechauff)
    {
        Mise_A_Jour_Tirette();

        Temp_debut_match=millis();
        Temps_Base_Systeme=millis();

    }
    else
    {
      if( millis()-Temp_debut_match > TEMPS_MATCH)
      {
        Robot_Principal=Fin;
        Serial.println("Fin du match");
        ACTIVER_FUNNY_ACTION();

        Arreter_Robot();
        while(1);
      }
      else if( Robot_Principal!= Fin)
      {
        Routine_Robot();

      }
      if(Robot_Principal== Fin)
        Arreter_Robot();


    }


}
# 1 "F:/Guilhem/Documents/GitHub/ProjetRobot2017/Asser/Asser/Actionneur.ino"
#include <Arduino.h>
#include <Servo.h>
Servo Servo_S_D;
Servo Servo_S_G;
Servo Servo_L_D;
Servo Servo_L_G;
Servo Servo_Funny;
void Setup_Actionneur() {
  Servo_S_D.attach(GPIO_PINCE_SERRAGE_DROITE);
  Servo_S_G.attach(GPIO_PINCE_SERRAGE_GAUCHE);
  Servo_L_D.attach(GPIO_PINCE_LEVAGE_DROITE);
  Servo_L_G.attach(GPIO_PINCE_LEVAGE_GAUCHE);
  Servo_Funny.attach(GPIO_FUNNY_ACTION);
  pinMode(Fin_Course_Retracte, INPUT_PULLUP);
  pinMode(Fin_Course_Pousse, INPUT_PULLUP);
  pinMode(PIN_Chargeur_Cylindre_DIR, OUTPUT);
  pinMode(PIN_Chargeur_Cylindre_PWM, OUTPUT);
  pinMode(PIN_Bras_DIR, OUTPUT);
  pinMode(PIN_Bras_PWM, OUTPUT);
  pinMode(GPIO_Fourche_Optique,INPUT);
  pinMode(GPIO_TIRRETTE,INPUT);
  pinMode(GPIO_COULEUR_BLEU,INPUT);
  pinMode(GPIO_COULEUR_JAUNE,INPUT);
  digitalWrite(PIN_Chargeur_Cylindre_DIR, LOW);
  analogWrite(PIN_Chargeur_Cylindre_PWM, 0);
# 40 "F:/Guilhem/Documents/GitHub/ProjetRobot2017/Asser/Asser/Actionneur.ino"
}
void Pince_CLOSE() {
  Servo_S_D.write(Servo_S_D_CLOSE);
  Servo_S_G.write(Servo_S_G_CLOSE);
}
void Pince_UP() {
  Servo_L_D.write(Servo_S_D_UP);
  Servo_L_G.write(Servo_S_G_UP);
}

void Pince_OPEN() {
  Pince_D_OPEN();
  Pince_G_OPEN();
}
void Pince_D_OPEN() {
  Servo_S_D.write(Servo_S_D_OPEN);
}
void Pince_G_OPEN() {
  Servo_S_G.write(Servo_S_G_OPEN);
}
void Pince_DOWN() {
  Servo_L_D.write(Servo_S_D_DOWN);
  Servo_L_G.write(Servo_S_G_DOWN);
}

void Pince_WAIT() {
  Servo_S_D.write(Servo_S_D_WAIT);
  Servo_S_G.write(Servo_S_G_WAIT);
}

void Pince_V_Bourre(){
  Servo_L_D.write(Servo_S_D_BOURRE);
  Servo_L_G.write(Servo_S_G_BOURRE);
}
void Pince_H_Decharge(){
  Servo_S_D.write(Servo_S_D_Decharge);
  Servo_S_G.write(Servo_S_G_Decharge);
}
void ACTIVER_FUNNY_ACTION(){
  Servo_Funny.write(80);
}
void DESACTIVER_FUNNY_ACTION(){
  Servo_Funny.write(50);
}
void Pince_V_Pousse_Action()
{
  Servo_L_D.write(Servo_S_D_POUSSE);
  Servo_L_G.write(Servo_S_G_POUSSE);
}
void Mise_a_jour_bras() {

  if (digitalRead(Fin_Course_Pousse) == LOW && Etat_bras_voulu == 1) {
    Etat_bras = 1;
    analogWrite(PIN_Bras_PWM, 0);
  } else if (digitalRead(Fin_Course_Pousse) == HIGH && Etat_bras_voulu == 1) {
    digitalWrite(PIN_Bras_DIR, ETAT_BRAS_AVANCE);
    analogWrite(PIN_Bras_PWM, VITESSE_BRAS_AVANCE);
  } else if (digitalRead(Fin_Course_Retracte) == HIGH && Etat_bras_voulu == 0) {
    digitalWrite(PIN_Bras_DIR, ETAT_BRAS_RECULE);
    analogWrite(PIN_Bras_PWM, VITESSE_BRAS_RECULE);
  } else if (digitalRead(Fin_Course_Retracte) == LOW && Etat_bras_voulu == 0) {
    Etat_bras = 0;
    analogWrite(PIN_Bras_PWM, 0);
  }




  if( Chargeur_Pret==false&& Consigne_Actuel->Action==Chargeur_Cylindre)
  {
    digitalWrite(PIN_Chargeur_Cylindre_DIR,LOW);
    analogWrite(PIN_Chargeur_Cylindre_PWM, Vitesse_MIN_Chargeur_Cylindre);
    Compteur_Fourche_Optique++;
  }
  else
  {
    Compteur_Fourche_Optique=0;
    digitalWrite(PIN_Chargeur_Cylindre_DIR,HIGH);
    analogWrite(PIN_Chargeur_Cylindre_PWM, 2);
  }

}
Mise_a_jour_detection(){
  Obstacle_devant=digitalRead(GPIO_DETECTION_AVANT);
  Serial.print(Obstacle_devant);
  Serial.print(" ");

  Obstacle_derriere=digitalRead(GPIO_DETECTION_ARRIERE);
  Serial.println(Obstacle_derriere);

}
void Mise_A_Jour_Tirette()
{

  if(digitalRead(GPIO_TIRRETTE)==HIGH)
  {

    if(digitalRead(GPIO_COULEUR_JAUNE)==LOW)
    {


    }
    else if(digitalRead(GPIO_COULEUR_BLEU)==LOW)
    {


    }
    Robot_Principal=En_Route;
  }
}
void Lecture_Fourche_Optique()
{
  static bool Etat_Actuel=HIGH;
  static bool Etat_Precedent=HIGH;
  Etat_Actuel=digitalRead(GPIO_Fourche_Optique);
  if(Etat_Actuel!=Etat_Precedent&&Etat_Precedent==HIGH&& Compteur_Fourche_Optique>8)
  {
  Chargeur_Pret=true;
  Compteur_Fourche_Optique=0;
  digitalWrite(PIN_Chargeur_Cylindre_DIR,HIGH);
  analogWrite(PIN_Chargeur_Cylindre_PWM, 2);
  }
  Etat_Precedent=Etat_Actuel;
}
# 1 "F:/Guilhem/Documents/GitHub/ProjetRobot2017/Asser/Asser/Commande.ino"
#include "define.h"
# 1 "F:/Guilhem/Documents/GitHub/ProjetRobot2017/Asser/Asser/Communication.ino"
#include <Arduino.h>

void splitString(String message, char separator, String *data) {
  int index = 0;
  inputString = "";
  stringComplete = false;
  for (int i = 0; i < 10; i++) {
    data[i] = "";
  }
  cnt = 0;
  do {
    index = message.indexOf(separator);
    if (index != -1) {

      data[cnt] = message.substring(0, index);
      cnt++;

      message = message.substring(index + 1, message.length());
    } else {


      if (message.length() > 0) {

        data[cnt] = message.substring(0, index);
        cnt++;
      }
    }
  } while (index >= 0);
}

void Reception() {
  if (stringComplete) {




    splitString(inputString, SEPARATEUR, data);







    Traitement();
  }
}
void Traitement() {
  if (data[0].equals("XYA")) {
    ConsigneTemp.X_DEST = (float)data[1].toInt();
    ConsigneTemp.Y_DEST = (float)data[2].toInt();
    ConsigneTemp.ANGLE_FINAL = (float)data[3].toInt();
   New_moove_angle = true;
   for(int i=0;i<TAILLE_TABLEAU_SOMME;i++)
   {
     Somme_Erreur_Lin[i]=0;
     Somme_Erreur_Ang[i]=0;
   }

    New_moove_angle = true;
    New_moove_distance = false;
    New_moove_angle_final = false;
    premier_passage = false;

  erreur_precedente_lineaire=0;
  erreur_lineaire=0;
  erreur_precedente_angulaire=0;
  erreur_angulaire=0;

  Rampe_distance = 0;
   ConsigneTemp.Derniere_Consigne=true;
    ConsigneTemp.consigne_suivante=&ConsigneTemp;

  }
  if (data[0].equals("A")) {
    ConsigneTemp.X_DEST = (float)data[1].toInt()+X_POS;
    ConsigneTemp.Y_DEST = (float)data[2].toInt()+Y_POS;
   for(int i=0;i<TAILLE_TABLEAU_SOMME;i++)
   {
     Somme_Erreur_Lin[i]=0;
     Somme_Erreur_Ang[i]=0;
   }

    New_moove_angle = true;
    New_moove_distance = false;
    New_moove_angle_final = false;
    premier_passage = false;
    ConsigneTemp.Derniere_Consigne=true;
    ConsigneTemp.consigne_suivante=&ConsigneTemp;


erreur_precedente_lineaire=0;
erreur_lineaire=0;
erreur_precedente_angulaire=0;
erreur_angulaire=0;

  Rampe_distance = 0;
  Consigne_Actuel=&ConsigneTemp;
  }
}

void serialEvent() {

  while (Serial.available()) {



    char inChar = (char)Serial.read();



    if (inChar == '\n') {

      stringComplete = true;

    } else {

      inputString += inChar;

    }

  }

}
# 1 "F:/Guilhem/Documents/GitHub/ProjetRobot2017/Asser/Asser/Fonction_test.ino"
#include <Arduino.h>

#define VITESSE_TEST 255

void Tourner_Moteur_D() {

  Serial.println("Moteur Droit avance \n");
  delay(1000);
  digitalWrite(PIN_MOTEUR_DROITE_SENS, ETAT_MOTEUR_AVANCE);
  delayMicroseconds(10);
  analogWrite(PIN_MOTEUR_DROITE_VITESSE, VITESSE_TEST);
  delay(1000);
  analogWrite(PIN_MOTEUR_DROITE_VITESSE, 0);
  Serial.println("Moteur Droit Recule \n");
  delay(1000);
  digitalWrite(PIN_MOTEUR_DROITE_SENS, !ETAT_MOTEUR_AVANCE);
  delayMicroseconds(10);
  analogWrite(PIN_MOTEUR_DROITE_VITESSE, VITESSE_TEST);
  delay(1000);
  analogWrite(PIN_MOTEUR_DROITE_VITESSE, 0);
}
void Droit_Au_But() {

  Serial.println("Moteur Droit & gauche avance \n");
  Serial.println("Test de ligne droite \n");
  delay(1000);
  digitalWrite(PIN_MOTEUR_DROITE_SENS, ETAT_MOTEUR_AVANCE);
  digitalWrite(PIN_MOTEUR_GAUCHE_SENS, ETAT_MOTEUR_AVANCE);

  delayMicroseconds(10);
  analogWrite(PIN_MOTEUR_DROITE_VITESSE, VITESSE_TEST);
  analogWrite(PIN_MOTEUR_GAUCHE_VITESSE, VITESSE_TEST);

  delay(4000);
  analogWrite(PIN_MOTEUR_DROITE_VITESSE, 0);
  analogWrite(PIN_MOTEUR_GAUCHE_VITESSE, 0);
}
void Je_Paye_Ma_Tournee() {

  Serial.println("Moteur Droit avance & gauche recule \n");
  Serial.println("Test  de rotation \n");
  delay(1000);
  digitalWrite(PIN_MOTEUR_DROITE_SENS, ETAT_MOTEUR_AVANCE);
  digitalWrite(PIN_MOTEUR_GAUCHE_SENS, !ETAT_MOTEUR_AVANCE);

  delayMicroseconds(10);
  analogWrite(PIN_MOTEUR_DROITE_VITESSE, VITESSE_TEST / 8);
  analogWrite(PIN_MOTEUR_GAUCHE_VITESSE, VITESSE_TEST / 8);

  delay(4000);
  analogWrite(PIN_MOTEUR_DROITE_VITESSE, 0);
  analogWrite(PIN_MOTEUR_GAUCHE_VITESSE, 0);
}

void Tourner_Moteur_G() {
  Serial.println("Moteur gauche avance \n");
  delay(1000);
  digitalWrite(PIN_MOTEUR_GAUCHE_SENS, ETAT_MOTEUR_AVANCE);
  delayMicroseconds(10);
  analogWrite(PIN_MOTEUR_GAUCHE_VITESSE, VITESSE_TEST);
  delay(1000);
  analogWrite(PIN_MOTEUR_GAUCHE_VITESSE, 0);
  Serial.println("Moteur gauche Recule \n");
  delay(1000);
  digitalWrite(PIN_MOTEUR_GAUCHE_SENS, !ETAT_MOTEUR_AVANCE);
  delayMicroseconds(10);
  analogWrite(PIN_MOTEUR_GAUCHE_VITESSE, VITESSE_TEST);
  delay(1000);
  analogWrite(PIN_MOTEUR_GAUCHE_VITESSE, 0);
}

void Plz_Share_What_U_Know_About_Encoder() {
  Serial.print("D: ");
  Serial.print(Codeuse_Droite);
  Serial.print("  ");
  Serial.print("G: ");
  Serial.println(Codeuse_Gauche);
}

void Where_Is_Robot() {
  Serial.print("X: ");
  Serial.print(X_POS);
  Serial.print("   ");
  Serial.print("Y: ");
  Serial.print(Y_POS);
  Serial.print("O: ");
  Serial.println(ANGLE_POS);
}

void Are_U_Wrong() {
  Serial.print("Distance: ");
  Serial.print(Distance_moyenne);
  Serial.print("   ");
  Serial.print("Erreur_Angle: ");
  Serial.print(erreur_angle_radian * RAD_TO_DEG);
  Serial.println("");
}
# 1 "F:/Guilhem/Documents/GitHub/ProjetRobot2017/Asser/Asser/fonction_asservissement.ino"
#include <Arduino.h>



void asservissement_robot(float Consigne_Lin, float Consigne_Ang) {

  float Commande_Lin = asservissement_lineaire(Consigne_Lin);

  float Commande_Ang = asservissement_angulaire(Consigne_Ang);

  if(Commande_Lin>160) Commande_Lin=160;

  if(Commande_Lin<-160) Commande_Lin=-160;



  float Commande_D = Commande_Lin + Commande_Ang;

  float Commande_G = Commande_Lin - Commande_Ang;







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





  digitalWrite(PIN_MOTEUR_DROITE_SENS, sens_D);

  digitalWrite(PIN_MOTEUR_GAUCHE_SENS, sens_G);

  delayMicroseconds(10);

  analogWrite(PIN_MOTEUR_DROITE_VITESSE, Commande_D);

  analogWrite(PIN_MOTEUR_GAUCHE_VITESSE, Commande_G);



}

float asservissement_lineaire(float Consigne) {

  erreur_precedente_lineaire =

      erreur_lineaire;

  erreur_lineaire = Consigne;



  float delta_erreur_lineaire =

      erreur_lineaire - erreur_precedente_lineaire;

      static int32_t i=0;

  Somme_Erreur_Lin[i%TAILLE_TABLEAU_SOMME]= erreur_lineaire;

  float Somme_Erreur_Lineaire_Local=0;

  for(int j=0;j<TAILLE_TABLEAU_SOMME;j++)

  {

    Somme_Erreur_Lineaire_Local+= Somme_Erreur_Lin[j%TAILLE_TABLEAU_SOMME];

  }

  i++;

  if(I_LINEAIRE * Somme_Erreur_Lineaire_Local>SEUIL_I_LINEAIRE/TAILLE_TABLEAU_SOMME) Somme_Erreur_Lineaire_Local=(float)SEUIL_I_LINEAIRE/(TAILLE_TABLEAU_SOMME*I_LINEAIRE);

  else if(I_LINEAIRE * Somme_Erreur_Lineaire_Local<-SEUIL_I_LINEAIRE/TAILLE_TABLEAU_SOMME) Somme_Erreur_Lineaire_Local=-(float)SEUIL_I_LINEAIRE/(TAILLE_TABLEAU_SOMME*I_LINEAIRE);

  float Commande_lineaire =

      P_LINEAIRE * erreur_lineaire + I_LINEAIRE * Somme_Erreur_Lineaire_Local +

      D_LINEAIRE * delta_erreur_lineaire;



  return Commande_lineaire;

}



float asservissement_angulaire(float Consigne) {



  erreur_precedente_angulaire = erreur_angulaire;

  erreur_angulaire = Consigne;

  float delta_erreur_angulaire =

      erreur_angulaire - erreur_precedente_angulaire;

      static int32_t i=0;

  Somme_Erreur_Ang[i%TAILLE_TABLEAU_SOMME_ANGULAIRE]= erreur_angulaire;

  float Somme_Erreur_Angulaire_Local=0;

  for(int j=0;j<TAILLE_TABLEAU_SOMME_ANGULAIRE;j++)

  {

    Somme_Erreur_Angulaire_Local+= Somme_Erreur_Ang[j%TAILLE_TABLEAU_SOMME_ANGULAIRE];

  }

  i++;

  if(I_ANGULAIRE * Somme_Erreur_Angulaire_Local>SEUIL_I_ANGULAIRE/TAILLE_TABLEAU_SOMME_ANGULAIRE) Somme_Erreur_Angulaire_Local=(float) SEUIL_I_ANGULAIRE/(TAILLE_TABLEAU_SOMME_ANGULAIRE*I_ANGULAIRE);

  else if(I_ANGULAIRE * Somme_Erreur_Angulaire_Local<-SEUIL_I_ANGULAIRE/TAILLE_TABLEAU_SOMME_ANGULAIRE){ Somme_Erreur_Angulaire_Local=- (float)SEUIL_I_ANGULAIRE/(TAILLE_TABLEAU_SOMME_ANGULAIRE*I_ANGULAIRE);}

  float Commande_angulaire = erreur_angulaire * P_ANGULAIRE +

                             I_ANGULAIRE * Somme_Erreur_Angulaire_Local +

                             D_ANGULAIRE * delta_erreur_angulaire;



  return Commande_angulaire;

}

void Arreter_Robot()

{



  analogWrite(PIN_MOTEUR_DROITE_VITESSE, 0);

  analogWrite(PIN_MOTEUR_GAUCHE_VITESSE, 0);

  analogWrite(PIN_Chargeur_Cylindre_PWM, 0);

  analogWrite(PIN_Bras_PWM, 0);

}
# 1 "F:/Guilhem/Documents/GitHub/ProjetRobot2017/Asser/Asser/fonction_codeuse.ino"
#include <Arduino.h>

void recuperer(byte A) {

  String inputString_Codeuse = "";
  String data_Codeuse[10];
  bool fini = true;
  Serial3.print("C\n");

  while (Serial3.available() && fini) {
    char inChar = (char)Serial3.read();

    if (inChar == '\n') {

      splitString(inputString_Codeuse, SEPARATEUR, data_Codeuse);
      Codeuse_Droite = data_Codeuse[1].toInt();
      Codeuse_Gauche = -data_Codeuse[2].toInt();

      fini = false;

    } else
    inputString_Codeuse += inChar;
  }
}
# 1 "F:/Guilhem/Documents/GitHub/ProjetRobot2017/Asser/Asser/fonction_robot.ino"
#include <Arduino.h>

#include "define.h"

void mise_a_jour_robot()

{



Codeuse_Droite_PAST=Codeuse_Droite;

Codeuse_Gauche_PAST=Codeuse_Gauche;



recuperer(0);

recuperer(1);





mise_a_jour_POS();

}

void mise_a_jour_POS()

{

  float delta_D = (Codeuse_Droite_PAST - Codeuse_Droite)*TICS2MM;

  float delta_G = (Codeuse_Gauche_PAST - Codeuse_Gauche)*TICS2MM;

  float localX = 0, localY = 0;

  localY = (float)(((delta_D + delta_G) / 2.0f) * cos(angle_radian +(delta_D - delta_G) / (2* ECARTEMENT_ROUES)));

  localX = (float)(((delta_D + delta_G) / 2.0f) * sin(angle_radian +(delta_D - delta_G) / (2* ECARTEMENT_ROUES)));

  angle_radian += ((float)(delta_D - delta_G) / ECARTEMENT_ROUES);



  X_POS += localX;

  Y_POS -= localY;

  ANGLE_POS = (angle_radian * RAD_TO_DEG);



}

void calcul_erreur()

{

   float dx=X_DEST-X_POS;

   float dy=Y_DEST-Y_POS;

   if(dx==0)

   {

     dx=0.00001;

   }
# 83 "F:/Guilhem/Documents/GitHub/ProjetRobot2017/Asser/Asser/fonction_robot.ino"
static int cpt=0;

    int i=0;

    int avancer=0;



  float angle_robot=angle_radian*RAD_TO_DEG;



  if(angle_robot<0) angle_robot+=360;





  float angle_droite1=-(atan2(dx,dy))*RAD_TO_DEG;

  if(angle_droite1<0) angle_droite1+=180;

  float angle_droite2=angle_droite1+180;

  if(angle_droite2>360) angle_droite2=angle_droite1-180;



  float angle_necessaire=abs(angle_droite1-angle_robot);

  int angle_droite_retenu=angle_droite1;

  if(abs(angle_necessaire)>abs(angle_droite2-angle_robot)){

    angle_necessaire=abs(angle_droite2-angle_robot);

    angle_droite_retenu=angle_droite2;



  }

  if(abs(360-angle_robot+angle_droite1)<abs(angle_necessaire)){

    angle_necessaire=abs(360-angle_robot+angle_droite1);

    angle_droite_retenu=angle_droite1;



  }

  if(abs(360-angle_robot+angle_droite2)<abs(angle_necessaire)){

    angle_necessaire=abs(360-angle_robot+angle_droite2);

    angle_droite_retenu=angle_droite2;



  }

  if(abs(360-angle_droite2+angle_robot)<abs(angle_necessaire)){

    angle_necessaire=abs(360-angle_droite2+angle_robot);

    angle_droite_retenu=angle_droite2;



  }

  if(abs(360-angle_droite1+angle_robot)<abs(angle_necessaire)){

    angle_necessaire=abs(360-angle_droite1+angle_robot);

    angle_droite_retenu=angle_droite1;

  }





  float angle_envoye=angle_radian;

  if(angle_droite_retenu>angle_robot) angle_envoye=abs(angle_necessaire);

  else angle_envoye=-abs(angle_necessaire);

  if(angle_droite_retenu>angle_robot+180) angle_envoye=-abs(angle_necessaire);

  if(angle_droite_retenu+180<angle_robot) angle_envoye=abs(angle_necessaire);





  if(abs(dy)<2&&dx>0&&abs(angle_robot+angle_envoye)-90<=3) avancer=-1;

  else if((((abs(angle_robot+angle_envoye)<=90 || angle_robot+angle_envoye>=270) && Y_DEST>Y_POS) || (angle_robot+angle_envoye>90 && angle_robot+angle_envoye<270 && Y_DEST<Y_POS)) || (((angle_robot+angle_envoye>-180 && angle_robot+angle_envoye<0) || angle_robot+angle_envoye>=180) && X_DEST>X_POS) || (angle_robot+angle_envoye>90 && angle_robot+angle_envoye<270 && Y_DEST<Y_POS)|| (((angle_robot+angle_envoye>0 && angle_robot+angle_envoye<180) || angle_robot+angle_envoye<-180) && X_DEST<X_POS)) avancer=1;

  else avancer=-1;







  static float Rampe_Angle=0;

  static float Rampe_Distance=0;
  float erreur_angle=angle_envoye;

  #define TOLERANCE_ANGLE_RAMPE 8

  #define TOLERANCE_DISTANCE_RAMPE 20
  #define TOLERANCE_DISTANCE_BOULE_ANGLE_FINAL 20

  #define TOLERANCE_DISTANCE 30

  #define TOLERANCE_ANGLE_FINAL 3

  static bool Mise_A_Angle=true;



  static bool Mise_A_Angle_Final=false;

if(sqrt(dx*dx+dy*dy)<TOLERANCE_DISTANCE_BOULE_ANGLE_FINAL)

{

  erreur_angle=-(angle_radian*RAD_TO_DEG-ANGLE_FINAL);

  Mise_A_Angle_Final=true;

}

else

{

   erreur_angle=angle_envoye ;

   Mise_A_Angle_Final=false;



}





float Erreur_Distance=avancer*sqrt(dx*dx+dy*dy)*abs(cos(erreur_angle*DEG_TO_RAD));

  if(abs(Erreur_Distance)>TOLERANCE_DISTANCE_RAMPE)

  {



      Rampe_Distance+=COEFF_RAMP_LINEAIRE;

      if(Rampe_Distance>1) Rampe_Distance=1;

      Erreur_Distance*=Rampe_Distance;

  }

  else

  {



      Rampe_Distance=0;
      Erreur_Distance=avancer*sqrt(dx*dx+dy*dy)*abs(cos(erreur_angle*DEG_TO_RAD));

      if(abs(Erreur_Distance)<TOLERANCE_DISTANCE&&Mise_A_Angle_Final==true &&Consigne_Actuel->Action==Deplacement&& abs(erreur_angle)<TOLERANCE_ANGLE_FINAL)

      {

          Consigne_termine=true;

          Rampe_Distance=0;

          Rampe_Angle=0;

          Mise_A_Angle_Final=false;

          Mise_A_Angle=true;

      }



  }



  float Erreur_Angulaire_Degres=erreur_angle;

  if(abs(Erreur_Angulaire_Degres)>TOLERANCE_ANGLE_RAMPE)

  {

    if(abs(Erreur_Angulaire_Degres)>45)Rampe_Angle+=COEFF_RAMP_ANG/10;

    else Rampe_Angle+=COEFF_RAMP_ANG;

       if (Rampe_Angle > 1 ) Rampe_Angle=1 ;

       Erreur_Angulaire_Degres*=Rampe_Angle;

  }

  else

  {

    Rampe_Angle=0;

    Erreur_Angulaire_Degres=erreur_angle;

    if(abs(Erreur_Angulaire_Degres)<5&&Mise_A_Angle==true)Mise_A_Angle=false;



  }



  erreur_angle_radian=Erreur_Angulaire_Degres*DEG_TO_RAD;

(Mise_A_Angle==true )? Distance_moyenne=0:Distance_moyenne=Erreur_Distance;







if(Consigne_Actuel->Action!=Deplacement){

  erreur_angle_radian=-(angle_radian-ANGLE_FINAL*DEG_TO_RAD);



}





if(Obstacle_devant==true && Distance_moyenne>0){

  Distance_moyenne=0;

  Rampe_Distance=0;

  Rampe_Angle=0;





}

else if(Obstacle_derriere==true && Distance_moyenne<0){

  Distance_moyenne=0;

  Rampe_Distance=0;

  Rampe_Angle=0;





}







}



void Routine_Robot()

{





  if ((millis() - Temps_assert) > TEMPS_MIN_ASSERT) {

    Mise_A_Jour_Action_Robot();

    Lecture_Fourche_Optique();

    Mise_a_jour_bras();

    mise_a_jour_robot();

    calcul_erreur();

    Temps_assert = millis();

    asservissement_robot(Distance_moyenne, erreur_angle_radian);



  }

  Reception();

  Mise_a_jour_detection();

}

void Mise_A_Jour_Action_Robot()

{

  static bool First_Passage_Action=true;

  if(Consigne_termine==true)

  {

    if(Consigne_Actuel->Derniere_Consigne==false)

    {





      Consigne_Actuel=Consigne_Actuel->consigne_suivante;

      for(int i=0;i<TAILLE_TABLEAU_SOMME;i++)

      {

        Somme_Erreur_Lin[i]=0;

        Somme_Erreur_Ang[i]=0;

      }

        First_Passage_Action=true;

         New_moove_angle = true;

         New_moove_distance = false;

         New_moove_angle_final = false;

         premier_passage_A = false;

         Consigne_termine=false;

       }

      else

      {

        Robot_Principal=Fin;

      }

       Temps_Base_Systeme=millis();

    }



  switch (Consigne_Actuel->Action) {

    case Deplacement:

          X_DEST=Consigne_Actuel->X_DEST;

          Y_DEST=Consigne_Actuel->Y_DEST;

          ANGLE_FINAL=Consigne_Actuel->ANGLE_FINAL;

    break;

    case Pince_V:



      if(Consigne_Actuel->Information_Supplementaire==Pince_V_UP)

      {



        Pince_UP();



      }



      else if(Consigne_Actuel->Information_Supplementaire==Pince_V_DOWN)

          Pince_DOWN();

      else if(Consigne_Actuel->Information_Supplementaire==Pince_V_Bourrage)

          Pince_V_Bourre();

      else if(Consigne_Actuel->Information_Supplementaire==Pince_V_Pousse)

          Pince_V_Pousse_Action();

    break;

    case Pince_H:

      if(Consigne_Actuel->Information_Supplementaire==Pince_H_Desserre)

        Pince_OPEN();

      else if(Consigne_Actuel->Information_Supplementaire==Pince_H_Pousse)

        Pince_WAIT();

      else if(Consigne_Actuel->Information_Supplementaire==Pince_H_Serre)

        Pince_CLOSE();

        else if(Consigne_Actuel->Information_Supplementaire==Pince_H_Droite_Desserre)

          Pince_D_OPEN();

        else if(Consigne_Actuel->Information_Supplementaire==Pince_H_Gauche_Desserre)

          Pince_G_OPEN();

          else if(Consigne_Actuel->Information_Supplementaire==Pince_H_Dechargement)

            Pince_H_Decharge();

    break;

    case Chargeur_Cylindre:

      if(Consigne_Actuel->Information_Supplementaire==Chargeur_Down&&First_Passage_Action==true)

        {Quart++;

        Chargeur_Pret=false;

      First_Passage_Action=false;}

      else if(Consigne_Actuel->Information_Supplementaire==Chargeur_UP&&First_Passage_Action==true)

        {Quart++;

        Chargeur_Pret=false;

        First_Passage_Action=false;}

    break;

    case Bras:

      if(Consigne_Actuel->Information_Supplementaire==Bras_Pousse)

        Etat_bras_voulu=1;

      else if(Consigne_Actuel->Information_Supplementaire==Bras_Retracte)

        Etat_bras_voulu=0;

    break;

  }



  if(Consigne_Actuel->Action==Bras&&Etat_bras_voulu==Etat_bras)

  {

    Consigne_termine=true;



  }



  if(Consigne_Actuel->Action==Chargeur_Cylindre&& Chargeur_Pret)

  {

    Consigne_termine=true;



  }



if (Consigne_Actuel->TimeOut != -1) {

  if ((millis() - Temps_Base_Systeme) > Consigne_Actuel->TimeOut) {

    Consigne_termine = true;



  }

}

}
# 1 "F:/Guilhem/Documents/GitHub/ProjetRobot2017/Asser/Asser/setup.ino"
#include <Arduino.h>

#include "define.h"



void Setup_Commande()

{
# 23 "F:/Guilhem/Documents/GitHub/ProjetRobot2017/Asser/Asser/setup.ino"
  Consigne_Actuel=&Consigne1;

  int32_t dx=Consigne_Actuel->X_DEST-X_POS;

  int32_t dy=Consigne_Actuel->Y_DEST-Y_POS;

  DELTA_Consigne_Init=Consigne1.ANGLE_FINAL;





}

void setup_asservissement()

{

   Serial.begin(115200);

   Serial1.begin(115200);





  Serial3.begin(115200);

  Serial3.print("R\n");



 pinMode(PIN_MOTEUR_DROITE_VITESSE, OUTPUT);

  pinMode(PIN_MOTEUR_DROITE_SENS, OUTPUT);

  pinMode(PIN_MOTEUR_GAUCHE_VITESSE, OUTPUT);

  pinMode(PIN_MOTEUR_GAUCHE_SENS, OUTPUT);

  initialisation_variables();

  Serial1.println("INIT Gros Robot");

Consigne_termine=false;

 delay(100);





}

void initialisation_variables()

{

 cnt = 0;

  for(int i=0; i<10;i++)

    {

      data[i]="";

    }

 stringComplete = false;

 inputString = "";





 Codeuse_Droite=0;

 Codeuse_Gauche=0;

 Codeuse_Droite_PAST=0;

 Codeuse_Gauche_PAST=0;
# 115 "F:/Guilhem/Documents/GitHub/ProjetRobot2017/Asser/Asser/setup.ino"
}