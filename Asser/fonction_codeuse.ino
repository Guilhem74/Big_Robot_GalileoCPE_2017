
void recuperer(byte A)
{

  String inputString_Codeuse = "";
  String data_Codeuse[10]; // stockage des données découpées
  bool fini = true;
  Serial1.print("C\n");

  while (Serial1.available() && fini)
  {
    char inChar = (char)Serial1.read();

    if (inChar == '\n')
    { 
 
    splitString(inputString_Codeuse, SEPARATEUR,data_Codeuse);
     Codeuse_Droite=data_Codeuse[1].toInt();
     Codeuse_Gauche=-data_Codeuse[2].toInt();
     Serial.print(Codeuse_Droite);
     Serial.print("  ");
     Serial.println(Codeuse_Gauche);
     fini = false;
    
    }
    else
      inputString_Codeuse += inChar;
  }

}
