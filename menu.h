/**
 * Fichier d'en-tête contenant les fonctions utilitaires
 * gérant l'interaction avec l'utilisateur.
 *
 * Les indices des menus principales est gérée avec des constantes, permettant
 * de le rendre modulable
 */

#ifndef MENU_H
#define MENU_H

#include <string>

using namespace std;

// Copie d'une image
const int COPY = 1;
// Suppression d'une ou deux composantes d'une image
const int RM_C = 2;
// Recherche d'une composante dans une image
const int SRCH_C = 3;
// Négation d'une image
const int NEG = 4;
// Binarisation d'une image
const int BIN = 5;
// Modifier la luminosité d'une image
const int LUM = 6;
// Quitter l'application
const int QUIT = 7;

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
 * Fonction qui affiche le menu
 * @return Le choix de l'utilisateur
 */
int menuMain();

#endif
