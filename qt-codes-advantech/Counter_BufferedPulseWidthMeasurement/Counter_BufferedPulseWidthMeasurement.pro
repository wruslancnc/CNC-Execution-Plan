#-------------------------------------------------
#
# Project created by QtCreator 2017-04-26
#
#-------------------------------------------------
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Counter_BufferedPulseWidthMeasurement
TEMPLATE = app

INCLUDEPATH += ../../../inc/bdaqctrl.h
           	   
SOURCES += configuredialog.cpp\
		   main.cpp\
		   bufferedpulsewidthmeasurement.cpp\

HEADERS += configuredialog.h\
           bufferedpulsewidthmeasurement.h\

FORMS   += configuredialog.ui \ 
		   bufferedpulsewidthmeasurement.ui

RESOURCES += bufferedpulsewidthmeasurement.qrc

CONFIG += debug_and_release

CONFIG(debug, debug|release){
        DESTDIR += $$PWD/../bin/debug
        OBJECTS_DIR = $$PWD/debug
        UI_DIR      = $$PWD/debug/ui
        MOC_DIR     = $$PWD/debug/moc
        RCC_DIR     = $$PWD/debug/rcc

} else {
        DESTDIR += $$PWD/../bin/release
        OBJECTS_DIR = $$PWD/release
        UI_DIR      = $$PWD/release/ui
        MOC_DIR     = $$PWD/release/moc
        RCC_DIR     = $$PWD/release/rcc
}

unix: LIBS += -lbiodaq
