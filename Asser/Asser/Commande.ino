#include "define.h"
/*struct Consigne {
  Type_Action Action=Deplacement;

  float X_DEST = X_POS, Y_DEST = Y_POS, ANGLE_FINAL = ANGLE_POS;
  int32_t TimeOut=-1;//En ms
  int Information_Supplementaire=Detection_Active;
  bool Derniere_Consigne=false;
  Consigne *consigne_suivante = NULL;
};*/
/*
enum Type_Action {Deplacement, Pince_V, Pince_H, Chargeur_Cylindre,Bras};
enum Deplacement {Detection_Active, Detection_Inactive};
enum Pince_V_Action{Pince_V_UP,Pince_V_DOWN};
enum Pince_H_Action{Pince_H_Serre,Pince_H_Pousse,Pince_H_Desserre};
enum Bras_Action{Bras_Retracte,Bras_Pousse};
enum Chargeur_Cylindre_Action{Chargeur_UP, Chargeur_Down};*/
//Consigne Consigne1 = {.Type_Action=Deplacement,.X_DEST=400,.Y_DEST=1070,.ANGLE_FINAL=90,.TimeOut=-1,.Information_Supplementaire=Detection_Active,.Derniere_Consigne=true,.consigne_suivante=NULL};

/*  Consigne(Type_Action Action2,float X,float Y,float A,int32_t Time, int Inf, bool Cons,Consigne *Next ):Action(Action2),X_DEST(X),Y_DEST(Y),ANGLE_FINAL(A), TimeOut(Time),Information_Supplementaire(Inf),Derniere_Consigne(Cons),consigne_suivante(Next) {}
Consigne():X_DEST(X_POS),Y_DEST(Y_POS),ANGLE_FINAL(ANGLE_POS) {}
Consigne(float X,float Y,float A,Consigne *Next ):X_DEST(X),Y_DEST(Y),ANGLE_FINAL(A),consigne_suivante(Next) {}
Consigne(float X,float Y,float A ):X_DEST(X),Y_DEST(Y),ANGLE_FINAL(A),Derniere_Consigne(true) {}*/
/*Consigne Consigne5(400,1070,90);
Consigne Consigne4(Chargeur_Cylindre,400,1070,90,3000,Chargeur_UP,false,&Consigne5);
Consigne Consigne3(Bras,400,1070,90,2000,Bras_Pousse,false,&Consigne4);
Consigne Consigne2(400,1070,90,&Consigne3);

Consigne Consigne1(Pince_V,0,1070,90,2000,Pince_V_DOWN,false,&Consigne2);

Consigne Consigne5(400,1070,90);
Consigne Consigne4(Chargeur_Cylindre,400,1070,90,3000,Chargeur_UP,false,&Consigne5);*/
/*Consigne Consigne12(175,1250,90);
Consigne Consigne11(Pince_V,175,1250,90,1000,Pince_V_DOWN,false,&Consigne12);
Consigne Consigne10(Pince_H,175,1250,90,1000,Pince_H_Desserre,false,&Consigne11);
Consigne Consigne9(Pince_V,175,1250,90,1000,Pince_V_UP,false,&Consigne10);
Consigne Consigne8(Bras,175,1250,90,2000,Bras_Retracte,false,&Consigne9);
Consigne Consigne7(Chargeur_Cylindre,175,1250,90,3000,Chargeur_UP,false,&Consigne8);
Consigne Consigne6(Pince_H,175,1250,90,1000,Pince_H_Serre,false,&Consigne7);
Consigne Consigne5(Bras,175,1250,90,1000,Bras_Pousse,false,&Consigne6);
Consigne Consigne4(Pince_H,175,1250,90,1000,Pince_H_Pousse,false,&Consigne5);
Consigne Consigne3(Pince_V,175,1250,90,1000,Pince_V_DOWN,false,&Consigne4);
Consigne Consigne2(175,1250,90,&Consigne3);
Consigne Consigne1(130,1070,130,&Consigne2);*/
Consigne Consigne1(0,1070,0);


void Setup_Commande()
{
  /*
  Consigne[0].X_DEST=400;
  Consigne[0].Y_DEST=1070;
  Consigne[0].ANGLE_FINAL=90;
  Consigne[0].Derniere_Consigne=true;
  Consigne[0].consigne_suivante=&Consigne[0];*/
  Consigne_Actuel=&Consigne1;
  int32_t dx=Consigne_Actuel->X_DEST-X_POS;
  int32_t dy=Consigne_Actuel->Y_DEST-Y_POS;
  DELTA_Consigne_Init=Consigne1.ANGLE_FINAL;//sqrt(dx*dx+dy*dy);


/*
  Consigne[0].consigne_suivante=&Consigne[1];

  Consigne[1].X_DEST=200;
  Consigne[1].Y_DEST=1300;
  Consigne[1].ANGLE_FINAL=90;
  Consigne[1].consigne_suivante=&Consigne[2];

  Consigne[2].X_DEST=30;
  Consigne[2].Y_DEST=1300;
  Consigne[2].ANGLE_FINAL=90;
  Consigne[2].consigne_suivante=&Consigne[3];


  Consigne[3].X_DEST=650;
  Consigne[3].Y_DEST=1650;
  Consigne[3].ANGLE_FINAL=90;
  Consigne[3].consigne_suivante=&Consigne[4];

  Consigne[4].X_DEST=700;
  Consigne[4].Y_DEST=750;
  Consigne[4].ANGLE_FINAL=130;
  Consigne[4].consigne_suivante=&Consigne[5];

  Consigne[5].X_DEST=350;
  Consigne[5].Y_DEST=200;
  Consigne[5].ANGLE_FINAL=130;
  Consigne[5].Derniere_Consigne=true;*/


}
