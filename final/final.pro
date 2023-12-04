QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ControladorEventos.cpp \
    Enemigo.cpp \
    InterfazUsuario.cpp \
    Juego.cpp \
    Jugador.cpp \
    Nivel.cpp \
    ObjectoRecolectable.cpp \
    Objeto.cpp \
    ObjetoObstaculo.cpp \
    Personaje.cpp \
    Personaje.cpp \
    Temporizador.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    ControladorEventos.h \
    Enemigo.h \
    InterfazUsuario.h \
    Juego.h \
    Jugador.h \
    Nivel.h \
    Objeto.h \
    ObjetoObstaculo.h \
    ObjetoRecolectable.h \
    Personaje.h \
    Personaje.h \
    Temporizador.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
