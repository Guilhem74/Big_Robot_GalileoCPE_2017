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
//Consigne Consigne4(0,1370,90);
//Consigne Consigne3(0,1070,0,&Consigne4);
#define TIMEOUT_SERVO 500
#define TIMEOUT_BRAS 1200
#define YELLOW true






















#if YELLOW==0
Consigne Consigne101(100,1070,90);
Consigne Consigne100(565,1365,180,&Consigne101);
Consigne Consigne99(565,1665,180,&Consigne100);
Consigne Consigne98(565,1665,90,&Consigne99);

Consigne Consigne97(Chargeur_Cylindre,1000,Chargeur_UP,&Consigne98);
Consigne Consigne96(Bras,TIMEOUT_BRAS,Bras_Retracte,&Consigne97);
Consigne Consigne95(Bras,TIMEOUT_BRAS,Bras_Pousse,&Consigne96);
Consigne Consigne94(Pince_H,TIMEOUT_SERVO,Pince_H_Serre,&Consigne95);
Consigne Consigne93(Bras,TIMEOUT_BRAS,Bras_Retracte,&Consigne94);
Consigne Consigne92(Bras,TIMEOUT_BRAS,Bras_Pousse,&Consigne93);
Consigne Consigne91(Pince_H,TIMEOUT_SERVO,Pince_H_Desserre,&Consigne92);

Consigne Consigne90(Chargeur_Cylindre,1000,Chargeur_UP,&Consigne91);
Consigne Consigne89(Bras,TIMEOUT_BRAS,Bras_Retracte,&Consigne90);
Consigne Consigne88(Bras,TIMEOUT_BRAS,Bras_Pousse,&Consigne89);
Consigne Consigne87(Pince_H,TIMEOUT_SERVO,Pince_H_Serre,&Consigne88);
Consigne Consigne86(Bras,TIMEOUT_BRAS,Bras_Retracte,&Consigne87);
Consigne Consigne85(Bras,TIMEOUT_BRAS,Bras_Pousse,&Consigne86);
Consigne Consigne84(Pince_H,TIMEOUT_SERVO,Pince_H_Desserre,&Consigne85);

Consigne Consigne83(Chargeur_Cylindre,1000,Chargeur_UP,&Consigne84);
Consigne Consigne82(Bras,TIMEOUT_BRAS,Bras_Retracte,&Consigne83);
Consigne Consigne81(Bras,TIMEOUT_BRAS,Bras_Pousse,&Consigne82);
Consigne Consigne80(Pince_H,TIMEOUT_SERVO,Pince_H_Serre,&Consigne81);
Consigne Consigne79(Bras,TIMEOUT_BRAS,Bras_Retracte,&Consigne80);
Consigne Consigne78(Bras,TIMEOUT_BRAS,Bras_Pousse,&Consigne79);
Consigne Consigne77(Pince_H,TIMEOUT_SERVO,Pince_H_Desserre,&Consigne78);

Consigne Consigne76(Chargeur_Cylindre,1000,Chargeur_UP,&Consigne77);
Consigne Consigne75(Bras,TIMEOUT_BRAS,Bras_Retracte,&Consigne76);
Consigne Consigne74(Bras,TIMEOUT_BRAS,Bras_Pousse,&Consigne75);
Consigne Consigne73(Pince_H,TIMEOUT_SERVO,Pince_H_Serre,&Consigne74);
Consigne Consigne72(Bras,TIMEOUT_BRAS,Bras_Retracte,&Consigne73);
Consigne Consigne71(Bras,TIMEOUT_BRAS,Bras_Pousse,&Consigne72);
Consigne Consigne70(Pince_H,TIMEOUT_SERVO,Pince_H_Desserre,&Consigne71);

Consigne Consigne69(810,1630,-90,&Consigne70);
Consigne Consigne400(300,1630,-90,&Consigne69);

Consigne Consigne68(300,1630,-15,&Consigne400);

Consigne Consigne67(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne68);
Consigne Consigne66(Pince_V,TIMEOUT_SERVO,Pince_V_Bourrage,&Consigne67);
Consigne Consigne65(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne66);
Consigne Consigne64(Chargeur_Cylindre,1000,Chargeur_UP,&Consigne65);

