#define VITESSE_TEST 255

void Tourner_Moteur_D()
{
//Envoi des commandes aux moteurs
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
void Droit_Au_But()
{
//Envoi des commandes aux moteurs
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
void Je_Paye_Ma_Tournee()
{
//Envoi des commandes aux moteurs
  Serial.println("Moteur Droit avance & gauche recule \n");
  Serial.println("Test  de rotation \n");
   delay(1000);
  digitalWrite(PIN_MOTEUR_DROITE_SENS, ETAT_MOTEUR_AVANCE);
  digitalWrite(PIN_MOTEUR_GAUCHE_SENS, !ETAT_MOTEUR_AVANCE);

  delayMicroseconds(10);
  analogWrite(PIN_MOTEUR_DROITE_VITESSE, VITESSE_TEST/8);
    analogWrite(PIN_MOTEUR_GAUCHE_VITESSE, VITESSE_TEST/8);

    delay(4000);
     analogWrite(PIN_MOTEUR_DROITE_VITESSE, 0);
      analogWrite(PIN_MOTEUR_GAUCHE_VITESSE, 0);

}

void Tourner_Moteur_G()
{
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

void Plz_Share_What_U_Know_About_Encoder()
{
  Serial.print("D: ");
  Serial.print(D);
  Serial.print("  ");
  Serial.print("G: ");
  Serial.println(G);
}

void Where_Is_Robot()
{
  Serial.print("X: ");
  Serial.print(X_POS);
  Serial.print("   ");
  Serial.print("Y: ");
  Serial.print(Y_POS);
   Serial.print("O: ");
  Serial.print(ANGLE_POS);
}

