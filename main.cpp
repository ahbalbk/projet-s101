/**
 * Projet S101 - Jouer avec les images
 * Ahmad Baalbaky, Mohamed Yaiche
 *
 * Dans tout le projet, on considère que les images sont carrées
 * Ainsi, pour optimiser le temps d'exécution, nous écrirons :
 * `comp.size()` à la place de `comp[i].size()`.
 */

#include "ppmio.h"
#include "menu.h"
#include "command.h"
#include <string>
#include <iostream>

using namespace std;

/**
 * Point d'entrée du programme
 */
int main()
{
    int replay;

    do
    {
        // On demande d'abord l'action que veut faire l'utilisateur
        int choice = menuMain();
        // pour éviter de demander l'image en entrée à l'utilisateur
        if (choice == QUIT) break;

        // On demande le chemin vers l'image en entrée.
        string imgPath = menuInPath();

        // On initialise les vecteurs représentant les composantes de l'image
        vector<vector<int>> red, green, blue;
        loadPicture(imgPath, red, green, blue);

        // On gère ensuite la commande de l'utilisateur
        switch (choice)
        {
        case COPY:
            // En appelant la fonction menuOutPath()
            // On lui demande le chemin en sortie
            copy(menuOutPath(), red, green, blue);
            break;
        case RM_C:
            rmColor(menuOutPath(), red, green, blue);
            break;
        case KEEP_C:
            keepColor(menuOutPath(), red, green, blue);
            break;
        case SRCH_C:
            searchColor(red, green, blue);
            break;
        case NEG:
            neg(menuOutPath(), red, green, blue);
            break;
        case BIN:
            bin(menuOutPath(), red, green, blue);
            break;
        case LUM:
            lum(menuOutPath(), red, green, blue);
            break;
        case VERT_SYM:
            vertSym(menuOutPath(), red, green, blue);
            break;
        case HORI_SYM:
            horiSym(menuOutPath(), red, green, blue);
            break;
        case TURN_90:
            turn90(menuOutPath(), red, green, blue);
            break;
        case FILT:
            filter(menuOutPath(), red, green, blue);
            break;
        case SOB_FILT:
            sobelFilter(menuOutPath(), red, green, blue);
            break;
        default:
            menuUnimplemented();
        }

        // On demande à l'utilisateur s'il veut recommencer
        replay = menuAskBegin();
    }
    while (replay == 'O' || replay == 'o');

    cout << "Au revoir.\n";

    return 0;
}