Consigne Consigne63(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne64);
Consigne Consigne62(Pince_V,TIMEOUT_SERVO,Pince_V_Bourrage,&Consigne63);
Consigne Consigne61(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne62);
Consigne Consigne60(Chargeur_Cylindre,1000,Chargeur_UP,&Consigne61);

Consigne Consigne59(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne60);
Consigne Consigne58(Pince_V,TIMEOUT_SERVO,Pince_V_Bourrage,&Consigne59);
Consigne Consigne57(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne58);
//Consigne Consigne56(Chargeur_Cylindre,1000,Chargeur_UP,&Consigne57);


Consigne Consigne55(Chargeur_Cylindre,1000,Chargeur_UP,&Consigne57);
Consigne Consigne54(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne55);
Consigne Consigne53(Pince_V,TIMEOUT_SERVO,Pince_V_Bourrage,&Consigne54);
Consigne Consigne52(Pince_H,TIMEOUT_SERVO,Pince_H_Serre,&Consigne53);
Consigne Consigne51(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne52);
Consigne Consigne50(Pince_H,TIMEOUT_SERVO,Pince_H_Gauche_Desserre,&Consigne51);
Consigne Consigne49(Pince_H,TIMEOUT_SERVO,Pince_H_Droite_Desserre,&Consigne50);
Consigne Consigne48(Pince_V,TIMEOUT_SERVO,Pince_V_UP,&Consigne49);
Consigne Consigne47(Bras,1000,Bras_Retracte,&Consigne48);
Consigne Consigne46(Pince_H,TIMEOUT_SERVO,Pince_H_Serre,&Consigne47);
Consigne Consigne45(Bras,TIMEOUT_BRAS,Bras_Pousse,&Consigne46);
Consigne Consigne44(Pince_H,TIMEOUT_SERVO,Pince_H_Pousse,&Consigne45);
Consigne Consigne43(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne44);



Consigne Consigne42(Chargeur_Cylindre,1000,Chargeur_UP,&Consigne43);
Consigne Consigne41(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne42);
Consigne Consigne40(Pince_V,TIMEOUT_SERVO,Pince_V_Bourrage,&Consigne41);
Consigne Consigne39(Pince_H,TIMEOUT_SERVO,Pince_H_Serre,&Consigne40);
Consigne Consigne38(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne39);
Consigne Consigne37(Pince_H,TIMEOUT_SERVO,Pince_H_Gauche_Desserre,&Consigne38);
Consigne Consigne36(Pince_H,TIMEOUT_SERVO,Pince_H_Droite_Desserre,&Consigne37);
Consigne Consigne35(Pince_V,TIMEOUT_SERVO,Pince_V_UP,&Consigne36);
Consigne Consigne34(Bras,1000,Bras_Retracte,&Consigne35);
Consigne Consigne33(Pince_H,TIMEOUT_SERVO,Pince_H_Serre,&Consigne34);
Consigne Consigne32(Bras,TIMEOUT_BRAS,Bras_Pousse,&Consigne33);
Consigne Consigne31(Pince_H,TIMEOUT_SERVO,Pince_H_Pousse,&Consigne32);
Consigne Consigne30(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne31);


Consigne Consigne29(Chargeur_Cylindre,1000,Chargeur_UP,&Consigne30);
Consigne Consigne28(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne29);
Consigne Consigne27(Pince_V,TIMEOUT_SERVO,Pince_V_Bourrage,&Consigne28);
Consigne Consigne26(Pince_H,TIMEOUT_SERVO,Pince_H_Serre,&Consigne27);
Consigne Consigne25(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne26);
Consigne Consigne24(Pince_H,TIMEOUT_SERVO,Pince_H_Gauche_Desserre,&Consigne25);
Consigne Consigne23(Pince_H,TIMEOUT_SERVO,Pince_H_Droite_Desserre,&Consigne24);
Consigne Consigne22(Pince_V,TIMEOUT_SERVO,Pince_V_UP,&Consigne23);
Consigne Consigne21(Bras,1000,Bras_Retracte,&Consigne22);
Consigne Consigne20(Pince_H,TIMEOUT_SERVO,Pince_H_Serre,&Consigne21);
Consigne Consigne19(Bras,TIMEOUT_BRAS,Bras_Pousse,&Consigne20);
Consigne Consigne18(Pince_H,TIMEOUT_SERVO,Pince_H_Pousse,&Consigne19);
//Consigne Consigne17(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne18);


