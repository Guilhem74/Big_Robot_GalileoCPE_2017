#ifndef Start1_BLUE
#define Start1_BLUE
#include "Consigne.h"

float X_POS = 0, Y_POS = 1070, ANGLE_POS = 90;

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
Consigne Consigne91(Pince_H,TIMEOUT_SERVO,Pince_H_Dechargement,&Consigne92);

Consigne Consigne90(Chargeur_Cylindre,1000,Chargeur_UP,&Consigne91);
Consigne Consigne89(Bras,TIMEOUT_BRAS,Bras_Retracte,&Consigne90);
Consigne Consigne88(Bras,TIMEOUT_BRAS,Bras_Pousse,&Consigne89);
Consigne Consigne87(Pince_H,TIMEOUT_SERVO,Pince_H_Serre,&Consigne88);
Consigne Consigne86(Bras,TIMEOUT_BRAS,Bras_Retracte,&Consigne87);
Consigne Consigne85(Bras,TIMEOUT_BRAS,Bras_Pousse,&Consigne86);
Consigne Consigne84(Pince_H,TIMEOUT_SERVO,Pince_H_Dechargement,&Consigne85);

Consigne Consigne83(Chargeur_Cylindre,1000,Chargeur_UP,&Consigne84);
Consigne Consigne82(Bras,TIMEOUT_BRAS,Bras_Retracte,&Consigne83);
Consigne Consigne81(Bras,TIMEOUT_BRAS,Bras_Pousse,&Consigne82);
Consigne Consigne80(Pince_H,TIMEOUT_SERVO,Pince_H_Serre,&Consigne81);
Consigne Consigne79(Bras,TIMEOUT_BRAS,Bras_Retracte,&Consigne80);
Consigne Consigne78(Bras,TIMEOUT_BRAS,Bras_Pousse,&Consigne79);
Consigne Consigne77(Pince_H,TIMEOUT_SERVO,Pince_H_Dechargement,&Consigne78);

Consigne Consigne76(Chargeur_Cylindre,1000,Chargeur_UP,&Consigne77);
Consigne Consigne75(Bras,TIMEOUT_BRAS,Bras_Retracte,&Consigne76);
Consigne Consigne74(Bras,TIMEOUT_BRAS,Bras_Pousse,&Consigne75);
Consigne Consigne73(Pince_H,TIMEOUT_SERVO,Pince_H_Serre,&Consigne74);
Consigne Consigne72(Bras,TIMEOUT_BRAS,Bras_Retracte,&Consigne73);
Consigne Consigne71(Bras,TIMEOUT_BRAS,Bras_Pousse,&Consigne72);
Consigne Consigne70(Pince_H,TIMEOUT_SERVO,Pince_H_Dechargement,&Consigne71);
/*Dechargement*/
Consigne Consigne69(840,1670,-90,&Consigne70);

Consigne Consigne400(400,1670,-90,&Consigne69);
Consigne Consigne68(180,1290,120 ,&Consigne400);

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
Consigne Consigne3000(Chargeur_Cylindre,1000,Chargeur_UP,&Consigne4);
Consigne Consigne3(180,1300,90 ,&Consigne675);
Consigne Consigne2(120,1070,130,&Consigne3);
Consigne Consigne1(Pince_V,TIMEOUT_SERVO,Pince_V_UP,&Consigne2);
#endif
