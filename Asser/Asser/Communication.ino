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
    if (index != -1) { // s'il y a bien un caractère séparateu
      // on découpe la chaine et on stocke le bout dans le tableau
      data[cnt] = message.substring(0, index);
      cnt++;
      // on enlève du message le bout stocké
      message = message.substring(index + 1, message.length());
    } else {
      // après le dernier espace
      // on s'assure que la chaine n'est pas vide
      if (message.length() > 0) {

        data[cnt] = message.substring(0, index); // dernier bout
        cnt++;
      }
    }
  } while (index >= 0); // tant qu'il y a bien un séparateur dans la chaine
}

void Reception() {
  if (stringComplete) {
    ////Affichage de la trame recue complete
    //    //Serial.println("inputString : " + inputString);
    // on le découpe à chaque  ';'
    // et on stocke les bouts dans un tableau data
    splitString(inputString, SEPARATEUR, data);
    ////Affichage du resultat du parseur de com
    //     for(int i=0; i<10;i++)
    //    {
    //      //Serial.println(data[i]);
    //    }

    // Data[] Contient la trame
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
  //Rampe_angle = 0;
  Rampe_distance = 0;
   ConsigneTemp.Derniere_Consigne=true;
    ConsigneTemp.consigne_suivante=&ConsigneTemp;
  //Serial.println("GG");
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
  //Rampe_angle = 0;
  Rampe_distance = 0;
  Consigne_Actuel=&ConsigneTemp;
  }
  if (data[0].equals("S")) {
    Servo_S_D.write((float)data[1].toInt());
    Servo_S_G.write((float)data[2].toInt());
  }

}
void serialEvent() {
  while (Serial.available()) {
    // récupérer le prochain octet (byte ou char) et l'enlever du buffer
    char inChar = (char)Serial.read();

    if (inChar == '\n') { // caractère de fin pour notre chaine
      stringComplete = true;
    } else { // concaténation des octets reçus
      inputString += inChar;
    }
  }
}
