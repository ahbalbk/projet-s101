/**
 * Fichier contenant les définitions des commandes selon le choix de l'utilisateur
 * Nous travaillons sur des images carrées, ainsi le nombre de colonnes est égale
 * au nombre de ligne d'une composante et le nombre d'élément au total des trois composantes 
 * est le même : pour optimiser la recherche, nous utiliserons à chaque fois 
 * deux boucles pour opérer sur les trois composantes ; et la deuxième boucle 
 * utilisera les mêmes paramètres que la première.
 */

#include "command.h"
#include "ppmio.h"
#include <vector>
#include <iostream>
#include <string>

/**
 * Commande pour effectuer une copie d'image
 */
void copy(string path,
        const vector<vector<int>>& red,
        const vector<vector<int>>& green,
        const vector<vector<int>>& blue)
{
    writePicture(path, red, green, blue);
}

/**
 * Commande pour retirer une composante d'une image
 */
void rmColor(string path,
        const vector<vector<int>>& red,
        const vector<vector<int>>& green,
        const vector<vector<int>>& blue)
{

}

/**
 * Commande pour garder seulement une composante d'une image
 */
void keepColor(string path,
        const vector<vector<int>>& red,
        const vector<vector<int>>& green,
        const vector<vector<int>>& blue)
{
}


/**
 * Commande pour rechercher la présence d'une composante dans une image
 */
void searchColor(const vector<vector<int>>& red,
        const vector<vector<int>>& green,
        const vector<vector<int>>& blue)
{}

/**
 * Commande pour écrire la négation d'une image
 */
void neg(string path,
        const vector<vector<int>>& red,
        const vector<vector<int>>& green,
        const vector<vector<int>>& blue)
{}

/**
 * Commande pour binariser une image
 */
void bin(string path,
        const vector<vector<int>>& red,
        const vector<vector<int>>& green,
        const vector<vector<int>>& blue)
{}

/**
 * Commande pour augmenter ou diminuer la luminosité d'une image
 */
void lum(string path,
        const vector<vector<int>>& red,
        const vector<vector<int>>& green,
        const vector<vector<int>>& blue)
{}

/**
 * Commande pour appliquer une symmétrie verticale à une image
 */
void vertSym(string path,
        const vector<vector<int>>& red,
        const vector<vector<int>>& green,
        const vector<vector<int>>& blue)
{
    // Les composantes en retour (o pour output)
    vector<vector<int>> ored = red, ogreen = green, oblue = blue;

    for (int i = 0; i < oblue.size(); i++)
    {
        for (int j = 0; j < oblue.size(); j++)
        {
            oblue[i][j] = blue[i][blue.size()-j-1];
            ogreen[i][j] = green[i][green.size()-j-1];
            ored[i][j] = red[i][red.size()-j-1];
        }
    }

    writePicture(path, ored, ogreen, oblue);
}

/**
 * Commande pour appliquer une symmétrie horizontale à une image
 */
void horiSym(string path,
        const vector<vector<int>>& red,
        const vector<vector<int>>& green,
        const vector<vector<int>>& blue)
{
    vector<vector<int>> ored = red, ogreen = green, oblue = blue;

    for (int i = 0; i < oblue.size(); i++)
    {
        oblue[i] = blue[blue.size()-i-1];
        ogreen[i] = green[green.size()-i-1];
        ored[i] = red[red.size()-i-1];
    }

    writePicture(path, ored, ogreen, oblue);
}

/**
 * Commande pour tourner une image à 90° dans le sens inverse des aiguilles d'une montre
 */
void turn90(string path,
        const vector<vector<int>>& red,
        const vector<vector<int>>& green,
        const vector<vector<int>>& blue)
{
    vector<vector<int>> ored = red, ogreen = green, oblue = blue;

    for (int i = 0; i < oblue.size(); i++)
    {
        for (int j = 0; j < oblue.size(); j++)
        {
            oblue[i][j] = blue[j][blue.size()-i-1];
            ogreen[i][j] = green[j][green.size()-i-1];
            ored[i][j] = red[j][red.size()-i-1];
        }
    }

    writePicture(path, ored, ogreen, oblue);
}
