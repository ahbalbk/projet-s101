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
 * Mohamed Yaiche
 * Commande pour effectuer une copie d'image
 */
void copy(string path,
        const vector<vector<int>>& red,
        const vector<vector<int>>& green,
        const vector<vector<int>>& blue);

/**
 * Mohamed Yaiche
 * Commande pour retirer une composante d'une image
 */
void rmColor(string path,
        const vector<vector<int>>& red,
        const vector<vector<int>>& green,
        const vector<vector<int>>& blue);

/**
 * Mohamed Yaiche
 * Commande pour garder seulement une composante d'une image
 */
void keepColor(string path,
        const vector<vector<int>>& red,
        const vector<vector<int>>& green,
        const vector<vector<int>>& blue);

/**
 * Mohamed Yaiche
 * Commande pour rechercher la présence d'une composante dans une image
 */
void searchColor(const vector<vector<int>>& red,
        const vector<vector<int>>& green,
        const vector<vector<int>>& blue);

/**
 * Mohamed Yaiche
 * Commande pour écrire la négation d'une image
 */
void neg(string path,
        const vector<vector<int>>& red,
        const vector<vector<int>>& green,
        const vector<vector<int>>& blue);

/**
 * Mohamed Yaiche
 * Commande pour binariser une image
 */
void bin(string path,
        const vector<vector<int>>& red,
        const vector<vector<int>>& green,
        const vector<vector<int>>& blue);

/**
 * Mohamed Yaiche
 * Commande pour augmenter ou diminuer la luminosité d'une image
 */
void lum(string path,
        const vector<vector<int>>& red,
        const vector<vector<int>>& green,
        const vector<vector<int>>& blue);

/**
 * Commande pour appliquer une symmétrie verticale à une image
 */
void vertSym(string path,
        const vector<vector<int>>& red,
        const vector<vector<int>>& green,
        const vector<vector<int>>& blue);

/**
 * Commande pour appliquer une symmétrie horizontale à une image
 */
void horiSym(string path,
        const vector<vector<int>>& red,
        const vector<vector<int>>& green,
        const vector<vector<int>>& blue);

/**
 * Ahmad Baalbaky
 * Commande pour tourner une image à 90° dans le sens inverse des aiguilles d'une montre
 */
void turn90(string path,
        const vector<vector<int>>& red,
        const vector<vector<int>>& green,
        const vector<vector<int>>& blue);

/**
 * Ahmad Baalbaky
 * Commande pour appliquer un filtre à une image
 */
void filter(string path,
        const vector<vector<int>>& red,
        const vector<vector<int>>& green,
        const vector<vector<int>>& blue);

/**
 * Ahmad Baalbaky
 * Commande pour appliquer les filtres de Sobel à une image
 */
void sobelFilter(string path,
        const vector<vector<int>>& red,
        const vector<vector<int>>& green,
        const vector<vector<int>>& blue);

#endif
