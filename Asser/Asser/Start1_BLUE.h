#ifndef Start1_BLUE
#define Start1_BLUE
#include "Consigne.h"

float X_POS = 0, Y_POS = 770, ANGLE_POS = -90;
/*Consigne Consigne9500(Bras,TIMEOUT_BRAS,Bras_Retracte);
Consigne Consigne9400(Pince_V,TIMEOUT_SERVO,Pince_V_Bourrage,&Consigne9500);
Consigne Consigne9200(Bras,TIMEOUT_BRAS,Bras_Pousse,&Consigne9400);
Consigne Consigne9100(Pince_H,TIMEOUT_SERVO,Pince_H_Dechargement,&Consigne9200);
Consigne Consigne102(1250,670,-45,&Consigne9100);
Consigne Consigne101(1071,430,-44,TIMEOUT_DEPLACEMENT,&Consigne102);
Consigne Consigne100(969,248,-45,TIMEOUT_DEPLACEMENT,&Consigne101);

Consigne Consigne799(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne100);
Consigne Consigne798(Pince_V,TIMEOUT_SERVO,Pince_V_Bourrage,&Consigne799);
Consigne Consigne797(Pince_H,TIMEOUT_SERVO,Pince_H_Serre,&Consigne798);
Consigne Consigne796(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne797);
Consigne Consigne795(Pince_H,TIMEOUT_SERVO,Pince_H_Gauche_Desserre,&Consigne796);
Consigne Consigne794(Pince_H,TIMEOUT_SERVO,Pince_H_Droite_Desserre,&Consigne795);
Consigne Consigne793(Pince_V,TIMEOUT_SERVO,Pince_V_UP,&Consigne794);
1530 566 -76
A Final -217
1260 260 -274
900 281-345
760 815 -270
310 920 -265*/

/*Consigne Consigne9877(310,940,90);
Consigne Consigne9875(900,815,80,TIMEOUT_DEPLACEMENT,&Consigne9877);
Consigne Consigne560412(Pince_V,TIMEOUT_SERVO,Pince_V_UP,&Consigne9875);
Consigne Consigne98750(830,515,30,TIMEOUT_DEPLACEMENT,&Consigne560412);
Consigne Consigne9874(960,281,30,TIMEOUT_DEPLACEMENT,&Consigne98750);
Consigne Consigne9873(1260,260,80,TIMEOUT_DEPLACEMENT,&Consigne9875);
Consigne Consigne9872(Pince_H,TIMEOUT_SERVO,Pince_H_Desserre,&Consigne9873);
Consigne Consigne9871(1489,440,160,TIMEOUT_DEPLACEMENT,&Consigne9872);*/

Consigne Consigne970(Chargeur_Cylindre,TIMEOUT_CYLINDRE,Chargeur_UP);
Consigne Consigne8074(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne970);
Consigne Consigne960(Bras,TIMEOUT_BRAS,Bras_Retracte,&Consigne8074);
Consigne Consigne5604(Pince_V,TIMEOUT_SERVO,Pince_V_Bourrage,&Consigne960);
Consigne Consigne950(Bras,TIMEOUT_BRAS,Bras_Pousse,&Consigne960);
Consigne Consigne940(Pince_H,TIMEOUT_SERVO,Pince_H_Serre,&Consigne950);
Consigne Consigne602745(1108,475,-135,TIMEOUT_DEPLACEMENT,&Consigne940);
Consigne Consigne930(Bras,TIMEOUT_BRAS,Bras_Retracte,&Consigne940);
Consigne Consigne5604159(Pince_V,TIMEOUT_SERVO,Pince_V_Bourrage,&Consigne930);
Consigne Consigne920(Bras,TIMEOUT_BRAS,Bras_Pousse,&Consigne5604159);
Consigne Consigne910(Pince_H,TIMEOUT_SERVO,Pince_H_Dechargement,&Consigne920);


