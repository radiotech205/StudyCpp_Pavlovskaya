TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    dbase.cpp \
    man.cpp \
    getfunc.cpp

HEADERS += \
    dbase.h \
    man.h \
    getfunc.h
