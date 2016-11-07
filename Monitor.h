#ifndef Monitor_H
#define Monitor_H

#include <QApplication>
#include <QWidget>
#include <QString>
#include <QPushButton>
#include <QLCDNumber>
#include <QVBoxLayout>
#include <QFrame>
#include <QSlider>
#include <QLabel>
#include <QProgressBar>
#include <QWidget>
#include <QMainWindow>
#include <QLCDNumber>
#include <QDebug>

class Window;

class Monitor: public QFrame
{
    Q_OBJECT

    public:
    Monitor(Window *parent = 0);
    Monitor(QString s, Window *parent, qint16 id = 0);

    void init();
    void setIp(QString s);
    void setId(qint16 id);
    qint16 getId();
    QString getRadioActivite();

    public slots:

    void changeRadioActivite(int rad);
    void remove(qint16 id);

    signals:
    void valueChanged(QString);

    private:
   // int niveauRadiation; // pour Monitor non utilisé radiametre

    QString radioactivite;
    int radiation;
    QString ip;
    qint16 id;
    QLabel *ipDisplay;
    QLabel *msv;
    Window *parent;
    QWidget *panel;
    QLCDNumber *lcd;
    QHBoxLayout *layout;
    QVBoxLayout *vLayout;
    QPushButton *bouton;
    QSlider *control;
    QProgressBar *bar;
};


#endif // Monitor_H
