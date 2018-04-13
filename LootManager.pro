TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    CSV_Parser/csv_parser.cpp \
    main.cpp \
    CSV_Parser/csv_parser.cpp \
    XML_Parser/nattlib3.cpp \
    XML_Parser/nelementlib3.cpp \
    XML_Parser/nexample3.cpp \
    XML_Parser/ntokenlib3.cpp \
    main.cpp \
    LootInventory/item.cpp \
    LootInventory/player.cpp \
    LootUtility/utility.cpp \
    LootInventory/global.cpp \
    LootInventory/page.cpp \
    XML_Parser/xml_parser.cpp \
    LootUtility/xml_export.cpp

HEADERS += \
    CSV_Parser/csv_parser.h \
    includes.h \
    main.h \
    CSV_Parser/csv_parser.h \
    XML_Parser/natt3.h \
    XML_Parser/nelement3.h \
    XML_Parser/ntoken3.h \
    includes.h \
    main.h \
    XML_Parser/nexample3.h \
    LootInventory/item.h \
    LootInventory/player.h \
    LootUtility/utility.h \
    LootInventory/global.h \
    LootInventory/page.h \
    XML_Parser/xml_parser.h \
    LootUtility/xml_export.h
