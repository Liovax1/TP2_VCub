#-------------------------------------------------
#
# Project created by QtCreator 2017-03-29T21:15:31
#
#-------------------------------------------------

QT       += core gui webenginewidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtVCubTP2_etudiant
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11
#pour probleme webengine !
CONFIG+=use_gold_linker

SOURCES += main.cpp\
    CSeuilAlarme/cseuilalarme.cpp \
    DialogCSeuilAlarme/dialogcseuilalarme.cpp \
        mainwindow.cpp \
    cstationvcub.cpp \
    cstationvcubmanager.cpp

HEADERS  += mainwindow.h \
    CSeuilAlarme/cseuilalarme.h \
    DialogCSeuilAlarme/dialogcseuilalarme.h \
    cstationvcub.h \
    cstationvcubmanager.h

FORMS    += mainwindow.ui \
    DialogCSeuilAlarme/dialogcseuilalarme.ui

RESOURCES += \
    images.qrc
