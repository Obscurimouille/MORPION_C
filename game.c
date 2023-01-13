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
    Board_init(squareChangedCallback, endOfGame);
}

void Game_free (void)
{
  // TODO: libérer tous les modules
}

void Game_loop (void)
{
	// TODO: à compléter
}
