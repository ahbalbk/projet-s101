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
    // On demande d'abord l'action que veut faire l'utilisateur
    int choice = menuMain();

    while (choice != QUIT)
    {
        // On demande le chemin vers l'image en entrée.
        string imgPath = menuInPath();

        // Puis on initialise les vecteurs représentant les composantes de l'image
        vector<vector<int>> red, green, blue;
        loadPicture(imgPath, red, green, blue);

        // Puis on demande le chemin vers l'image en sortie.
        // Elle peut être la même que celle en entrée
        string toPath = menuOutPath();

        // On gère ensuite la commande de l'utilisateur
        switch (choice)
        {
        case COPY:
            copy(toPath, red, green, blue);
            break;
        case RM_C:
            rmColor(toPath, red, green, blue);
            break;
        case KEEP_C:
            keepColor(toPath, red, green, blue);
            break;
        case SRCH_C:
            searchColor(red, green, blue);
            break;
        case NEG:
            neg(toPath, red, green, blue);
            break;
        case BIN:
            bin(toPath, red, green, blue);
            break;
        case LUM:
            lum(toPath, red, green, blue);
            break;
        case VERT_SYM:
            vertSym(toPath, red, green, blue);
            break;
        case HORI_SYM:
            horiSym(toPath, red, green, blue);
            break;
        case TURN_90:
            turn90(toPath, red, green, blue);
            break;
        case FILT:
            filter(toPath, red, green, blue);
            break;
        case SOB_FILT:
            sobelFilter(toPath, red, green, blue);
            break;
        }

        // On redemande le choix de l'utilisateur
        choice = menuMain();
    }

    cout << "Au revoir.\n";

    return 0;
}
