#include "board.h"
#include <assert.h>

PieceType (*board)[3];
SquareChangeCallback squareChange;
EndOfGameCallback endOfGame;

/**
 * Check if the game has to be ended. Only alignment from the last
 * modified square are checked.
 *
 * @param [in] boardSquares the board to check
 * @param [in] lastChangeX the colum where the last piece has been put
 * @param [in] lastChangeY the row where the last piece has been put
 * @param [out] gameResult the winning status if the game has ended (value is not set if
 * the game is not finished)
 *
 * @pre lastChangeX must be in [0..2]
 * @pre lastChangeY must be in [0..2]
 * @pre gameResult must point on an allocated GameResult variable
 *
 * @return a boolean that tells if the game is finished
 */
static bool isGameFinished (const PieceType boardSquares[3][3], Coordinate lastChangeX, Coordinate lastChangeY, GameResult *gameResult)
{
    unsigned int i, j;

    // Colonnes et lignes
    for(i = 0; i < 3; i++)
        if((boardSquares[i][0] != NONE && boardSquares[i][0] == boardSquares[i][1] && boardSquares[i][1] == boardSquares[i][2]) ||
                (boardSquares[0][i] != NONE && boardSquares[0][i] == boardSquares[1][i] && boardSquares[1][i] == boardSquares[2][i]))
        {
            *gameResult = (GameResult)boardSquares[lastChangeY][lastChangeX];
            return true;
        }

    // Diagonales
    if(boardSquares[0][0] != NONE && ((boardSquares[0][0] == boardSquares[1][1] && boardSquares[1][1] == boardSquares[2][2]) ||
            (boardSquares[0][2] == boardSquares[1][1] && boardSquares[1][1] == boardSquares[2][0])))
    {
        *gameResult = (GameResult)boardSquares[lastChangeY][lastChangeX];
        return true;
    }

    // Pas fin
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
            if(boardSquares[i][j] == NONE) return false;

    // Fin par égalité
    *gameResult = DRAW;
    return true;
}

void Board_init (SquareChangeCallback onSquareChange, EndOfGameCallback onEndOfGame)
{

    board = calloc(3, sizeof *board);

    // Init tableau
    int i, j;

    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
            board[i][j] = NONE;

//    squareChange = onSquareChange;
//    endOfGame = onEndOfGame;

}

void Board_free ()
{
  free(board);
}

PutPieceResult Board_putPiece (Coordinate x, Coordinate y, PieceType kindOfPiece)
{
    if(board[y][x] != NONE) return SQUARE_IS_NOT_EMPTY;

    board[y][x] = kindOfPiece;
    squareChange(x, y, kindOfPiece);

    GameResult result = DRAW;

    if(isGameFinished(board, x, y, &result))
        endOfGame(result);

    return PIECE_IN_PLACE;
}

PieceType Board_getSquareContent (Coordinate x, Coordinate y)
{
    return board[y][x];
}