Consigne Consigne605159(1250,670,-45,TIMEOUT_DEPLACEMENT,&Consigne910);
Consigne Consigne98123(968,362,-45,TIMEOUT_DEPLACEMENT,&Consigne605159);

Consigne Consigne799(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne98123);
Consigne Consigne798(Pince_V,TIMEOUT_SERVO,Pince_V_Bourrage,&Consigne799);
Consigne Consigne797(Pince_H,TIMEOUT_SERVO,Pince_H_Serre,&Consigne798);
Consigne Consigne796(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne797);
Consigne Consigne795(Pince_H,TIMEOUT_SERVO,Pince_H_Gauche_Desserre,&Consigne796);
Consigne Consigne794(Pince_H,TIMEOUT_SERVO,Pince_H_Droite_Desserre,&Consigne795);
Consigne Consigne793(Pince_V,TIMEOUT_SERVO,Pince_V_UP,&Consigne794);

Consigne Consigne792(Pince_H,TIMEOUT_SERVO,Pince_H_Serre,&Consigne793);
Consigne Consigne99(1589,580,-75,TIMEOUT_DEPLACEMENT,&Consigne792);
Consigne Consigne111(Pince_H,TIMEOUT_SERVO,Pince_H_Pousse,&Consigne99);
Consigne Consigne98(968,362,-71,TIMEOUT_DEPLACEMENT,&Consigne111);

/*Consigne Consigne102(203,786,-270);
Consigne Consigne101(670,783,-271,TIMEOUT_DEPLACEMENT,&Consigne102);
Consigne Consigne100(969,248,-335,TIMEOUT_DEPLACEMENT,&Consigne101);
Consigne Consigne99(1234,333,-262,TIMEOUT_DEPLACEMENT,&Consigne100);
Consigne Consigne98(1065,468,-135,TIMEOUT_DEPLACEMENT,&Consigne99);*/



Consigne Consigne8073735(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne98);
Consigne Consigne96987(Bras,TIMEOUT_BRAS,Bras_Retracte,&Consigne8073735);
Consigne Consigne560312(Pince_V,TIMEOUT_SERVO,Pince_V_Bourrage,&Consigne96987);
Consigne Consigne954569(Bras,TIMEOUT_BRAS,Bras_Pousse,&Consigne560312);

Consigne Consigne97(Chargeur_Cylindre,TIMEOUT_CYLINDRE,Chargeur_UP,&Consigne954569);
Consigne Consigne8073(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne97);
Consigne Consigne96(Bras,TIMEOUT_BRAS,Bras_Retracte,&Consigne8073);
Consigne Consigne5603(Pince_V,TIMEOUT_SERVO,Pince_V_Bourrage,&Consigne96);
Consigne Consigne95(Bras,TIMEOUT_BRAS,Bras_Pousse,&Consigne5603);
Consigne Consigne94(Pince_H,TIMEOUT_SERVO,Pince_H_Serre,&Consigne95);
Consigne Consigne56004(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne94);
Consigne Consigne93(Bras,TIMEOUT_BRAS,Bras_Retracte,&Consigne56004);
Consigne Consigne4803(Pince_V,TIMEOUT_SERVO,Pince_V_Bourrage,&Consigne93);
Consigne Consigne92(Bras,TIMEOUT_BRAS,Bras_Pousse,&Consigne4803);
Consigne Consigne91(Pince_H,TIMEOUT_SERVO,Pince_H_Dechargement,&Consigne92);

