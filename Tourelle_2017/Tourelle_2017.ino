#define RESOLUTION 64 //taille du tableau de detection multiple de 16!!!

boolean detecteur[RESOLUTION];
boolean detecteur_sauvegarde[RESOLUTION];
boolean analyse_over = 1;

int indice_detecteur = 0;

unsigned long clic_tour           = 0;
unsigned long clic_tour_precedent = 0;
int           tps_rotation        = 0;
unsigned long clic_objet          = 0;

int nb_objet;

boolean analyse_moi_ca = 0;

int compteur_detection_tiges=4;
int indices_tige[4];
int Avant=0;
int Arriere=0;
#define Intervalle_Min_AR 55
#define Intervalle_Max_AR 7
#define Intervalle_Min_AV 20
#define Intervalle_Max_AV 40
#define PIN_Detection_AVANT 4
#define PIN_Detection_ARRIERE 5
void setup() {
  Serial.begin(115200);  //début de la transmission
  delay(2000);//le temps de mettre en marche la tourelle
  pinMode(2,INPUT);
  pinMode(3,INPUT);
   pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  
  attachInterrupt(digitalPinToInterrupt(3),ISR_objet,FALLING);
  attachInterrupt(digitalPinToInterrupt(2),ISR_tour,RISING);
  reboot_tableaux();
          Serial.println("Init2");

}
void loop() {


    bool Avant_Detect=false;
     bool Arriere_Detect=false;
    delay(500);
    if(Avant>1)
    {
      Avant_Detect=true;
    }
      else
      {
        Avant_Detect=false;
      }
    digitalWrite(PIN_Detection_AVANT,Avant_Detect);
    Serial.println("D:"); 
    Serial.println(Avant_Detect);

    if(Arriere>1)
    {
      Arriere_Detect=true;
    }
      else
      {
        Arriere_Detect=false;
      }
      digitalWrite(PIN_Detection_ARRIERE,Arriere_Detect);
Serial.println(Arriere_Detect);


  reboot_tableaux();
}

void reboot_tableaux()
{
  for(int i =0;i<RESOLUTION;i++)
  {
    detecteur[i]=0;
  }
  Avant=0;
  Arriere=0;
}

void afficher_detecteur()
{
  for(int i =0;i<RESOLUTION;i++)
  {
    detecteur_sauvegarde[i] ? Serial.print('1'):Serial.print('0');
  }
  Serial.print(nb_objet);
  Serial.print("\n");
}

void ISR_objet(){

  clic_objet=millis();
  int delais_clic = clic_objet-clic_tour_precedent; 
  int indice = (delais_clic*RESOLUTION)/tps_rotation;
  if(indice<RESOLUTION)
  {
    detecteur[indice]=1;
    if(indice>Intervalle_Min_AR || indice<Intervalle_Max_AR)
    {
      Arriere++;
    }
    else if(indice>Intervalle_Min_AV  && indice<Intervalle_Max_AV)
    {
      Avant++;
    }

  }

  nb_objet++;
}

void ISR_tour()
{

  clic_tour=millis();
  if(nb_objet>0 && analyse_over)//demande une analyse du tableau par loop() si elle n'est pas déjà entrain de faire un truc
  {
    for (int i=0;i<RESOLUTION;i++)
    {
      detecteur_sauvegarde[(i+RESOLUTION/16)%RESOLUTION]=detecteur[i];
    }
    analyse_over = 0;
    analyse_moi_ca=1;    
  }
  tps_rotation=clic_tour - clic_tour_precedent;
  clic_tour_precedent=clic_tour;

  nb_objet=0;
}

