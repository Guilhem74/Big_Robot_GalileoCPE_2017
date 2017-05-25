#ifndef Start1_YELLOW
#define Start1_YELLOW
#include "Consigne.h"
float X_POS = 0, Y_POS = 1930, ANGLE_POS = 270;

Consigne Consigne4500(Pince_V,100000,Pince_V_DOWN);
Consigne Consigne105(250,1850,80,TIMEOUT_DEPLACEMENT,&Consigne4500);

Consigne Consigne104(280,1930,80);

Consigne Consigne103(475,1897,80,TIMEOUT_DEPLACEMENT,&Consigne104);

Consigne Consigne102(711,2072,128,TIMEOUT_DEPLACEMENT,&Consigne103);

Consigne Consigne101(1011,2473,147,TIMEOUT_DEPLACEMENT,&Consigne102);

Consigne Consigne100(1395,2296,62,TIMEOUT_DEPLACEMENT,&Consigne101);

Consigne Consigne99(1455,2280,100,TIMEOUT_DEPLACEMENT,&Consigne100);
Consigne Consigne94000(Pince_H,TIMEOUT_SERVO,Pince_H_Desserre,&Consigne99);

Consigne Consigne990(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne94000);

Consigne Consigne98(1068,2200,96,TIMEOUT_DEPLACEMENT,&Consigne990);

Consigne Consigne97(Chargeur_Cylindre,1000,Chargeur_UP,&Consigne98);
Consigne Consigne96(Bras,TIMEOUT_BRAS,Bras_Retracte,&Consigne97);
Consigne Consigne95(Bras,TIMEOUT_BRAS,Bras_Pousse,&Consigne96);
Consigne Consigne940(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne95);
Consigne Consigne94(Pince_H,TIMEOUT_SERVO,Pince_H_Serre,&Consigne940);
Consigne Consigne93(Bras,TIMEOUT_BRAS,Bras_Retracte,&Consigne94);
Consigne Consigne92(Bras,TIMEOUT_BRAS,Bras_Pousse,&Consigne93);
Consigne Consigne91(Pince_H,TIMEOUT_SERVO,Pince_H_Dechargement,&Consigne92);

Consigne Consigne90(Chargeur_Cylindre,1000,Chargeur_UP,&Consigne91);
Consigne Consigne89(Bras,TIMEOUT_BRAS,Bras_Retracte,&Consigne90);
Consigne Consigne88(Bras,TIMEOUT_BRAS,Bras_Pousse,&Consigne89);
Consigne Consigne870(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne88);
Consigne Consigne87(Pince_H,TIMEOUT_SERVO,Pince_H_Serre,&Consigne870);
Consigne Consigne86(Bras,TIMEOUT_BRAS,Bras_Retracte,&Consigne87);
Consigne Consigne85(Bras,TIMEOUT_BRAS,Bras_Pousse,&Consigne86);
Consigne Consigne84(Pince_H,TIMEOUT_SERVO,Pince_H_Dechargement,&Consigne85);

Consigne Consigne83(Chargeur_Cylindre,1000,Chargeur_UP,&Consigne84);
Consigne Consigne82(Bras,TIMEOUT_BRAS,Bras_Retracte,&Consigne83);
Consigne Consigne81(Bras,TIMEOUT_BRAS,Bras_Pousse,&Consigne82);
Consigne Consigne800(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne81);
Consigne Consigne80(Pince_H,TIMEOUT_SERVO,Pince_H_Serre,&Consigne800);
Consigne Consigne79(Bras,TIMEOUT_BRAS,Bras_Retracte,&Consigne80);
Consigne Consigne78(Bras,TIMEOUT_BRAS,Bras_Pousse,&Consigne79);
Consigne Consigne77(Pince_H,TIMEOUT_SERVO,Pince_H_Dechargement,&Consigne78);

Consigne Consigne76(Chargeur_Cylindre,1000,Chargeur_UP,&Consigne77);
Consigne Consigne75(Bras,TIMEOUT_BRAS,Bras_Retracte,&Consigne76);
Consigne Consigne74(Bras,TIMEOUT_BRAS,Bras_Pousse,&Consigne75);
Consigne Consigne730(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne74);
Consigne Consigne73(Pince_H,TIMEOUT_SERVO,Pince_H_Serre,&Consigne730);
Consigne Consigne72(Bras,TIMEOUT_BRAS,Bras_Retracte,&Consigne73);
Consigne Consigne71(Bras,TIMEOUT_BRAS,Bras_Pousse,&Consigne72);
Consigne Consigne70(Pince_H,TIMEOUT_SERVO,Pince_H_Dechargement,&Consigne71);
Consigne Consigne696(1202,2048,225,TIMEOUT_DEPLACEMENT,&Consigne70);
Consigne Consigne5601(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne696);
Consigne Consigne69500(1207,2048,225,TIMEOUT_DEPLACEMENT,&Consigne5601);

Consigne Consigne695(963,2309,226,TIMEOUT_DEPLACEMENT,&Consigne69500);
Consigne Consigne5600(Pince_V,TIMEOUT_SERVO,Pince_V_UP,&Consigne695);

Consigne Consigne694(Pince_H,TIMEOUT_SERVO,Pince_H_Desserre,&Consigne695);
Consigne Consigne69300(824,2191,150,TIMEOUT_DEPLACEMENT,&Consigne694);

Consigne Consigne693(930,2300,150,TIMEOUT_DEPLACEMENT,&Consigne69300);

Consigne Consigne692(Pince_H,TIMEOUT_SERVO,Pince_H_Serre,&Consigne693);

Consigne Consigne691(1207,2048,225,TIMEOUT_DEPLACEMENT,&Consigne692);

Consigne Consigne690(963,2309,224,TIMEOUT_DEPLACEMENT,&Consigne691);

Consigne Consigne69(Pince_H,TIMEOUT_SERVO,Pince_H_Pousse,&Consigne690);
Consigne Consigne68(712,1723,159,&Consigne69);
Consigne Consigne67(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne68);
Consigne Consigne66(Pince_V,TIMEOUT_SERVO,Pince_V_Bourrage,&Consigne67);
Consigne Consigne65(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne66);
Consigne Consigne64(Chargeur_Cylindre,1000,Chargeur_UP,&Consigne65);

Consigne Consigne63(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne64);
Consigne Consigne62(Pince_V,TIMEOUT_SERVO,Pince_V_Bourrage,&Consigne63);
Consigne Consigne61(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne62);
Consigne Consigne60(Chargeur_Cylindre,1000,Chargeur_UP,&Consigne68);

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
Consigne Consigne200(220,1930-225,90,TIMEOUT_DEPLACEMENT,&Consigne4);

Consigne Consigne3(270,1930-225,90,TIMEOUT_DEPLACEMENT,&Consigne200);
Consigne Consigne2(270,1930,180,TIMEOUT_DEPLACEMENT,&Consigne3);

Consigne Consigne1(Pince_V,300,Pince_V_DOWN,&Consigne2);
#endif
