#include <AFMotor.h>

AF_DCMotor motor1(1, MOTOR12_64KHZ); // create motor #2, 64KHz pwm
AF_DCMotor motor2(2, MOTOR12_64KHZ); // create motor #2, 64KHz pwm

unsigned long tempsstop; 

int antioptimisationauto = 0;

int pinA1 = 18; //Encoder pin A connects to interrupt 0 (D2)
int pinB1 = 20; //Encoder pin B connects to D4
int iValue1 = 0; //A variable that will be increased or decreased
                //when we turn the encoder
int pinA2 = 19; //Encoder pin A connects to interrupt 0 (D2)
int pinB2 = 21; //Encoder pin B connects to D4
int iValue2 = 0; //A variable that will be increased or decreased
                //when we turn the encoder
int MAXDEPASS = 5; // depassement maximal d'une roue sur l'autre en click de codeuse

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Motor test!");

  pinMode(pinA1, INPUT);  
  pinMode(pinB1, INPUT);
  pinMode(pinA2, INPUT);  
  pinMode(pinB2, INPUT);
  
  // Enable interrupt on encoder pin A
  // Trigger at RISING if your encoder stops (clicks) only at high pulse
  // Trigger at CHANGE if your encoder stops (clicks) at both high and low
  // positions or if it has no stops
  attachInterrupt(digitalPinToInterrupt(pinA1), encoderClick1, RISING);
  attachInterrupt(digitalPinToInterrupt(pinA2), encoderClick2, RISING);
  
  // Alerte au code sale !!!!!!!!!!!!!!§§!!!

  // pour copenser un defaut de la carte ???
  
  motor1.setSpeed(250);     // set the speed to 200/255
  motor2.setSpeed(255);     // set the speed to 200/255

  
}

void loop() {

tracetaroutebro(100);
resetcodeuse();
tournemongars(50);
resetcodeuse();


delay(20000);



}

void resetcodeuse()
{
    iValue1 = 0;
    iValue2 = 0;  
}


// positif => sens horaire
void tournemongars(int nbclick)
{
  if (nbclick > 0)
  {
    motor1.run(FORWARD);
    motor2.run(BACKWARD);
    while (iValue1 < nbclick)
    {
      Serial.println("processing ....antioptimisationauto");
    }
  }
  else
  {
    motor1.run(BACKWARD);
    motor2.run(FORWARD);
    while (iValue2 < nbclick)
    {
      Serial.println("processing ....antioptimisationauto");
    }
  }

motor1.run(RELEASE);
motor2.run(RELEASE); 
Serial.println("objectif  virage :");
Serial.print(nbclick);
Serial.println("realise (M1 et M2):");
Serial.println(iValue1);
Serial.println(iValue2);
 
}





void tracetaroutebro(int distance)
{
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  while (iValue1 < distance)
    {
    if (iValue1 - iValue2 > MAXDEPASS)
    {
      while(iValue1 > iValue2)
      {
      motor1.run(RELEASE);
      }
      motor1.run(FORWARD);
    }
    
    if (iValue2 - iValue1 > MAXDEPASS)
    {
      while(iValue2 > iValue1)
      {
      motor2.run(RELEASE);
      }
      motor2.run(FORWARD);
    }

}

motor1.run(RELEASE);
motor2.run(RELEASE); 
Serial.println("objectif tout droit :");
Serial.print(distance);
Serial.println("realise (M1 et M2):");
Serial.println(iValue1);
Serial.println(iValue2);

}



void encoderClick1(){
  // encoder must have turned one click because interrupt 0 was triggered
  // read value from both encoder pins
  int valA = digitalRead(pinA1);
  int valB = digitalRead(pinB1);
  
  // compare pins to determine in which direction encoder was turned
  if (valA != valB){
      // pinA just changed but pinB had not yet changed
      // Direction must be clockwise if A changes before B
      iValue1++;
  }
  else{
      // pinA just changed and pinB had already done so.
      // Direction must be counter-clockwise if B changes before A
      iValue1--;
  }
}



void encoderClick2(){
  // encoder must have turned one click because interrupt 0 was triggered
  // read value from both encoder pins
  int valA = digitalRead(pinA2);
  int valB = digitalRead(pinB2);
  
  // compare pins to determine in which direction encoder was turned
  if (valA != valB){
      // pinA just changed but pinB had not yet changed
      // Direction must be clockwise if A changes before B
      iValue2--;
  }
  else{
      // pinA just changed and pinB had already done so.
      // Direction must be counter-clockwise if B changes before A
      iValue2++;
  }
}
