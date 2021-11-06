#include "menu.h"
#include <iostream>
#include <string>

using namespace std;

/**
 * Fonction utilisée pour afficher un message
 * puis fait saisir une chaîne de caractère à l'utilisateur.
 * @param msg Le message à afficher à l'utilisateur
 * @return La chaîne de caractère saisie par l'utilisateur
 */
inline string askPath(const string& msg)
{
    cout << msg << " :\n>> ";
    string out;
    cin >> out;
    return out;
}

string menuInPath()
{
    return askPath("Veuillez spécifier le chemin vers l'image en entrée"); 
}

string menuOutPath()
{
    return askPath("Veuillez spécifier le chemin vers l'image en sortie");
}

int menuMain()
{
    // On affiche le menu
    cout << "Application de manipulation d'image au format PPM\n";
    cout << "-------------------------------------------------\n";
    cout << "Tapez :\n";
    for (int i = 0; i < MENU.size(); i++)
    {
        cout << i + 1 << " - pour " << MENU[i] << ".\n";
    }
    cout << ">> ";

    int out;
    cin >> out;
    // Si l'utilisateur saisit une mauvaise entrée,
    // on rentre dans la boucle
    while (out < COPY || out > QUIT) 
    {
        cout << "Erreur: mauvaise entrée.\n>> ";
        cin >> out;
    }

    // On retourne finalement la bonne saisie
    return out;
}