Consigne Consigne16(Chargeur_Cylindre,1000,Chargeur_UP,&Consigne18);
Consigne Consigne15(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne16);
Consigne Consigne14(Pince_V,TIMEOUT_SERVO,Pince_V_Bourrage,&Consigne15);
Consigne Consigne13(Pince_H,TIMEOUT_SERVO,Pince_H_Serre,&Consigne14);
Consigne Consigne12(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne13);
Consigne Consigne11(Pince_H,TIMEOUT_SERVO,Pince_H_Gauche_Desserre,&Consigne12);
Consigne Consigne10(Pince_H,TIMEOUT_SERVO,Pince_H_Droite_Desserre,&Consigne11);
Consigne Consigne9(Pince_V,TIMEOUT_SERVO,Pince_V_UP,&Consigne10);
Consigne Consigne8(Bras,1500,Bras_Retracte,&Consigne9);
Consigne Consigne7(Pince_H,TIMEOUT_SERVO,Pince_H_Serre,&Consigne8);
Consigne Consigne6(Bras,TIMEOUT_BRAS,Bras_Pousse,&Consigne7);
Consigne Consigne5(Pince_H,TIMEOUT_SERVO,Pince_H_Pousse,&Consigne6);
Consigne Consigne4(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne5);
Consigne Consigne3(180,1290,85 ,&Consigne4);
Consigne Consigne2(90,1070,90,&Consigne3);
Consigne Consigne1(Pince_V,TIMEOUT_SERVO,Pince_V_UP,&Consigne2);
//Consigne Consigne1(400,1070,90);

/*Consigne Consigne3(Chargeur_Cylindre,1000,Chargeur_UP);
Consigne Consigne2(Chargeur_Cylindre,4000,Chargeur_UP,&Consigne3);
Consigne Consigne1(0,1070,90,&Consigne2);*/
#else
Consigne Consigne101(0,2200,90);

Consigne Consigne100(1000,2200,90,&Consigne101);
Consigne Consigne99(565,1665,180,&Consigne100);
Consigne Consigne98(565,1665,90,&Consigne99);

Consigne Consigne97(Bras,TIMEOUT_BRAS,Bras_Retracte);
Consigne Consigne96(Chargeur_Cylindre,1000,Chargeur_UP,&Consigne97);
Consigne Consigne95(Bras,TIMEOUT_BRAS,Bras_Pousse,&Consigne96);
Consigne Consigne94(Pince_H,TIMEOUT_SERVO,Pince_H_Serre,&Consigne95);
Consigne Consigne93(Bras,TIMEOUT_BRAS,Bras_Retracte,&Consigne94);
Consigne Consigne92(Bras,TIMEOUT_BRAS,Bras_Pousse,&Consigne93);
Consigne Consigne91(Pince_H,TIMEOUT_SERVO,Pince_H_Desserre,&Consigne92);

Consigne Consigne90(Bras,TIMEOUT_BRAS,Bras_Retracte,&Consigne91);
Consigne Consigne89(Chargeur_Cylindre,1000,Chargeur_UP,&Consigne90);
Consigne Consigne88(Bras,TIMEOUT_BRAS,Bras_Pousse,&Consigne89);
Consigne Consigne87(Pince_H,TIMEOUT_SERVO,Pince_H_Serre,&Consigne88);
Consigne Consigne86(Bras,TIMEOUT_BRAS,Bras_Retracte,&Consigne87);
Consigne Consigne85(Bras,TIMEOUT_BRAS,Bras_Pousse,&Consigne86);
Consigne Consigne84(Pince_H,TIMEOUT_SERVO,Pince_H_Desserre,&Consigne85);

