#include <QApplication>
#include <QPushButton>
#include <QWidget>

#include "Window.h"
#include "Server.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QGuiApplication::setApplicationDisplayName(Server::tr("Nuclear monitor: Master app"));
    Server server;

    Window window;

    //window.showMonitors();
    window.show();

    return app.exec();
}
