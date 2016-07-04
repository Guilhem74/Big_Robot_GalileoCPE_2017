#include "define.h"


void setup() {
setup_asservissement();
  pinMode(13, OUTPUT);
    digitalWrite(13, LOW);  
}


void loop() {
mise_a_jour_robot();
/*

*/
 asservissement_robot();
}


