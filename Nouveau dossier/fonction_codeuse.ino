#include <Arduino.h>

void recuperer(byte A) {

  String inputString_Codeuse = "";
  String data_Codeuse[10]; // stockage des données découpées
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
