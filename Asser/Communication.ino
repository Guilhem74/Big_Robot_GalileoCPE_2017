

void splitString(String message, char separator,String* data) {
  int index = 0;
  inputString = "";
  stringComplete = false;
  for(int i=0; i<10;i++)
    {
      data[i]="";
    }
  cnt = 0;
    do {
      index = message.indexOf(separator);
      if(index != -1) {// s'il y a bien un caractère séparateu
          // on découpe la chaine et on stocke le bout dans le tableau
          data[cnt] = message.substring(0,index);
          cnt++;
          // on enlève du message le bout stocké
          message = message.substring(index+1, message.length());
      } else {
         // après le dernier espace
         // on s'assure que la chaine n'est pas vide
         if(message.length() > 0) {
        
           data[cnt] = message.substring(0,index); // dernier bout
           cnt++;
         }
      }
   } while(index >=0); // tant qu'il y a bien un séparateur dans la chaine

}

void Reception()
{
  if (stringComplete)
  {
////Affichage de la trame recue complete
//    Serial.println("inputString : " + inputString);
    // on le découpe à chaque  ';'
    // et on stocke les bouts dans un tableau data
    splitString(inputString, SEPARATEUR,data);
////Affichage du resultat du parseur de com
//     for(int i=0; i<10;i++)
//    {
//      Serial.println(data[i]);
//    }


// Data[] Contient la trame
  Traitement();
   }
   
}
void Traitement()
{
  if(data[0].equals("XYA"))
  {
    X_DEST=(float)data[1].toInt();
    Y_DEST=(float)data[2].toInt();
    ANGLE_FINAL=(float)data[3].toInt();
    MARCHE_ARRIERE=false;
    New_moove_angle=true;
    Rampe_angle=0;
    Rampe_distance=0;
  }
  if(data[0].equals("S"))
  {
     mise_a_jour_POS();
    X_DEST=X_POS;
    Y_DEST=Y_POS;
    ANGLE_FINAL=ANGLE_POS;


  }
   if(data[0].equals("O"))
  {
    Y_DEST=(float)data[1].toInt();
  }
  if(data[0].equals("R"))
  {
    X_DEST=(float)data[1].toInt();
    Y_DEST=(float)data[2].toInt();
    ANGLE_FINAL=(float)data[3].toInt();
    MARCHE_ARRIERE=true;
  }
  if(data[0].equals("U"))
  {
    Serial1.write('r');
    
    X_DEST=0;
    X_POS=0;
    Y_DEST=0;
    Y_POS=0;
    ANGLE_FINAL=0;
    ANGLE_POS=0;
    Distance_moyenne =0;
    erreur_angle_radian=0;
    erreur_lineaire=0;
    erreur_precedente_lineaire=0;
    Somme_erreur_lineaire=0;
    erreur_angulaire=0;
    Somme_erreur_angulaire=0;
    erreur_precedente_angulaire=0;
    erreur_vitesseD=0;
    Somme_erreur_vitesseD=0;
    erreur_vitesseG=0;
    Somme_erreur_vitesseG=0;
    mise_a_jour_POS();
calcul_erreur();
  }
   if(data[0].equals("P"))
   {
  
   }


}


