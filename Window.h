#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QWidget>
#include <QFrame>
#include <QLabel>
#include <QVBoxLayout>
#include <QMainWindow>
#include <QDebug>
#include <QNetworkInterface>
#include <QTcpSocket>
#include "Monitor.h"
// window width outer (extérieur)
#define WWO 600
// side margin thickness
#define SMT 4
#define VMT 2
// window width
#define WW  WWO - SMT * 2
#define WH 100
#define BH 50
#define TOP_H 30

#define PANEL_H 40
#define BAR_H 5
#define DOS_H PANEL_H + BAR_H
#define LCD_W 50
#define LCD_H 50
#define MAX_NUM 12

class Window : public QMainWindow
{
    Q_OBJECT

    public:
    explicit Window();
     void broadcast(/*QWidget *widget*/);
    //QVector <Monitor*> getMonitors();
    QVector <Monitor*> monitors;


    public slots:
    void changerHauteur(int hauteur);
    void addMonitor();
    void connect();

    signals:
    void agrandissementMax();

    private:
    QWidget *cw;
    int numMonitor;
    QVBoxLayout *layout;
    QHBoxLayout *topLayout;
    QHBoxLayout *panelLayout;
    QFrame *topBar;
    QFrame *topPanel;
    QLabel *topLabel;
    QLabel *launchLabel;
    QLabel *ajouterLabel;
    Monitor *monitor;

    QPushButton *ajouter;
    QPushButton *launch;

    QTcpSocket *socket;
};


#endif // MAINWINDOW_H
