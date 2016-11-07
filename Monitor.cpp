#include <QWidget>
#include "Monitor.h"
#include "Window.h"

Monitor::Monitor(Window *parent): QFrame()
{
    this->parent = parent;
    this->init();
}

Monitor::Monitor(QString s, Window *parent, qint16 id): QFrame(), ip(s), id(id)
{
    this->parent = parent;
    this->init();
   // this->id = id;
   // this->ip = s;
}

 void Monitor::init()
{
    setFixedSize(WW, DOS_H);
    setStyleSheet("background-color:slategrey;color:black;");
    vLayout = new QVBoxLayout(this);
    vLayout->setContentsMargins(0,0,0,0);
    panel = new QWidget();
    //panel->move(0, 0);
    panel->setFixedSize(WW, PANEL_H);
    layout = new QHBoxLayout(panel);
    layout->setContentsMargins(1,1,1,1);
    ipDisplay = new QLabel(ip);
    QString number = QString("%1").arg(1, 6, 10, QChar('0'));

    lcd = new QLCDNumber();
    //lcd->setSmallDecimalPoint(true);
    lcd->setDigitCount(7);
    lcd->display(number);
    lcd->setFixedSize(LCD_W*2, PANEL_H-6);
    lcd->setSegmentStyle(QLCDNumber::Flat);
    lcd->setStyleSheet("background-color:#699363; color:charcoal; border: 1px solid charcoal;");
    msv = new QLabel("mSv");
    bar = new QProgressBar();
    bar->setStyleSheet("background-color:black;color:green;");
    bar->setFixedSize(WW, BAR_H);
    bar->setRange(0001, 100000);
    bar->setValue(1);
    bar->setTextVisible(0);
    bar->move(0, 0);
    control = new QSlider(Qt::Horizontal, this);
    control->setGeometry(100, 10, 150, 20);

    //slider->setGeometry(100, 10, 150, 20);
    control->setRange(0001,100000);


    QPushButton *bouton = new QPushButton("Reconnecter");
    layout->addWidget(ipDisplay);

    layout->addWidget(control);
    layout->addWidget(lcd);
    layout->addWidget(msv);
    lcd->setDigitCount(7);
    //lcd->display(0.0001);
    layout->addWidget(bouton);
    vLayout->addWidget(panel);
    vLayout->addWidget(bar);

    bouton->setStyleSheet("background-color:darkgrey;color:charcoal;");
    bouton->setCursor(Qt::PointingHandCursor);

    QObject::connect(bouton, &QPushButton::clicked, this, &Monitor::remove);

    QObject::connect(control, SIGNAL(valueChanged(int)), this, SLOT(changeRadioActivite(int)));
    QObject::connect(this, SIGNAL(valueChanged(QString)), lcd, SLOT(display(QString)));
    QObject::connect(control, SIGNAL(valueChanged(int)), bar, SLOT(setValue(int)));
}

 void Monitor::remove(qint16 id)
 {
    //QVector<Monitor*> monitors (this->parent->monitors);

     if(this->parent->monitors.size() > 0){
        this->layout->removeWidget(this);
        this->parent->setFixedHeight(this->parent->height() - PANEL_H - BAR_H);
        this->parent->monitors.erase(this->parent->monitors.begin() + id);

        qDebug() << "taille de fenetre" << this->parent->height();
        qDebug() << "Taille moniteur : " << this->parent->monitors.size();

        delete(this);
     }
 }

 void Monitor::setId(qint16 id)
 {
        this->id = id;
 }

 qint16 Monitor::getId()
 {
        return this->id;
 }

 void Monitor::changeRadioActivite(int rad)
 {
     double dRad  = (double)rad;
     radiation = rad;
     dRad = dRad/1000;
     radioactivite = QString("%1").arg(dRad, 0, 'F', 3);
     qDebug() << "Radio-activité : "<< this->radioactivite;
     emit valueChanged(this->radioactivite);
 }

 QString Monitor::getRadioActivite()
 {
     return radioactivite;
 }





