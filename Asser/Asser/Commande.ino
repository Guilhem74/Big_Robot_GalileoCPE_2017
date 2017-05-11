#include "define.h"

void Setup_Commande()
{

  //Consigne[0].X_DEST=130;
  //Consigne[0].Y_DEST=1070;
  //Consigne[0].ANGLE_FINAL=135;
  Consigne[0].X_DEST=250;
  Consigne[0].Y_DEST=1070;
  Consigne[0].ANGLE_FINAL=90;
  Consigne[0].Derniere_Consigne=true;
  Consigne[0].consigne_suivante=&Consigne[0];
  Consigne_Actuel=&Consigne[0];
  int32_t dx=Consigne_Actuel->X_DEST-X_POS;
  int32_t dy=Consigne_Actuel->Y_DEST-Y_POS;
  Serial.println(dy);
  Serial.println(dx);
  DELTA_Consigne_Init=sqrt(dx*dx+dy*dy);

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

  Consigne_Actuel=&Consigne[0];

}
