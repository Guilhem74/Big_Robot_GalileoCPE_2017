import processing.serial.*; // importe la librairie série processing

Serial  Port_COM; 
 String Reception;
 boolean Recue=false;
 int Compteur=2;
 // fin fonction Setup
int X_Size=800,Y_Size=8000;
int[] X = new int[Y_Size+100];
int[] Y = new int[Y_Size+100];
int[] Z = new int[Y_Size+100];
int value =0;
void setup()
{
  // fonction d'initialisation exécutée 1 fois au démarrage
  //---- initialisation graphique ----
  size(1000,1200);
  background(255,255,255); // fond noir
  println("Ports série disponibles sur le PC :");
  println(Serial.list()); // affiche dans la console la liste des ports séries
  Port_COM = new Serial(this, "COM4", 115200); // Initialise une nouvelle instance du port Série
  Y[1]=0;
  X[1]=0;
  Z[1]=0;
}

void  draw()
{ // fonction exécutée en boucle

 Analyse_Donnees();
 Dessin();
  Compteur++;
  
} // fin de la fonction draw()
void Analyse_Donnees()
{
    if(Recue)
   { 
     Recue=false;
     String[] list = split(Reception, ';');
     //println(list[1]);
     if(list[0].equals("X"))
     {
     Y[Compteur]=int(list[1]);
     Z[Compteur]=int(list[2]);
     println(Z[Compteur]);
     println(Y[Compteur]);
     }
   }
   else
   { 
     Y[Compteur]=Y[Compteur-1];
     Z[Compteur]=Z[Compteur-1];
   }
   X[Compteur]=X[Compteur-1]+1;
 }
 void Dessin()
 {
     stroke(204, 102, 0);
   line(X[Compteur-1]/10,height/2-Y[Compteur-1],X[Compteur]/10,height/2-Y[Compteur]);
   stroke(204, 102, 120);
   line(X[Compteur-1]/10,height/2-Z[Compteur-1],X[Compteur]/10,height/2-Z[Compteur]);
 }
 
 
//------------- Fonction de gestion des évènements série ----
void serialEvent (Serial Port_COM)
{ // fonction appelée lors de la survenue d'un évènement série
  // ******** Gestion de la valeur reçue sur le port série : **********
  String inString = Port_COM.readStringUntil('\n'); // chaine stockant la chaîne reçue sur le port Série
  // saut de ligne en marque de fin
 
  if (inString != null)
  { // si la chaine recue n'est pas vide
                 Reception=inString;// affiche chaine recue
                 Recue=true;
                
  } // fin condition chaine recue pas vide
} // fin de la fonction de gestion des évènements Série
 void keyPressed() {

  if (key == 'a' || key == 'A') {
      Port_COM.write("XYA;0;500;0 \n");
    }
  if (key == 'H' || key == 'h') {
      Port_COM.write("XYA;0;0;0 \n");
    }
    if (key == 's' || key == 'S') {
      Port_COM.write("S; \n");
    }
    if (key == 'r' || key == 'R') {
     Port_COM.write("R;0;0;0 \n");;
    }
    if (key == 'U' || key == 'u') {
     Port_COM.write("U; \n");;
    }
  
  }