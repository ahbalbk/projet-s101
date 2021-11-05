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
    cout << COPY << " - pour copier une image.\n";
    cout << RM_C << " - pour retirer une composante d'une image.\n";
    cout << KEEP_C << " - pour garder uniquement une composante de l'image.\n";
    cout << SRCH_C << " - pour rechercher la présence d'une composante dans une image.\n";
    cout << NEG << " - pour avoir la négation d'une image.\n";
    cout << BIN << " - pour binariser une image.\n";
    cout << LUM << " - pour changer la luminosité d'une image.\n";
    cout << VERT_SYM << " - pour appliquer une symmétrie verticale sur une image.\n";
    cout << HORI_SYM << " - pour appliquer une symmétrie horizontale sur une image.\n";
    cout << TURN_90 << " - pour tourner l'image à 90° dans le sens inverse des aiguilles d'une montre.\n";
    cout << QUIT << " - pour quitter l'application.\n>> ";

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


