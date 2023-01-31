/**
 * @file main.c
 *
 * @date 7 oct. 2016
 * @author jilias
 */

#include "player_manager.h"
#include "board_view.h"
#include "board.h"

unsigned char gameEnded = 0;

void squareChangedCallback(Coordinate x, Coordinate y, PieceType newContent) {
    BoardView_displaySquare(x, y, newContent);
}

void endOfGameCallback(GameResult result) {
    gameEnded = 1;
    BoardView_displayEndOfGame(result);
}

void Game_init (void)
{
    Board_init(squareChangedCallback, endOfGameCallback);
    BoardView_init();
    PlayerManager_init();
}

void Game_free (void)
{
    Board_free();
    BoardView_free();
    PlayerManager_free();
}

void Game_loop (void)
{
    while(!gameEnded) {
        PlayerManager_oneTurn();
    }
}
