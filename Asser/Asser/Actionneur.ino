#include <Arduino.h>

#define GPIO_PINCE_SERRAGE_DROITE 3
#define GPIO_PINCE_SERRAGE_GAUCHE 5
#define GPIO_PINCE_LEVAGE_DROITE 4
#define GPIO_PINCE_LEVAGE_GAUCHE 2
#include <Servo.h>
#define Servo_S_D_CLOSE 160
#define Servo_S_G_CLOSE 20
#define Servo_S_D_UP 155
#define Servo_S_G_UP 5
#define Servo_S_D_OPEN 5
#define Servo_S_G_OPEN 180
#define Servo_S_D_DOWN 85
#define Servo_S_G_DOWN 75
#define Servo_S_D_WAIT 145
#define Servo_S_G_WAIT 35

#define Fin_Course_Retracte 53
#define Fin_Course_Pousse 51

#define PIN_Chargeur_Cylindre_DIR 45
#define PIN_Chargeur_Cylindre_PWM 7
#define Vitesse_MIN_Chargeur_Cylindre 60
#define PIN_Bras_DIR 47
#define PIN_Bras_PWM 6
#define VITESSE_BRAS_AVANCE 200
#define VITESSE_BRAS_RECULE 200
#define ETAT_BRAS_AVANCE HIGH
#define ETAT_BRAS_RECULE LOW

Servo Servo_S_D;
Servo Servo_S_G;
Servo Servo_L_D;
Servo Servo_L_G;

void Setup_Actionneur() {
  Servo_S_D.attach(GPIO_PINCE_SERRAGE_DROITE);
  Servo_S_G.attach(GPIO_PINCE_SERRAGE_GAUCHE);
  Servo_L_D.attach(GPIO_PINCE_LEVAGE_DROITE);
  Servo_L_G.attach(GPIO_PINCE_LEVAGE_GAUCHE);
  pinMode(Fin_Course_Retracte, INPUT_PULLUP);
  pinMode(Fin_Course_Pousse, INPUT_PULLUP);
  pinMode(PIN_Chargeur_Cylindre_DIR, OUTPUT);
  pinMode(PIN_Chargeur_Cylindre_PWM, OUTPUT);
  pinMode(PIN_Bras_DIR, OUTPUT);
  pinMode(PIN_Bras_PWM, OUTPUT);

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
  Servo_S_D.write(Servo_S_D_OPEN);
  Servo_S_G.write(Servo_S_G_OPEN);
}
void Pince_DOWN() {
  Servo_L_D.write(Servo_S_D_DOWN);
  Servo_L_G.write(Servo_S_G_DOWN);
}

void Pince_WAIT() {
  Servo_L_D.write(Servo_S_D_WAIT);
  Servo_L_G.write(Servo_S_G_WAIT);
}

void Mise_a_jour_bras() {
  if (digitalRead(Fin_Course_Pousse) == HIGH && Etat_bras_voulu == 1) {
    Etat_bras = 1;
    analogWrite(PIN_Bras_PWM, 0);
  } else if (digitalRead(Fin_Course_Pousse) == LOW && Etat_bras_voulu == 1) {
    digitalWrite(PIN_Bras_DIR, ETAT_BRAS_AVANCE);
    analogWrite(PIN_Bras_PWM, VITESSE_BRAS_AVANCE);
  } else if (digitalRead(Fin_Course_Retracte) == LOW && Etat_bras_voulu == 0) {
    digitalWrite(PIN_Bras_DIR, ETAT_BRAS_RECULE);
    analogWrite(PIN_Bras_PWM, VITESSE_BRAS_RECULE);
  } else if (digitalRead(Fin_Course_Retracte) == HIGH && Etat_bras_voulu == 0) {
    Etat_bras = 0;
    analogWrite(PIN_Bras_PWM, 0);
  }
}
