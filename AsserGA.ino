#include "define.h"


void setup() {
setup_asservissement();
}


void loop() {
mise_a_jour_robot();
/*
vitesse_D=1000*((D-D_ancien)*PI*DIAMETRE_ROUE/(TIC_CODEUSES*delta_T));//Vitesse mm par seconde
vitesse_G=1000*((G-G_ancien)*PI*DIAMETRE_ROUE/(TIC_CODEUSES*delta_T));//Vitesse mm par seconde
*/
 asservissement_robot();
}


