#include "define.h"

void setup_asservissement()
{
  Serial1.begin(115200);
Serial1.write('r');
Serial.begin(115200);
 pinMode(PIN_MOTEUR_DROITE_VITESSE, OUTPUT);
  pinMode(PIN_MOTEUR_DROITE_SENS, OUTPUT);
  pinMode(PIN_MOTEUR_GAUCHE_VITESSE, OUTPUT);
  pinMode(PIN_MOTEUR_GAUCHE_SENS, OUTPUT);
delay(100);
}

