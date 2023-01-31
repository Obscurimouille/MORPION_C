/**
 * @file player_manager_scanf.c
 *
 * @date 7 oct. 2016
 * @author jilias
 */

#include "board.h"
#include "board_view.h"
#include <assert.h>
#include <stdio.h>

#if defined CONFIG_PLAYER_MANAGER_SCANF

PieceType player = CIRCLE;

void PlayerManager_init (void)
{
}

void PlayerManager_free (void)
{
}

void PlayerManager_oneTurn (void)
{
    int x, y, read = 0;
    bool ok = false;

    BoardView_displayPlayersTurn(player);

    do {
        // Demander les coordonnées selon le format X,Y
        printf("Placez votre piece en X,Y:\n");
        read = scanf("%d,%d", &x, &y);

        // Si incorrect (format, valeur, ou pièce déja placée à cet endroit),
        if(read != 2 || x < 0 || x > 2 || y < 0 || y > 2 || Board_putPiece(x, y, player) != PIECE_IN_PLACE) {
            // Vider le buffer et afficher un message d'erreur
            char c;
            while ((c = getchar()) != '\n' && c != EOF);
            printf("\nCoordonnees incorrectes...\n");
        }
        else ok = true;
    }
    while(!ok);

    printf("a");
    player = player == CIRCLE ? CROSS : CIRCLE;
}

#endif // defined CONFIG_PLAYER_MANAGER_SCANF
