/**
 * @file main.c
 *
 * @date 7 oct. 2016
 * @author jilias
 */

#include "player_manager.h"
#include "board_view.h"
#include "board.h"

void squareChangedCallback(Coordinate x, Coordinate y, PieceType newContent) {

}

void endOfGame(GameResult result) {

}

void Game_init (void)
{
    printf("[*] Game_init\n");
    Board_init(squareChangedCallback, endOfGame);
    BoardView_init();
}

void Game_free (void)
{
    printf("[*] Game_free\n");
    Board_free();
    BoardView_free();
}

void Game_loop (void)
{
	// TODO: à compléter
}
