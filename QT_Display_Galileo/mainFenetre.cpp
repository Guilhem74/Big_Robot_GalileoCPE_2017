#include "mainFenetre.h"


mainFenetre::mainFenetre() : QWidget()
{

    setGeometry(200, 200,600,600);

           //affichage graphe
       //setMouseTracking(true);
           // add two new graphs and set their look:
           Rafraichissement=true;
           QGridLayout *layout = new QGridLayout;
           layout->addWidget(&Graph,0,0,2,2);
           Refresh = new QCheckBox("Raffraichissement du graph", this);

           layout->addWidget(Refresh,0,3,1,1);
           Refresh->setCheckState(Qt::Checked);
            connect(Refresh, SIGNAL(clicked()), this, SLOT(Chgmt_refresh()));
            QGraphicsScene* scene;
            QGraphicsView* view;
            QGraphicsPixmapItem* item;
            QImage image("Tablejeu.jpg");
           scene = new QGraphicsScene();
           view = new QGraphicsView(scene);

           view->setMouseTracking(true);
           //connect(view, SIGNAL(zoomIn()), this, SLOT(afficherPosition()));
           //view->mapFromGlobal();
           item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
            scene->addItem(item);
            //layout->addWidget(view,1,3,1,3);
           view->show();


           setLayout(layout);

           Graph.addGraph(); // blue line
           Graph.graph(0)->setPen(QPen(QColor(40, 110, 255)));
           Graph.addGraph(); // red line
           Graph.graph(1)->setPen(QPen(QColor(255, 110, 40)));

           Graph.axisRect()->setupFullAxesBox();
           Graph.yAxis->setRange(-1.2, 1.2);
           Graph.graph(0)->rescaleValueAxis();
           Graph.graph(1)->rescaleValueAxis(true);
           // make left and bottom axes transfer their ranges to right and top axes:
           connect(Graph.xAxis, SIGNAL(rangeChanged(QCPRange)), Graph.xAxis2, SLOT(setRange(QCPRange)));
           connect(Graph.yAxis, SIGNAL(rangeChanged(QCPRange)), Graph.yAxis2, SLOT(setRange(QCPRange)));
           // setup a timer that repeatedly calls MainWindow::realtimeDataSlot:
           connect(&MySerial, SIGNAL(Fin_analyse()), this, SLOT(Replot()));
            Graph.setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

}

void mainFenetre::Replot()
{

    double key = MySerial.Taille_vecteur; // time elapsed since start of demo, in seconds

     Graph.graph(0)->addData(key, MySerial.y1_vect[key-1]);
     Graph.graph(1)->addData(key, MySerial.y2_vect[key-1]);

     Graph.xAxis->setRange(key, Qt::AlignRight);
if(Rafraichissement)
{
     Graph.graph(0)->rescaleValueAxis();
     Graph.graph(1)->rescaleValueAxis(true);
     Graph.replot(QCustomPlot::rpQueuedRefresh);
}



}

void mainFenetre::Chgmt_refresh()
{
    Rafraichissement=!Rafraichissement;
}

void mainFenetre::mousePressEvent(QMouseEvent *e) // Fonction protected appartenant à QWidget
{

}
