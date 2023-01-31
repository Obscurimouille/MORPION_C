TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        board.c \
        board_view_text.c \
        game.c \
        main.c \
        player_manager_mock.c \
        player_manager_scanf.c \
        tictactoe_erros.c

HEADERS += \
    board.h \
    board_view.h \
    game.h \
    player_manager.h \
    tictactoe_errors.h
