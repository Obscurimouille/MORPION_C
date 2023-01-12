TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        ../../board.c \
        main.c \
        test_CheckEndOfGame.c

HEADERS += \
    ../../board.h \
    test_CheckEndOfGame.h
