#include <QApplication>
#include <QDesktopServices>
#include <QDialog>
#include <QDir>
#include <QFileInfo>
#include <QUrl>
#include <QWebChannel>
#include <QWebSocketServer>
#include "websocketchannel.h"
#include "dialog.h"
int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    
    //建立QWebSocketServer，url是ws://localhost:12345

    QWebSocketServer server(QStringLiteral("QWebChannel Standalone Example Server"), QWebSocketServer::NonSecureMode);
    if (!server.listen(QHostAddress::LocalHost, 12345)) {
        qFatal("Failed to open web socket server.");
        return 1;
    }
    
    //建立websocketchannl,该channel就可以用来通信了
    WebSocketChannel channel(&server);

    // setup the UI
    Dialog dialog;

    
    //注册C++对象，该类要继承自QObject
    channel.registerObject(QStringLiteral("dialog"), &dialog);

    // open a browser window with the client HTML page
    QUrl url = QUrl::fromLocalFile( "/Users/apple/workspace/websocket/index.html");
    QDesktopServices::openUrl(url);

    dialog.displayMessage(Dialog::tr("Initialization complete, opening browser at %1.").arg(url.toDisplayString()));
    dialog.show();

    return app.exec();
}
