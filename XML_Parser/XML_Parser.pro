TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    attlib.cpp \
    tokenlib6.cpp

HEADERS += \
    att.h \
    token6.h