Consigne Consigne90(Chargeur_Cylindre,TIMEOUT_CYLINDRE,Chargeur_UP,&Consigne91);
Consigne Consigne8072(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne90);
Consigne Consigne89(Bras,TIMEOUT_BRAS,Bras_Retracte,&Consigne8072);
Consigne Consigne5602(Pince_V,TIMEOUT_SERVO,Pince_V_Bourrage,&Consigne89);
Consigne Consigne88(Bras,TIMEOUT_BRAS,Bras_Pousse,&Consigne5602);
Consigne Consigne87(Pince_H,TIMEOUT_SERVO,Pince_H_Serre,&Consigne88);
Consigne Consigne56003(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne87);
Consigne Consigne86(Bras,TIMEOUT_BRAS,Bras_Retracte,&Consigne56003);
Consigne Consigne4802(Pince_V,TIMEOUT_SERVO,Pince_V_Bourrage,&Consigne86);
Consigne Consigne85(Bras,TIMEOUT_BRAS,Bras_Pousse,&Consigne4802);
Consigne Consigne84(Pince_H,TIMEOUT_SERVO,Pince_H_Dechargement,&Consigne85);

Consigne Consigne83(Chargeur_Cylindre,TIMEOUT_CYLINDRE,Chargeur_UP,&Consigne84);
Consigne Consigne8071(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne83);
Consigne Consigne82(Bras,TIMEOUT_BRAS,Bras_Retracte,&Consigne8071);
Consigne Consigne5601(Pince_V,TIMEOUT_SERVO,Pince_V_Bourrage,&Consigne82);
Consigne Consigne81(Bras,TIMEOUT_BRAS,Bras_Pousse,&Consigne5601);
Consigne Consigne80(Pince_H,TIMEOUT_SERVO,Pince_H_Serre,&Consigne81);
Consigne Consigne56002(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne80);
Consigne Consigne79(Bras,TIMEOUT_BRAS,Bras_Retracte,&Consigne56002);
Consigne Consigne4801(Pince_V,TIMEOUT_SERVO,Pince_V_Bourrage,&Consigne79);
Consigne Consigne78(Bras,TIMEOUT_BRAS,Bras_Pousse,&Consigne4801);
Consigne Consigne77(Pince_H,TIMEOUT_SERVO,Pince_H_Dechargement,&Consigne78);


Consigne Consigne76(Chargeur_Cylindre,TIMEOUT_CYLINDRE,Chargeur_UP,&Consigne77);
Consigne Consigne8070(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne76);
Consigne Consigne75(Bras,TIMEOUT_BRAS,Bras_Retracte,&Consigne8070);
Consigne Consigne561(Pince_V,TIMEOUT_SERVO,Pince_V_Bourrage,&Consigne75);
Consigne Consigne74(Bras,TIMEOUT_BRAS,Bras_Pousse,&Consigne561);
Consigne Consigne73(Pince_H,TIMEOUT_SERVO,Pince_H_Serre,&Consigne74);
Consigne Consigne56001(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne73);
Consigne Consigne72(Bras,TIMEOUT_BRAS,Bras_Retracte,&Consigne56001);
Consigne Consigne4800(Pince_V,TIMEOUT_SERVO,Pince_V_Bourrage,&Consigne72);
Consigne Consigne71(Bras,TIMEOUT_BRAS,Bras_Pousse,&Consigne4800);
Consigne Consigne70(Pince_H,TIMEOUT_SERVO,Pince_H_Dechargement,&Consigne71);


