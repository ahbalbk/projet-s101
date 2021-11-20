/**
 * Fichier d'en-tête contenant les fonctions utilitaires
 * gérant l'interaction avec l'utilisateur.
 *
 * Les indices des menus principales est gérée avec des constantes, permettant
 * de le rendre modulable
 * Pour ajouter un nouveau menu, il faut :
 * - rajouter la ligne correspondante dans la déclaration du MENU
 * - rajouter une constante correspondante au menu (ne pas oublier de décaler les valeurs)
 * - déclarer et définir la procédure correspondante au menu dans les fichiers command.h et command.cpp
 * - utiliser cette procédure dans le switch de la fonction main
 */

#ifndef MENU_H
#define MENU_H

#include <vector>
#include <string>

using namespace std;

/**
 * Liste des commandes disponibles dans le menu
 */
const vector<string> MENU = {
    "copier une image",
    "retirer une composante d'une image",
    "garder uniquement une composante de l'image",
    "rechercher la présence d'une composante dans une image",
    "avoir la négation d'une image",
    "binariser une image",
    "changer la luminosité d'une image",
    "appliquer une symmétrie verticale sur une image",
    "appliquer une symmétrie horizontale sur une image",
    "tourner l'image à 90° dans le sens inverse des aiguilles d'une montre",
    "appliquer un filtre à une image",
    "appliquer le filtre de Sobel à une image",
    "quitter l'application"
};

// Copie d'une image
const int COPY = 1;
// Suppression d'une composante d'une image
const int RM_C = 2;
// Garder une seul composante d'une image
const int KEEP_C = 3;
// Recherche d'une composante dans une image
const int SRCH_C = 4;
// Négation d'une image
const int NEG = 5;
// Binarisation d'une image
const int BIN = 6;
// Modifier la luminosité d'une image
const int LUM = 7;
// Appliquer une symmétrie verticale à l'image
const int VERT_SYM = 8;
// Appliquer une symmétrie horizontale à l'image
const int HORI_SYM = 9;
// Tourner une image à 90° dans le sens inverse des aiguilles d'une montre
const int TURN_90 = 10;
// Appliquer un filtre à une image
const int FILT = 11;
// Appliquer le filtre de Sobel à une image
const int SOB_FILT = 12;
// Quitter l'application
const int QUIT = 13;

/**
 * Liste des couleurs sélectionnables par l'utilisateur dans le menu
 * pour retirer, rechercher ou garder une couleur
 *
 * La couleur bleue doit rester en dernière position
 */
const vector<string> C_MENU = {
    "Rouge",
    "Vert",
    "Bleu"
};

/**
 * Indices des couleurs sélectionnées par l'utilisateur dans le menu
 *
 * La couleur bleue doit rester en dernière position
 */
const int RED = 1;
const int GREEN = 2;
const int BLUE = 3;

/**
 * Fonction qui demande à l'utilisateur le chemin d'accès à une image en entrée
 * au format PPM
 * @return Le chemin d'accès spécifié par l'utilisateur
 */
string menuInPath();

/**
 * Fonction qui demande à l'utilisateur le chemin d'accès en sortie de l'image
 * @return Le chemin d'accès vers l'image en sortie spécifié par l'uilisateur
 */
string menuOutPath();

/**
 * Fonction qui demande à l'utilisateur de saisir le filtre qu'il souhaite
 * appliquer à l'image
 * @return Le filtre de l'utilisateur (carré)
 */
vector<vector<double>> menuGetFilter();

/**
 * Fonction qui demande à l'utilisateur de sélectionner une couleur
 * @param msg Le message demandé à l'utilisateur
 * @return Le choix de l'utilisateur
 */
int menuGetColor(const string& msg);

/**
 * Procédure utilisée pour avertir l'utilisateur qu'une fonctionnalité
 * n'est pas encore implémentée dans le programme.
 *
 * Elle sert pour rajouter une fonctionnalité au programme, commme
 * un nouveau choix de couleur, un nouveau menu,
 * au cas où le code n'aurait pas été totalement mis à jour.
 */
void menuUnimplemented();

/**
 * Fonction qui affiche le menu
 * @return Le choix de l'utilisateur
 */
int menuMain();

#endif
