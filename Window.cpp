#include "Window.h"


Window::Window(): QMainWindow()
{
    broadcast();
    setFixedSize(WWO, TOP_H );
    cw = new QFrame();
    setCentralWidget(cw);

    topBar = new QFrame();
    topBar->setFixedSize(WW, TOP_H);
    topPanel = new QFrame();
    topPanel->setFixedHeight(TOP_H - VMT * 4);
    topPanel->setStyleSheet("background-color: grey; color:charcoal;");

    layout = new QVBoxLayout(cw);
    panelLayout = new QHBoxLayout(topPanel);
    panelLayout->setContentsMargins(5, 3, 2, 5);
    cw->setStyleSheet("background-color:orangered;color:white;");
    layout->setContentsMargins(SMT, 0, 0, SMT);
    layout->setSpacing(0);
    topLayout = new QHBoxLayout(topBar);
    topLayout->setContentsMargins(0,VMT,VMT,0);
    topLabel = new QLabel("Nuclear safety monitor");
    launchLabel = new QLabel("recherche dosimètres");
    ajouterLabel = new QLabel("ajouter dosimètre");
    launch =new QPushButton();
    launch->setStyleSheet("background-color:dimgrey; color:charcoal;");
    launch->setFixedSize(TOP_H/2+6, TOP_H/2);
    ajouter = new QPushButton();
    ajouter->setStyleSheet("background-color:darkgrey; color:charcoal;");
    ajouter->setFixedSize(TOP_H/2+6, TOP_H/2);

    topLayout->addWidget(topLabel);
    topLayout->addWidget(topPanel);
    panelLayout->setSpacing(5);
    panelLayout->addWidget(launchLabel);
    panelLayout->addWidget(launch);
    panelLayout->addWidget(ajouterLabel);
    panelLayout->addWidget(ajouter);
    topLabel->setFont(QFont("Arial", 12, true));

    topBar->setStyleSheet("background-color:orangered;color:white;");
    setStyleSheet("background-color:black;color:red;");
    /*bouton = new QPushButton("Appuyer ici");
    bouton->setFont(QFont("Comic Sans MS", 14));
    bouton->setCursor(Qt::PointingHandCursor);
    bouton->show();*/
   // bouton->move(50, 50);
  layout->addWidget(topBar);

  //this->addMonitor();
  /*monitor = new Monitor();
  monitors.push_back(monitor);
  layout->addWidget(monitor);*/
    //monitor->move(0,TOP_H+5);

    QObject::connect(ajouter, SIGNAL(clicked()), this, SLOT(addMonitor()));
    //monitors.append(monitor);
}

/*QVector <Monitor*> Window::getMonitors(){

    return this->monitors;
}*/


/*void Window::showMonitors()
{
    for(int i = 0; i < monitors.size(); i++){
        monitors[i]->show();
    }
}*/

void Window::addMonitor()
{
    if(monitors.size() < MAX_NUM){
        Monitor *monitor = new Monitor("0.0.0.0", this, monitors.size());
        this->layout->addWidget(monitor);
        this->monitors.push_back(monitor);

        setFixedHeight(this->height() + DOS_H);
        qDebug() << "Taille moniteur : " << monitors.size();
    }

}

void Window::changerHauteur(int hauteur)
{
    setFixedSize(width(), hauteur);
    if (hauteur == 1000)
    {
        emit agrandissementMax();
    }
}

void Window::broadcast()
{
  qDebug() << QHostAddress::Broadcast << " broadcast";
}

/* void Window::broadcast2(/*QWidget *widget)
{
   // uSocket = new QUdpSocket(widget);
  //  uSocket->bind();


    foreach (const QHostAddress &address, QNetworkInterface::allAddresses()) {
        if (address.protocol() == QAbstractSocket::IPv4Protocol && address != QHostAddress(QHostAddress::LocalHost))
             qDebug() << address.toString();
}*/

void Window::connect()
{
    socket = new QTcpSocket(this);
    socket->connectToHost("bogotobogo.com", 80);

    if(socket->waitForConnected(3000))
    {
        qDebug() << "Connected!";

        // send
        socket->write("hello server\r\n\r\n\r\n\r\n");
        socket->waitForBytesWritten(1000);
        socket->waitForReadyRead(3000);
        qDebug() << "Reading: " << socket->bytesAvailable();

        qDebug() << socket->readAll();

        socket->close();
    }
    else
    {
        qDebug() << "Not connected!";
    }

    // sent

    // got

    // closed
}