/*Consigne Consigne605(1250,670,-45,TIMEOUT_DEPLACEMENT,&Consigne98);
Consigne Consigne56000(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne605);
Consigne Consigne604(1054,507,-45,2000,&Consigne56000);
Consigne Consigne5600(Pince_V,TIMEOUT_SERVO,Pince_V_UP,&Consigne604);
Consigne Consigne694(Pince_H,TIMEOUT_SERVO,Pince_H_Desserre,&Consigne5600);
Consigne Consigne603(1117,308,-135,TIMEOUT_DEPLACEMENT,&Consigne694);
Consigne Consigne602(1108,475,-135,TIMEOUT_DEPLACEMENT,&Consigne603);*/
Consigne Consigne97311(1210,640,-45,TIMEOUT_DEPLACEMENT,&Consigne70);
Consigne Consigne698701(1300,700,-45,TIMEOUT_DEPLACEMENT,&Consigne97311);
Consigne Consigne9632(Pince_H,TIMEOUT_SERVO,Pince_H_Serre,&Consigne698701);
Consigne Consigne9134(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne9632);
Consigne Consigne56000(1104,536,-46,TIMEOUT_DEPLACEMENT,&Consigne9134);
/*Consigne Consigne604(950,393,-42,TIMEOUT_DEPLACEMENT,&Consigne56000);
Consigne Consigne5600(670,90,-40,TIMEOUT_DEPLACEMENT,&Consigne604);
Consigne Consigne750753(Pince_H,TIMEOUT_SERVO,Pince_H_Pousse,&Consigne5600);
Consigne Consigne694(712,719,-0,TIMEOUT_DEPLACEMENT,&Consigne750753);
Consigne Consigne603(612,154,-17,TIMEOUT_DEPLACEMENT,&Consigne694);
Consigne Consigne602(1045,393,-42,TIMEOUT_DEPLACEMENT,&Consigne603);*/

Consigne Consigne692896(Pince_H,TIMEOUT_SERVO,Pince_H_Desserre,&Consigne56000);
Consigne Consigne601(1250,670,-45,TIMEOUT_DEPLACEMENT,false,&Consigne692896);
Consigne Consigne7503557(Pince_H,TIMEOUT_SERVO,Pince_H_Gauche_Desserre,&Consigne601);
Consigne Consigne750(Pince_V,TIMEOUT_SERVO,Pince_V_droite_up,&Consigne7503557);
Consigne Consigne692985(Pince_H,TIMEOUT_SERVO,Pince_H_Serre,&Consigne750);

Consigne Consigne60000(1104,536,-46,TIMEOUT_DEPLACEMENT,&Consigne692985);
Consigne Consigne6000(1004,436,-46,TIMEOUT_DEPLACEMENT,&Consigne750);

Consigne Consigne600(600,900,-100,TIMEOUT_DEPLACEMENT,&Consigne6000);


Consigne Consigne67(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne600);
Consigne Consigne66(Pince_V,TIMEOUT_SERVO,Pince_V_Bourrage,&Consigne67);
Consigne Consigne65(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne66);
Consigne Consigne64(Chargeur_Cylindre,TIMEOUT_CYLINDRE,Chargeur_UP,&Consigne65);

Consigne Consigne63(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne64);
Consigne Consigne62(Pince_V,TIMEOUT_SERVO,Pince_V_Bourrage,&Consigne63);
Consigne Consigne61(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne62);
Consigne Consigne60(Chargeur_Cylindre,TIMEOUT_CYLINDRE,Chargeur_UP,&Consigne61);

Consigne Consigne59(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne60);
Consigne Consigne58(Pince_V,TIMEOUT_SERVO,Pince_V_Bourrage,&Consigne59);
Consigne Consigne57(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne58);
//Consigne Consigne56(Chargeur_Cylindre,1000,Chargeur_UP,&Consigne57);


Consigne Consigne55(Chargeur_Cylindre,TIMEOUT_CYLINDRE,Chargeur_UP,&Consigne57);
Consigne Consigne54(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne55);
Consigne Consigne53(Pince_V,TIMEOUT_SERVO,Pince_V_Bourrage,&Consigne54);
Consigne Consigne52(Pince_H,TIMEOUT_SERVO,Pince_H_Serre,&Consigne53);
Consigne Consigne51(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne52);
Consigne Consigne50(Pince_H,TIMEOUT_SERVO+100,Pince_H_Gauche_Desserre,&Consigne51);
Consigne Consigne49(Pince_H,TIMEOUT_SERVO,Pince_H_Droite_Desserre,&Consigne50);
Consigne Consigne48(Pince_V,TIMEOUT_SERVO,Pince_V_UP,&Consigne49);
Consigne Consigne47(Bras,1000,Bras_Retracte,&Consigne48);
Consigne Consigne46(Pince_H,TIMEOUT_SERVO,Pince_H_Serre,&Consigne47);
Consigne Consigne45(Bras,TIMEOUT_BRAS,Bras_Pousse,&Consigne46);
Consigne Consigne44(Pince_H,TIMEOUT_SERVO,Pince_H_Pousse,&Consigne45);
Consigne Consigne43(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne44);



