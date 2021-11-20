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

/**
 * Fonction utilisée pour afficher un message
 * puis fait saisir un nombre à l'utilisateur entre min et max
 * @param msg Le message à afficher
 * @param min Le nombre minimum à saisir
 * @param max Le nombre maximum à saisir
 * @return Le nombre correct saisit par l'utilisateur
 */
int askNum(const string& msg, int min, int max)
{
    cout << msg << " :\n>> ";
    int n;
    cin >> n;
    while (n < min || n > max)
    {
        cout << "Erreur : le nombre doit être compris entre " << min << " et " << max << ".\n>> ";
        cin >> n;
    }

    return n;
}

/**
 * Fonction qui demande à l'utilisateur le chemin d'accès à une image en entrée
 * au format PPM
 * @return Le chemin d'accès spécifié par l'utilisateur
 */
string menuInPath()
{
    return askPath("Veuillez spécifier le chemin vers l'image en entrée"); 
}

/**
 * Fonction qui demande à l'utilisateur le chemin d'accès en sortie de l'image
 * @return Le chemin d'accès vers l'image en sortie spécifié par l'uilisateur
 */
string menuOutPath()
{
    return askPath("Veuillez spécifier le chemin vers l'image en sortie");
}

/**
 * Fonction qui demande à l'utilisateur de saisir le filtre qu'il souhaite
 * appliquer à l'image
 * @return Le filtre de l'utilisateur (carré)
 */
vector<vector<double>> menuGetFilter()
{
    // On demande la taille du filtre carré à l'utilisateur
    int n = askNum("Veuillez spécifier la taille de votre filtre", 3, 9); 
    // On initialise le vecteur en spécifiant la taille par ligne (n)
    vector<vector<double>> filter;
    filter.reserve(n);

    // On demande à l'utilisateur de remplir chaque ligne du filtre
    for (int i = 0; i < n; i++)
    {
        cout << "Ligne " << i + 1 << " :\n";
        // On réserve n colonnes pour la ligne courante (éviter de réallouer)
        vector<double> line;
        line.reserve(n);

        for (int j = 0; j < n; j++)
        {
            double x;
            cout << ">> ";
            cin >> x;
            line.push_back(x);
        }
        
        // On ajoute la ligne au filtre
        filter.push_back(line);
    }

    // On retourne finalement le filtre rempli par l'utilisateur
    return filter;
}

/**
 * Fonction qui demande à l'utilisateur de sélectionner une couleur
 * @param msg Le message demandé à l'utilisateur
 * @return Le choix de l'utilisateur
 */
int menuGetColor(const string& msg)
{
    // On affiche les couleurs disponibles
    for (int i = 0; i < C_MENU.size(); i++)
    {
        cout << i + 1 << " - " << C_MENU[i] << ".\n";
    }

    return askNum(msg, 1, BLUE);
}

/**
 * Procédure utilisée pour avertir l'utilisateur qu'une fonctionnalité
 * n'est pas encore implémentée dans le programme.
 *
 * Elle sert pour rajouter une fonctionnalité au programme, commme
 * un nouveau choix de couleur, un nouveau menu,
 * au cas où le code n'aurait pas été totalement mis à jour.
 */
void menuUnimplemented()
{
    cout << "Cette fonctionnalité n'est pas encore implémentée.\n";
}

/**
 * Fonction qui affiche le menu
 * @return Le choix de l'utilisateur
 */
int menuMain()
{
    // On affiche le menu
    cout << "-------------------------------------------------\n";
    cout << "Application de manipulation d'image au format PPM\n";
    cout << "-------------------------------------------------\n";
    for (int i = 0; i < MENU.size(); i++)
    {
        cout << i + 1 << " - pour " << MENU[i] << ".\n";
    }

    // On retourne finalement la saisie
    return askNum("Choisissez un menu", 1, QUIT);;
}


