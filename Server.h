#ifndef SERVER_H
#define SERVER_H

#include <QDialog>
#include <QUdpSocket>

class QLabel;
class QPushButton;
class QTcpServer;
class QNetworkSession;
class QStringList;

class Server : public QDialog
{
    Q_OBJECT

public:
    explicit Server(QWidget *parent = Q_NULLPTR);
    void broadcast(QWidget *widget);

private slots:
    void sessionOpened();
    void sendFortune();

private:
    QUdpSocket *uSocket;
    QLabel *statusLabel;
    QTcpServer *tcpServer;
    QStringList fortunes;
    QNetworkSession *networkSession;
};

#endif
