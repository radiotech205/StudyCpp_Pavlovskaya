TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    hexstring.cpp \
    action.cpp \
    showstr.cpp \
    showdec.cpp \
    showbin.cpp \
    factory.cpp \
    menu.cpp \
    showoct.cpp

HEADERS += \
    astring.h \
    sumbstring.h \
    hexstring.h \
    action.h \
    showstr.h \
    showdec.h \
    showbin.h \
    factory.h \
    menu.h \
    showoct.h
