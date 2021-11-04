/**
 * Fichier d'en-tête contenant les fonctions à exécuter selon la commande
 * Les commandes sont des procédures acceptant généralement des paramètres au format suivant :
 * @param path Le chemin vers l'image en sortie
 * @param red La composante rouge de l'image en entrée
 * @param green La composante verte de l'image en entrée
 * @param blue La composante bleue de l'image en entrée
 */

#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <vector>

using namespace std;

/**
 * Commande pour effectuer une copie d'image
 */
void copy(string path,
        const vector<vector<int>>& red,
        const vector<vector<int>>& green,
        const vector<vector<int>>& blue);

/**
 * Commande pour retirer une ou plusieurs composantes d'une image
 */
void rmColor(string path,
        const vector<vector<int>>& red,
        const vector<vector<int>>& green,
        const vector<vector<int>>& blue);

/**
 * Commande pour rechercher la présence d'une composante dans une image
 */
void searchColor(const vector<vector<int>>& red,
        const vector<vector<int>>& green,
        const vector<vector<int>>& blue);

/**
 * Commande pour écrire la négation d'une image
 */
void neg(string path,
        const vector<vector<int>>& red,
        const vector<vector<int>>& green,
        const vector<vector<int>>& blue);

/**
 * Commande pour binariser une image
 */
void bin(string path,
        const vector<vector<int>>& red,
        const vector<vector<int>>& green,
        const vector<vector<int>>& blue);

/**
 * Commande pour augmenter ou diminuer la luminosité d'une image
 */
void lum(string path,
        const vector<vector<int>>& red,
        const vector<vector<int>>& green,
        const vector<vector<int>>& blue);

#endif
