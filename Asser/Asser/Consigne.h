#ifndef CONSIGNE_H
#define CONSIGNE_H
enum Etat_Robot{ Prechauff, En_Route,Fin};
enum Type_Action {Deplacement, Pince_V, Pince_H, Chargeur_Cylindre,Bras};
enum Deplacement {Detection_Active, Detection_Inactive};
enum Pince_V_Action{Pince_V_UP,Pince_V_DOWN,Pince_V_Bourrage,Pince_V_Pousse};
enum Pince_H_Action{Pince_H_Serre,Pince_H_Pousse,Pince_H_Desserre,Pince_H_Droite_Desserre,Pince_H_Gauche_Desserre,Pince_H_Dechargement};
enum Bras_Action{Bras_Retracte,Bras_Pousse};
enum Chargeur_Cylindre_Action{Chargeur_UP, Chargeur_Down};
Etat_Robot Robot_Principal=Prechauff;

 struct Consigne {
  Type_Action Action=Deplacement;

  float X_DEST = 0, Y_DEST = 0, ANGLE_FINAL = 0;
  float COEFF_RAMP_ANG=0.01, COEFF_RAMP_LINEAIRE=0.01;
  int32_t TimeOut=-1;//En ms
  int Information_Supplementaire=Detection_Active;
  bool Derniere_Consigne=false;
  Consigne *consigne_suivante = NULL;
  Consigne(Type_Action Action2,int32_t Time, int Inf):Action(Action2), TimeOut(Time),Information_Supplementaire((int)Inf),Derniere_Consigne(true){}
  Consigne(Type_Action Action2,int32_t Time, int Inf,Consigne *Next ):Action(Action2), TimeOut(Time),Information_Supplementaire((int)Inf),Derniere_Consigne(false),consigne_suivante(Next) {}
  Consigne(): Action( Deplacement), X_DEST(0),Y_DEST(0),ANGLE_FINAL(0) {}
  Consigne(float X,float Y,float A,int32_t Time,Consigne *Next ):Action( Deplacement),X_DEST(X),Y_DEST(Y),ANGLE_FINAL(A),TimeOut(Time),consigne_suivante(Next) {}

  Consigne(float X,float Y,float A,Consigne *Next ):Action( Deplacement),X_DEST(X),Y_DEST(Y),ANGLE_FINAL(A),Derniere_Consigne(false),consigne_suivante(Next) {}
  Consigne(float X,float Y,float A ):Action(Deplacement),X_DEST(X),Y_DEST(Y),ANGLE_FINAL(A),Derniere_Consigne(true) {}
};
//RAZ des Tableaux et des news moove
/*
float Somme_Erreur_Lin[TAILLE_TABLEAU_SOMME]={};
float Somme_Erreur_Ang[TAILLE_TABLEAU_SOMME]={};
bool New_moove_angle = true;
bool New_moove_distance = false;
bool New_moove_angle_final = false;
bool premier_passage = false;
bool Consigne_termine=false,*/
Consigne *Consigne_Actuel;
Consigne ConsigneTemp;
#endif
