#ifndef MAINFENETRE_H
#define MAINFENETRE_H
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include "qcustomplot.h"
#include "Customplot.h"
#include <QtSerialPort/QtSerialPort>
#include "SerialCustom.h"
#include <iostream>
#include <QLabel>
class mainFenetre : public QWidget
{
    Q_OBJECT
public:
    mainFenetre();
    SerialCustom MySerial;
    CustomPlot Graph;
    QCheckBox *Refresh;

    bool Rafraichissement;

private:
    QPushButton *m_bouton;
signals:

public slots:
    void Chgmt_refresh();
    void Replot();
    void mousePressEvent(QMouseEvent *e);
};

#endif // MAINFENETRE_H


