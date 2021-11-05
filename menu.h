/**
 * Fichier d'en-tête contenant les fonctions utilitaires
 * gérant l'interaction avec l'utilisateur.
 *
 * Les indices des menus principales est gérée avec des constantes, permettant
 * de le rendre modulable
 * Pour ajouter un nouveau menu, il faut :
 * - rajouter une constante correspondante au menu (ne pas oublier de décaler les valeurs)
 * - mettre à jour la définition de la fonction int menuMain()
 * - déclarer et définir la procédure correspondante au menu dans les fichiers command.h et command.cpp
 * - utiliser cette procédure dans le switch de la fonction main
 */

#ifndef MENU_H
#define MENU_H

#include <string>

using namespace std;

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
// Quitter l'application
const int QUIT = 11;

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
