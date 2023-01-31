/**
 * @file player_manager_mock.c
 *
 * @date 7 oct. 2016
 * @author jilias
 */

#include "board.h"
#include <assert.h>
#include <stdio.h>

#define CONFIG_PLAYER_MANAGER_MOCK
#if defined CONFIG_PLAYER_MANAGER_MOCK

typedef struct {
    PieceType piece;
    unsigned int x;
    unsigned int y;
} Move;

// Jeu de test
Move test[9] = {
    {CIRCLE, 1, 1},
    {CROSS, 0, 0},
    {CIRCLE, 0, 1},
    {CROSS, 2, 1},
    {CIRCLE, 2, 0},
    {CROSS, 1, 0},
    {CIRCLE, 0, 2},
    {CROSS, 1, 2},
    {CIRCLE, 2, 2},
};

unsigned char turn = 0;

void PlayerManager_init (void)
{

}

void PlayerManager_free (void)
{

}

void PlayerManager_oneTurn (void)
{
    // Récupération des coordonées
    unsigned char x = test[turn].x, y = test[turn].y;
    // Placement de la pièce
    Board_putPiece(x, y, test[turn].piece);
    // Tour suivant
    turn++;
}

#endif //  #if defined CONFIG_PLAYER_MANAGER_MOCK
