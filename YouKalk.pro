#-------------------------------------------------
#
# Project created by QtCreator 2018-01-11T10:05:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = YouKalk
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
    udm.cpp \
    misura.cpp \
    spec_udm.cpp \
    spec_misura.cpp \
    eccezioni.cpp \
    Application.cpp \
    button_mod.cpp \
    display_mod.cpp \
    resistore.cpp \
    condensatore.cpp \
    solenoide.cpp \
    induttore.cpp \
    componenteelettrico.cpp \
    misuraTA.cpp \
    kalk.cpp \
    kalkC.cpp \
    kalkI.cpp \
    kalkR.cpp

HEADERS += \
    udm.h \
    misura.h \
    eccezioni.h \
    Application.h \
    button_mod.h \
    display_mod.h \
    resistore.h \
    condensatore.h \
    solenoide.h \
    induttore.h \
    componenteelettrico.h \
    misuraTA.h \
    kalk.h \
    kalkC.h \
    kalkI.h \
    kalkR.h

    QMAKE_CXXFLAGS += -std=c++11
