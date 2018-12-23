#ifndef WEBSOCKETCHANNEL_H
#define WEBSOCKETCHANNEL_H

#include <QWebChannel>

class QWebSocketServer;
class WebSocketTransport;

//继承QWebchannel类，在内部建立socket server与transport中socket的连接

class WebSocketChannel : public QWebChannel
{
    Q_OBJECT
public:
    WebSocketChannel(QWebSocketServer *server);

signals:
    void clientConnected(WebSocketTransport *client);

private slots:
    void handleNewConnection();

private:
    QWebSocketServer *_server;
};

#endif // WEBSOCKETCHANNEL_H
