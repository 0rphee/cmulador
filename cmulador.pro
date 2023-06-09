QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    counterwidget.cpp \
    funciones.cpp \
    inputnumeroswidget.cpp \
    main.cpp \
    mainwindow.cpp \
    presultadoswidget.cpp \
    resultadoswidget.cpp \
    tablafuerzaswidget.cpp \
    ventanaArmadura.cpp \
    ventanapalanca.cpp

HEADERS += \
    counterwidget.h \
    funciones.h \
    inputnumeroswidget.h \
    mainwindow.h \
    presultadoswidget.h \
    resultadoswidget.h \
    tablafuerzaswidget.h \
    ventanaArmadura.h \
    ventanapalanca.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
