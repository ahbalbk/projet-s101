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
    // Variable utilisée pour recommencer le programme selon l'utilisateur
    bool restart = true;

    while (restart)
    {
        // On demande d'abord le chemin vers l'image en entrée.
        string imgPath = menuInPath();
        // Puis on initialise les vecteurs représentant les composantes de l'image
        vector<vector<int>> r, g, b;
        loadPicture(imgPath, r, g, b);

        // On déclare des variables constantes pour les composantes
        // en entrée, pour qu'elles restent immuables.
        const vector<vector<int>> red = r, green = g, blue = b;

        // On demande l'action que veut faire l'utilisateur
        int choice = menuMain();
        // Puis finalement le chemin vers l'image en sortie. Elle peut être la même
        // que celle en entrée
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
        default:
            // L'utilisateur choisit de quitter
            restart = false;
            cout << "Au revoir.\n";
        }
    }

    return 0;
}
