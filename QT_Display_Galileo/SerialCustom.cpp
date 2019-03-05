#include "SerialCustom.h"
#include "define.h"
#include "iostream"
void splitString(string message, char separator,string* data) ;
SerialCustom::SerialCustom()
{
    Taille_vecteur=0;
    QTextStream standardOutput(stdout);
    /*Paramétrage Port Serie*/
    QString serialPortName = SERIAL_PORT_NAME;
    serialPort.setPortName(serialPortName);
    y1_vect.reserve(5000);
    y2_vect.reserve(5000);
    x0_vect.reserve(5000);
    connect(&serialPort, SIGNAL(readyRead()), this, SLOT(read()));//connexion de l'interruption sur reception de donnees

    int serialPortBaudRate =  QSerialPort::BAUDRATE;
    serialPort.setBaudRate(serialPortBaudRate);
    if (!serialPort.open(QIODevice::ReadWrite )) {
        standardOutput << QObject::tr("Failed to open port %1, error: %2").arg(serialPortName).arg(serialPort.errorString()) << endl;
        //abort();
        return ;
    }
    serialPort.setDataTerminalReady(true);
}

void SerialCustom::write(char *seq)
{
    QTextStream standardOutput(stdout);
    serialPort.write(seq);
    serialPort.waitForBytesWritten(5000);
    return;
}
void SerialCustom::read()
{

    QTextStream standardOutput(stdout);
    do{
        readData.append(serialPort.readAll());//Concaténation
    }while(serialPort.waitForReadyRead(0.0001));
    if (!readData.contains('\n')||readData.size()<4)
    {//Chaine recue incomplete
        return;
    }
    else
    {//Chaine complete
        Analyse_Buffer();
    }
//    cout<<"Post_read"<<endl;

    return ;
}

void SerialCustom::Analyse_Buffer()
{
    if (!readData.contains('\n'))
    {//Plus rien a analyser
        return;
    }
    int position=readData.indexOf('\n');

    if(position==0)//un '\n' traine en debut de la chaine
    {
        readData.remove(0,1);
        SerialCustom::Analyse_Buffer();//on réanalyse
        return;
    }
    QByteArray Cache=readData;//on copie la chaine
    Cache.truncate(position);//On veut juste la chaine jusqu'a \n
    int position2=Cache.indexOf('X');
    Cache.remove(0,position2);//on enleve le potentiel bruit present avant le caractere de debut

    //cout<<position<<" Init: "<<readData.data()<<endl ;
    readData.remove(0,position);//On supprime la chaine qu'on a recupéré
    //cout<<"Retenu "<< Cache.data()<<endl;
    Stockage_Valeur(Cache.data());//on stocke les valeurs qu'on a recupéré
    if (readData.contains('\n')&&readData.size()>4)
    {//Il reste des éléments a analyser
        //cout<<"Chaine restante :"<< readData.data();
        if(readData.size()>400)
        {//Trop d'élément, on a pris trop de retard
            readData.clear();
            cout<<"Too much timeout"<<endl;

        }
        SerialCustom::Analyse_Buffer();
    }
    else
    {//on a fini de traiter le buffer
        //cout<<"Analyse terminé"<<endl;
        emit Fin_analyse();
        return;
    }
}
void SerialCustom::Stockage_Valeur(QByteArray Info)
{

    //traitement de la chaine
    char* t=Info.data();
    //cout<<"Ready";
    double Y1=0,Y2=0;
    sscanf(t,"X;%lf;%lf\n",&Y1,&Y2);
    y1_vect.append(Y1);
    y2_vect.append(Y2);
    x0_vect.append(Taille_vecteur);
    Taille_vecteur++;

}

void splitString(string message, char separator,string* data) {
    int index = 0;
    for(int i=0; i<10;i++)
    {
        data[i]="";
    }
    int cnt = 0;
    do {
        index = message.find(separator);
        if(index != -1) {// s'il y a bien un caractère séparateu
            // on découpe la chaine et on stocke le bout dans le tableau
            data[cnt] = message.substr(0,index);
            cnt++;
            // on enlève du message le bout stocké
            message = message.substr(index+1, message.length());
        } else {
            // après le dernier espace
            // on s'assure que la chaine n'est pas vide
            if(message.length() > 0) {

                data[cnt] = message.substr(0,index); // dernier bout
                cnt++;
            }
        }
    } while(index >=0); // tant qu'il y a bien un séparateur dans la chaine

}
