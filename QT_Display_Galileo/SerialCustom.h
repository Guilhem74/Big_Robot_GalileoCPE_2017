#ifndef SERIALCUSTOM_H
#define SERIALCUSTOM_H
#include <QtSerialPort/QtSerialPort>
using namespace std;

class SerialCustom : public QObject
{
    Q_OBJECT


public:
    QSerialPort serialPort;
    QVector<double> y1_vect, y2_vect, x0_vect;
    int Taille_vecteur;
    QByteArray readData;
    SerialCustom();
    void Stockage_Valeur(QByteArray Info);
    void Analyse_Buffer(void);
    void write(char* seq);

 public slots:
    void read();
 signals:
    void Fin_analyse();
};

#endif // SERIALCUSTOM_H
