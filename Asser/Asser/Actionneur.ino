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

  // Servo_S_D.write(Servo_S_D_WAIT);
  // Servo_S_G.write(Servo_S_G_WAIT);
  // Servo_L_D.write(Servo_S_D_DOWN);
  // Servo_L_G.write(Servo_S_G_DOWN);
  /*Pince_DOWN();
  delay(1000);
  Pince_CLOSE();
  delay(1000);
  Pince_UP();
  delay (1000);
  Pince_OPEN();
  delay (1000);
  */
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
void Pince_V_d_up(){
  Servo_L_D.write(Servo_S_D_seul_UP);
}
void Pince_V_g_up(){
  Servo_L_G.write(Servo_S_G_UP);
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

  if (digitalRead(Fin_Course_Pousse) == LOW && Etat_bras_voulu == 1) {//Bras poussé
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


//Lecture_Fourche_Optique();

  if(  Chargeur_Pret==false&& Consigne_Actuel->Action==Chargeur_Cylindre)
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
void Mise_a_jour_detection(){
  Obstacle_devant=digitalRead(GPIO_DETECTION_AVANT);


  Obstacle_derriere=digitalRead(GPIO_DETECTION_ARRIERE);

}
void Mise_A_Jour_Tirette()
{
    //Serial.println("Waiting Tirette");
  if(digitalRead(GPIO_TIRRETTE)==HIGH)
  {
    //Serial.println("GOOOO");
    if(digitalRead(GPIO_COULEUR_JAUNE)==LOW)
    {
      //Couleur Jaune
          //Serial.println("yellow");
    }
    else if(digitalRead(GPIO_COULEUR_BLEU)==LOW)
    {
      //Serial.println("Blue");
      //Couleur Bleu
    }
    Robot_Principal=En_Route;
  }
}
