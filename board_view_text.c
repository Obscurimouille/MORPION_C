#include "board_view.h"
#include <assert.h>
#include <stdio.h>
#include <board.h>

#define CONFIG_TEXTUI

#if defined CONFIG_TEXTUI

void BoardView_init (void)
{
    printf("BoardView_init\n");
    BoardView_displayAll();
}

void BoardView_free (void)
{

}

char BoardView_pieceToChar(PieceType piece) {
    switch (piece) {
        case NONE: return ' ';
        case CROSS: return 'X';
        case CIRCLE: return 'O';
    }
}

void BoardView_displayAll (void)
{
    int i, j;

    printf("\n");

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf(" %c ", BoardView_pieceToChar(board[i][j]));
            printf(j < 2 ? "|" : "\n");
        }
        if(i < 2) printf("---+---+---\n");
    }

    printf("\n");
}

void BoardView_displaySquare (Coordinate x, Coordinate y, PieceType kindOfPiece)
{
	BoardView_displayAll();
}

void BoardView_displayEndOfGame (GameResult result)
{
    switch (result) {
        case CROSS_WINS:
            printf("---- LES CROIX ONT GAGNEES ----");
            break;
        case CIRCLE_WINS:
            printf("--- LES CRECLES ONT GAGNEES ---");
            break;
        case DRAW:
            printf("----------- EGALITE -----------");
            break;
    }
}

void BoardView_displayPlayersTurn (PieceType thisPlayer)
{
    switch (thisPlayer) {
        case CROSS:
            printf("Au tour des croix");
            break;
        case CIRCLE:
            printf("Au tour des cercles");
            break;
        case NONE:
            fatalError("BoardView_displayPlayersTurn -> PLAYER: NONE");
            break;
    }
}

void BoardView_sayCannotPutPiece (void)
{
    printf("Impossible de placer cette piece !");
}

#endif // defined CONFIG_TEXTUI