Consigne Consigne42(Chargeur_Cylindre,TIMEOUT_CYLINDRE,Chargeur_UP,&Consigne43);
/*Consigne Consigne41(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne42);
Consigne Consigne40(Pince_V,TIMEOUT_SERVO,Pince_V_Bourrage,&Consigne41);
Consigne Consigne39(Pince_H,TIMEOUT_SERVO,Pince_H_Serre,&Consigne40);*/
Consigne Consigne38(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne42);
Consigne Consigne37(Pince_H,TIMEOUT_SERVO,Pince_H_Gauche_Desserre,&Consigne38);
Consigne Consigne36(Pince_H,TIMEOUT_SERVO,Pince_H_Droite_Desserre,&Consigne37);
Consigne Consigne35(Pince_V,TIMEOUT_SERVO,Pince_V_UP,&Consigne36);
Consigne Consigne34(Bras,1000,Bras_Retracte,&Consigne35);
Consigne Consigne33(Pince_H,TIMEOUT_SERVO,Pince_H_Serre,&Consigne34);
Consigne Consigne32(Bras,TIMEOUT_BRAS,Bras_Pousse,&Consigne33);
Consigne Consigne31(Pince_H,TIMEOUT_SERVO,Pince_H_Pousse,&Consigne32);
Consigne Consigne30(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne31);


Consigne Consigne29(Chargeur_Cylindre,TIMEOUT_CYLINDRE,Chargeur_UP,&Consigne30);
/*Consigne Consigne28(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne29);
Consigne Consigne27(Pince_V,TIMEOUT_SERVO,Pince_V_Bourrage,&Consigne28);
Consigne Consigne26(Pince_H,TIMEOUT_SERVO,Pince_H_Serre,&Consigne27);*/
Consigne Consigne25(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne29);
Consigne Consigne24(Pince_H,TIMEOUT_SERVO,Pince_H_Gauche_Desserre,&Consigne25);
Consigne Consigne23(Pince_H,TIMEOUT_SERVO,Pince_H_Droite_Desserre,&Consigne24);
Consigne Consigne22(Pince_V,TIMEOUT_SERVO,Pince_V_UP,&Consigne23);
Consigne Consigne21(Bras,1000,Bras_Retracte,&Consigne22);
Consigne Consigne20(Pince_H,TIMEOUT_SERVO,Pince_H_Serre,&Consigne21);
Consigne Consigne19(Bras,TIMEOUT_BRAS,Bras_Pousse,&Consigne20);
Consigne Consigne18(Pince_H,TIMEOUT_SERVO,Pince_H_Pousse,&Consigne19);
//Consigne Consigne17(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne18);

/*1000 500 -45 prblm
1530 566 -76
A Final -217
1260 260 -274
900 281-345
760 815 -270
310 920 -265*/
Consigne Consigne16(Chargeur_Cylindre,TIMEOUT_CYLINDRE,Chargeur_UP,&Consigne18);
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
Consigne Consigne3000(Chargeur_Cylindre,TIMEOUT_CYLINDRE,Chargeur_UP,&Consigne4);
Consigne Consigne3(240,980,90,TIMEOUT_DEPLACEMENT,&Consigne3000);
Consigne Consigne2(240,770,0,TIMEOUT_DEPLACEMENT,&Consigne3);

Consigne Consigne1(Pince_V,TIMEOUT_SERVO,Pince_V_DOWN,&Consigne2);
#endif
