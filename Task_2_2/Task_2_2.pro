TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    line.cpp \
    menu.cpp \
    porabola.cpp \
    calculation.cpp \
    tabulation.cpp \
    anyaction.cpp

HEADERS += \
    function.h \
    exp.h \
    line.h \
    menu.h \
    porabola.h \
    action.h \
    calculation.h \
    tabulation.h \
    anyaction.h
