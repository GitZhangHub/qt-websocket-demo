TEMPLATE = app
TARGET = QwebSocketDemo
QT += webenginewidgets network websockets widgets
CONFIG += c++11


DISTFILES += \
    qwebchannel.js \
    index.html

HEADERS += \
    websocketchannel.h \
    websockettransport.h \
    dialog.h

SOURCES += \
    main.cpp \
    websocketchannel.cpp \
    websockettransport.cpp \
    dialog.cpp

FORMS += \
    dialog.ui
