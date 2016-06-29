void mise_a_jour_robot()
{
  D_ancien=D;
G_ancien=G;
t_precedent=t_actuel;
t_actuel=millis();
delta_T=t_actuel-t_precedent;
recuperer(0);
recuperer(1);
mise_a_jour_POS();
}


void mise_a_jour_POS()
{
  float delta_D = (D_ancien - D)* PI * DIAMETRE_ROUE / TICCODEUSE; //En tic puis converti en mm
  float delta_G = (G_ancien - G)* PI * DIAMETRE_ROUE / TICCODEUSE; //En tic puis converti en mm
  float localX = 0, localY = 0;
  
  localX = (float)(((delta_D + delta_G) / 2.0f) * cos(angle_radian +(delta_D - delta_G) / float(2 * ECARTEMENT_ROUES)));//on parcourt cette distance avec l'angle initial
  localY = (float)(((delta_D + delta_G) / 2.0f) * sin(angle_radian +(delta_D - delta_G) / float(2 * ECARTEMENT_ROUES)));
  angle_radian += ((float)(delta_D - delta_G) / ECARTEMENT_ROUES); //Mise a jour de l'angle pour le prochain déplacement,toutes les distances doivent avoir les mêmes unités!
  while (angle_radian >= PI)angle_radian -= 2 * PI;
  while (angle_radian < -PI)angle_radian += 2 * PI;
  
  X_POS += int(localX);
  Y_POS += int(localY);
  ANGLE_POS = (angle_radian * 360 / (float)(2 * PI));
  Serial.println(X_POS);
  Serial.println(Y_POS);
  
  Serial.println(ANGLE_POS);
  


}
