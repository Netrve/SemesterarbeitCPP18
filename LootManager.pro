TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    CSV_Parser/csv_parser.cpp \
    CSV_Parser/item.cpp \
    CSV_Parser/player.cpp \
    CSV_Parser/utility.cpp \
    lootmanager.cpp \
    main.cpp \
    CSV_Parser/csv_parser.cpp \
    CSV_Parser/item.cpp \
    CSV_Parser/player.cpp \
    CSV_Parser/utility.cpp \
    XML_Parser/nattlib3.cpp \
    XML_Parser/nelementlib3.cpp \
    XML_Parser/nexample3.cpp \
    XML_Parser/ntokenlib3.cpp \
    lootmanager.cpp \
    main.cpp \
    lootvault.cpp \
    lootcart.cpp

HEADERS += \
    CSV_Parser/csv_parser.h \
    CSV_Parser/item.h \
    CSV_Parser/player.h \
    CSV_Parser/utility.h \
    includes.h \
    lootmanager.h \
    main.h \
    CSV_Parser/csv_parser.h \
    CSV_Parser/item.h \
    CSV_Parser/player.h \
    CSV_Parser/utility.h \
    XML_Parser/natt3.h \
    XML_Parser/nelement3.h \
    XML_Parser/ntoken3.h \
    includes.h \
    lootmanager.h \
    main.h \
    XML_Parser/nexample3.h \
    lootvault.h \
    lootcart.h
