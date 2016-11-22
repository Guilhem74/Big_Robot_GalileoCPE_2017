import processing.serial.*; // importe la librairie série processing
import controlP5.*; // importe la librairie GUI cp5
Serial  Port_COM; 
ControlP5 cp5; // déclare un objet principal de la librairie GUI cp5
Button envoiButton,stopButton; // déclare objet Button  
CheckBox checkbox;
Textfield chaineX,chaineY,chaineA,chaineT; // déclare des objets Textfield 
//Variable de couleurs
int jaune=color(255,255,0); 
int vert=color(0,255,0); 
int rouge=color(255,0,0); 
int bleu=color(0,0,255); 
int noir=color(0,0,0); 
int blanc=color(255,255,255); 
int bleuclair=color(0,255,255); 
int violet=color(255,0,255); 
//
 String Reception;
 String chaineEnvoi = ""; // déclare un objet String (chaine de caractère) 
 String chaineEnvoi2 = ""; // déclare un objet String (chaine de caractère) 
  String chaineEnvoi3 = ""; // déclare un objet String (chaine de caractère) 
 String chaineEnvoi4 = ""; // déclare un objet String (chaine de caractère) 

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
  size(1000,800);
  background(255,255,255); // fond noir
  colorMode(RGB, 255,255,255); // fixe format couleur R G B pour fill, stroke, etc...
  fill(0,0,255); // couleur remplissage RGB
  stroke (0,0,0); // couleur pourtour RGB
  rectMode(CORNER); // origine rectangle : CORNER = coin sup gauche | CENTER : centre 
  imageMode(CORNER); // origine image : CORNER = coin sup gauche | CENTER : centre
  println("Ports série disponibles sur le PC :");
  println(Serial.list()); // affiche dans la console la liste des ports séries
  Port_COM = new Serial(this, "COM16", 115200); // Initialise une nouvelle instance du port Série
  Y[1]=0;
  X[1]=0;
  Z[1]=0;
 //Panneau de commande

  stroke(0)          ;//# Setting the outline (stroke) to black
  fill(0)          ;//# Setting the interior of a shape (fill) to grey 
  rect(0, 7.5*height/8, width,1*height/8);
  cp5=new ControlP5(this);
   checkbox = cp5.addCheckBox("checkBox")
                .setPosition(650, height-40)
                .setSize(10, 10)
                .setItemsPerRow(2)
                .setSpacingColumn(100)
                .setSpacingRow(40)
                .addItem("Reculer", 0)
                .addItem("Reinitialiser", 0)
                ;
  envoiButton=cp5.addButton("envoiButton",0,width-60,height-45,50,24); // initialise et ajoute un Button au cp5
  envoiButton.setLabelVisible(true); // affichage des labels
  envoiButton.setLabel("SEND"); // fixe label du bouton
  envoiButton.setColorActive(color(255,0,0)); // fixe la couleur active
  envoiButton.setColorForeground(color(0,255,255)); // fixe couleur avant 
  
  stopButton=cp5.addButton("stopButton",0,width-120,height-45,50,24); // initialise et ajoute un Button au cp5
  stopButton.setLabelVisible(true); // affichage des labels
  stopButton.setLabel("STOP"); // fixe label du bouton
  stopButton.setColorActive(color(255,0,0)); // fixe la couleur active
  stopButton.setColorForeground(color(255,0,0)); // fixe couleur avant 
  
  chaineT=cp5.addTextfield("chaineT",10,height-45,300,20); // initialise et ajoute un Textfield au cp5
  chaineT.setAutoClear(false); // autoeffacement après return
  chaineT.setValue(chaineEnvoi); // initialise Texte du champ
  chaineT.setLabelVisible(true); // affichage des labels
  chaineT.setLabel("Commande"); // fixe label
  chaineT.setColorActive(color(255,0,0)); // fixe la couleur active
  chaineT.setColorForeground(color(0,255,255)); // fixe couleur avant 
  
  chaineX=cp5.addTextfield("chaineX",500,height-45,30,20); // initialise et ajoute un Textfield au cp5
  chaineX.setAutoClear(false); // autoeffacement après return
  chaineX.setValue(chaineEnvoi2); // initialise Texte du champ
  chaineX.setLabelVisible(true); // affichage des labels
  chaineX.setLabel("X"); // fixe label
  chaineX.setColorActive(color(255,0,0)); // fixe la couleur active
  chaineX.setColorForeground(color(0,255,255)); // fixe couleur avant 

  chaineY=cp5.addTextfield("chaineY",535,height-45,30,20); // initialise et ajoute un Textfield au cp5
  chaineY.setAutoClear(false); // autoeffacement après return
  chaineY.setValue(chaineEnvoi3); // initialise Texte du champ
  chaineY.setLabelVisible(true); // affichage des labels
  chaineY.setLabel("Y"); // fixe label
  chaineY.setColorActive(color(255,0,0)); // fixe la couleur active
  chaineY.setColorForeground(color(0,255,255)); // fixe couleur avant 
  
  chaineA=cp5.addTextfield("chaineA",570,height-45,30,20); // initialise et ajoute un Textfield au cp5
  chaineA.setAutoClear(false); // autoeffacement après return
  chaineA.setValue(chaineEnvoi4); // initialise Texte du champ
  chaineA.setLabelVisible(true); // affichage des labels
  chaineA.setLabel("Z"); // fixe label
  chaineA.setColorActive(color(255,0,0)); // fixe la couleur active
  chaineA.setColorForeground(color(0,255,255)); // fixe couleur avant 
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
     {//Stockage des valeurs recues
     Y[Compteur]=int(list[1]);
     Z[Compteur]=int(list[2]);
     X[Compteur]=X[Compteur-1]+1;
     }
   }
   
 }
 void Dessin()
 {
     stroke(204, 102, 0);
   line(X[Compteur-1]/10,height/2-Y[Compteur-1]+7.5*height/16,X[Compteur]/10,height/2-Y[Compteur]+7.5*height/16);
   stroke(204, 102, 120);
   line(X[Compteur-1]/10,height/2-Z[Compteur-1]+7.5*height/16,X[Compteur]/10,height/2-Z[Compteur]+7.5*height/16);
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

void controlEvent(ControlEvent theEvent) {
  if (theEvent.isFrom(checkbox)) {
   
    
    if(checkbox.getArrayValue(1)==1)
      checkbox.deactivateAll();
      chaineX.clear();
      chaineY.clear();
      chaineA.clear();
      chaineT.clear();
       Port_COM.write("U;\n"); 
    }
  
}
void envoiButton(int theValue) { // fonction évènement Button de meme nom - reçoit la valeur

        println("Evènement envoiButton");
        if(checkbox.getArrayValue(0)==0)
        {
        Port_COM.write("XYA;"+chaineX.getText()+";"+chaineY.getText()+";"+chaineA.getText()+"\n"); // envoie la chaine suivi saut ligne sur le port Série
        }
        else
        {
         Port_COM.write("R;"+chaineX.getText()+";"+chaineY.getText()+";"+chaineA.getText()+"\n"); // envoie la chaine suivi saut ligne sur le port Série
        }

} 
void stopButton(int theValue) { // fonction évènement Button de meme nom - reçoit la valeur

        Port_COM.write("S;\n"); 


} 
public void chaineT(String theText) { // fonction évènement Textfield de meme nom - déclenché par return - reçoit la chaine
        Port_COM.write(theText+"\n");
} // fin evènement champ texte chemin fichier