Consigne Consigne83(Bras,TIMEOUT_BRAS,Bras_Retracte,&Consigne84);
Consigne Consigne82(Chargeur_Cylindre,1000,Chargeur_UP,&Consigne83);
Consigne Consigne81(Bras,TIMEOUT_BRAS,Bras_Pousse,&Consigne82);
Consigne Consigne80(Pince_H,TIMEOUT_SERVO,Pince_H_Serre,&Consigne81);
Consigne Consigne79(Bras,TIMEOUT_BRAS,Bras_Retracte,&Consigne80);
Consigne Consigne78(Bras,TIMEOUT_BRAS,Bras_Pousse,&Consigne79);
Consigne Consigne77(Pince_H,TIMEOUT_SERVO,Pince_H_Desserre,&Consigne78);

Consigne Consigne76(Bras,TIMEOUT_BRAS,Bras_Retracte,&Consigne77);
Consigne Consigne75(Chargeur_Cylindre,1000,Chargeur_UP,&Consigne76);
Consigne Consigne74(Bras,TIMEOUT_BRAS,Bras_Pousse,&Consigne75);
Consigne Consigne73(Pince_H,TIMEOUT_SERVO,Pince_H_Serre,&Consigne74);
Consigne Consigne72(Bras,TIMEOUT_BRAS,Bras_Retracte,&Consigne73);
Consigne Consigne71(Bras,TIMEOUT_BRAS,Bras_Pousse,&Consigne72);
Consigne Consigne70(Pince_H,TIMEOUT_SERVO,Pince_H_Desserre,&Consigne71);

Consigne Consigne69(825,1665,-90,&Consigne70);
Consigne Consigne68(1050,2400,230,&Consigne70);

Consigne Consigne67(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne68);
Consigne Consigne66(Pince_V,TIMEOUT_SERVO,Pince_V_Bourrage,&Consigne67);
Consigne Consigne65(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne66);
Consigne Consigne64(Chargeur_Cylindre,1000,Chargeur_UP,&Consigne65);

Consigne Consigne63(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne64);
Consigne Consigne62(Pince_V,TIMEOUT_SERVO,Pince_V_Bourrage,&Consigne63);
Consigne Consigne61(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne62);
Consigne Consigne60(Chargeur_Cylindre,1000,Chargeur_UP,&Consigne61);

Consigne Consigne59(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne60);
Consigne Consigne58(Pince_V,TIMEOUT_SERVO,Pince_V_Bourrage,&Consigne59);
Consigne Consigne57(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne58);
//Consigne Consigne56(Chargeur_Cylindre,1000,Chargeur_UP,&Consigne57);


Consigne Consigne55(Chargeur_Cylindre,1000,Chargeur_UP,&Consigne57);
Consigne Consigne54(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne55);
Consigne Consigne53(Pince_V,TIMEOUT_SERVO,Pince_V_Bourrage,&Consigne54);
Consigne Consigne52(Pince_H,TIMEOUT_SERVO,Pince_H_Serre,&Consigne53);
Consigne Consigne51(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne52);
Consigne Consigne50(Pince_H,TIMEOUT_SERVO,Pince_H_Gauche_Desserre,&Consigne51);
Consigne Consigne49(Pince_H,TIMEOUT_SERVO,Pince_H_Droite_Desserre,&Consigne50);
Consigne Consigne48(Pince_V,TIMEOUT_SERVO,Pince_V_UP,&Consigne49);
Consigne Consigne47(Bras,1000,Bras_Retracte,&Consigne48);
Consigne Consigne46(Pince_H,TIMEOUT_SERVO,Pince_H_Serre,&Consigne47);
Consigne Consigne45(Bras,TIMEOUT_BRAS,Bras_Pousse,&Consigne46);
Consigne Consigne44(Pince_H,TIMEOUT_SERVO,Pince_H_Pousse,&Consigne45);
Consigne Consigne43(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne44);



