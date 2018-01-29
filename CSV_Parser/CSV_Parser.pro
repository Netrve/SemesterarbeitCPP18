TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    item.cpp \
    player.cpp \
    csv_parser.cpp \
    utility.cpp

HEADERS += \
    item.h \
    player.h \
    includes.h \
    csv_parser.h \
    main.h \
    utility.h

DISTFILES += \
    ../build/Players.csv
