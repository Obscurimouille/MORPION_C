#include "board.h"
#include <assert.h>

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

    for(i = 0; i < 2; i++)
        if(boardSquares[i][0] != NONE && boardSquares[i][0] == boardSquares[i][1] && boardSquares[i][1] == boardSquares[i][2])
            return true;

    for(i = 0; i < 2; i++)
        if(boardSquares[0][i] != NONE && boardSquares[0][i] == boardSquares[1][i] && boardSquares[1][i] == boardSquares[2][i])
            return true;

    if(boardSquares[0][0] != NONE && boardSquares[0][0] == boardSquares[1][1] && boardSquares[1][1] == boardSquares[2][2])
        return true;

    if(boardSquares[0][2] != NONE && boardSquares[0][2] == boardSquares[1][1] && boardSquares[1][1] == boardSquares[2][0])
        return true;

    for(i = 0; i < 2; i++)
        for(j = 0; j < 2; j++)
            if(boardSquares[i][j] == NONE) return false;

    return true;
}

void Board_init (SquareChangeCallback onSquareChange, EndOfGameCallback onEndOfGame)
{
  // TODO: à compléter
}

void Board_free ()
{
  // TODO: à compléter
}

PutPieceResult Board_putPiece (Coordinate x, Coordinate y, PieceType kindOfPiece)
{
  // TODO: à compléter
}

PieceType Board_getSquareContent (Coordinate x, Coordinate y)
{
  // TODO: à compléter
}