Consigne Consigne42(Chargeur_Cylindre,1000,Chargeur_UP,&Consigne43);
Consigne Consigne41(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne42);
Consigne Consigne40(Pince_V,TIMEOUT_SERVO,Pince_V_Bourrage,&Consigne41);
Consigne Consigne39(Pince_H,TIMEOUT_SERVO,Pince_H_Serre,&Consigne40);
Consigne Consigne38(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne39);
Consigne Consigne37(Pince_H,TIMEOUT_SERVO,Pince_H_Gauche_Desserre,&Consigne38);
Consigne Consigne36(Pince_H,TIMEOUT_SERVO,Pince_H_Droite_Desserre,&Consigne37);
Consigne Consigne35(Pince_V,TIMEOUT_SERVO,Pince_V_UP,&Consigne36);
Consigne Consigne34(Bras,1000,Bras_Retracte,&Consigne35);
Consigne Consigne33(Pince_H,TIMEOUT_SERVO,Pince_H_Serre,&Consigne34);
Consigne Consigne32(Bras,TIMEOUT_BRAS,Bras_Pousse,&Consigne33);
Consigne Consigne31(Pince_H,TIMEOUT_SERVO,Pince_H_Pousse,&Consigne32);
Consigne Consigne30(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne31);


Consigne Consigne29(Chargeur_Cylindre,1000,Chargeur_UP,&Consigne30);
Consigne Consigne28(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne29);
Consigne Consigne27(Pince_V,TIMEOUT_SERVO,Pince_V_Bourrage,&Consigne28);
Consigne Consigne26(Pince_H,TIMEOUT_SERVO,Pince_H_Serre,&Consigne27);
Consigne Consigne25(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne26);
Consigne Consigne24(Pince_H,TIMEOUT_SERVO,Pince_H_Gauche_Desserre,&Consigne25);
Consigne Consigne23(Pince_H,TIMEOUT_SERVO,Pince_H_Droite_Desserre,&Consigne24);
Consigne Consigne22(Pince_V,TIMEOUT_SERVO,Pince_V_UP,&Consigne23);
Consigne Consigne21(Bras,1000,Bras_Retracte,&Consigne22);
Consigne Consigne20(Pince_H,TIMEOUT_SERVO,Pince_H_Serre,&Consigne21);
Consigne Consigne19(Bras,TIMEOUT_BRAS,Bras_Pousse,&Consigne20);
Consigne Consigne18(Pince_H,TIMEOUT_SERVO,Pince_H_Pousse,&Consigne19);
//Consigne Consigne17(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne18);

Consigne Consigne16(Chargeur_Cylindre,1000,Chargeur_UP,&Consigne18);
Consigne Consigne15(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne16);
Consigne Consigne14(Pince_V,TIMEOUT_SERVO,Pince_V_Bourrage,&Consigne15);
Consigne Consigne13(Pince_H,TIMEOUT_SERVO,Pince_H_Serre,&Consigne14);
Consigne Consigne12(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne13);
Consigne Consigne11(Pince_H,TIMEOUT_SERVO,Pince_H_Gauche_Desserre,&Consigne12);
Consigne Consigne10(Pince_H,TIMEOUT_SERVO,Pince_H_Droite_Desserre,&Consigne11);
Consigne Consigne9(Pince_V,TIMEOUT_SERVO,Pince_V_UP,&Consigne10);
Consigne Consigne8(Bras,1500,Bras_Retracte,&Consigne9);
Consigne Consigne7(Pince_H,TIMEOUT_SERVO,Pince_H_Serre,&Consigne8);
Consigne Consigne6(Bras,TIMEOUT_BRAS,Bras_Pousse,&Consigne7);
Consigne Consigne5(Pince_H,TIMEOUT_SERVO,Pince_H_Pousse,&Consigne6);
Consigne Consigne4(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne5);
Consigne Consigne200(270,2000,90,&Consigne68);
Consigne Consigne3(270,2000,90,&Consigne200);
Consigne Consigne2(270,2225,180,&Consigne3);
Consigne Consigne1(Pince_V,300,Pince_V_UP,&Consigne2);

#endif


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
