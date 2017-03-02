
void recuperer(byte A)
{

  String inputString = "";
  bool fini = true;
  if (A == 0) //Droite
  {
    Serial1.write("x");
  }

  if (A == 1) //Gauche
    Serial1.write("y");

  while (Serial1.available() && fini)
  {
    char inChar = (char)Serial1.read();

    inputString += inChar;

    if (inChar == '\n')
    { inputString += inChar;
      if (A == 0)
      {
        D = -inputString.toInt();
               
      }
      if (A == 1)
      {
        G = -inputString.toInt();
      
      }
     
      fini = false;
    }
  }

}
