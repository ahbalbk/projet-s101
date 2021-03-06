/**
* Fichier contenant les définitions des commandes selon le choix de l'utilisateur
* Nous travaillons sur des images carrées, ainsi le nombre de colonnes est égale
* au nombre de ligne d'une composante et le nombre d'élément au total des trois composantes 
* est le même : pour optimiser la recherche, nous utiliserons à chaque fois 
* deux boucles pour opérer sur les trois composantes ; et la deuxième boucle 
* utilisera les mêmes paramètres que la première.
*/

#include "command.h"
#include "menu.h"
#include "ppmio.h"
#include <cmath>
#include <vector>
#include <iostream>
#include <string>

/**
 * Mohamed Yaiche
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
 * Ahmad Baalbaky
 * Fonction qui retourne une composante noire de la même taille que celle en entrée
 * Elle est utilisée pour supprimer une composante d'une image
 *
 * @param comp La composante en entrée
 * @return Une composante noire de même taille
 */
vector<vector<int>> black(const vector<vector<int>>& comp)
{
    vector<int> blackLine(comp.size(), 0);
    vector<vector<int>> out(comp.size(), blackLine);
    return out;
}

/**
 * Mohamed Yaiche
* Commande pour retirer une composante d'une image
*/
void rmColor(string path,
    const vector<vector<int>>& red,
    const vector<vector<int>>& green,
    const vector<vector<int>>& blue)
{
    int color = menuGetColor("Choisissez la couleur à retirer");
    vector<vector<int>> blackC = black(blue);
    switch (color)
    {
    case RED:
        writePicture(path, blackC, green, blue);
        break;
    case GREEN:
        writePicture(path, red, blackC, blue);
        break;
    case BLUE:
        writePicture(path, red, green, blackC);
        break;
    default:
        menuUnimplemented();
    }
}

/**
 * Mohamed Yaiche
* Commande pour garder seulement une composante d'une image
*/
void keepColor(string path,
    const vector<vector<int>>& red,
    const vector<vector<int>>& green,
    const vector<vector<int>>& blue)
{
    int color = menuGetColor("Choisissez la couleur à garder");
    vector<vector<int>> blackC = black(blue);
    switch (color)
    {
    case RED:
        writePicture(path, red, blackC, blackC);
        break;
    case GREEN:
        writePicture(path, blackC, green, blackC);
        break;
    case BLUE:
        writePicture(path, blackC, blackC, blue);
        break;
    default:
        menuUnimplemented();
    }
}

/**
 * Ahmad Baalbaky
 * Fonction utilisée pour savoir si une image est noire ou non
 *
 * @param comp La composante en question
 * @return Vrai si la composante est présente, faux sinon
 */
bool isPresent(const vector<vector<int>>& comp)
{
    for (int i = 0; i < comp.size(); i++)
    {
        for (int j = 0; j < comp.size(); j++)
        {
            if (comp[i][j] > 0) return true;
        }
    }
    return false;
}
/**
 * Mohamed Yaiche
* Commande pour rechercher la présence d'une composante dans une image
*/
void searchColor(const vector<vector<int>>& red,
    const vector<vector<int>>& green,
    const vector<vector<int>>& blue)
{
    int color = menuGetColor("Choisissez la couleur à rechercher");
    bool found;

    switch (color)
    {
    case RED:
        found = isPresent(red);
        break;
    case GREEN:
        found = isPresent(green);
        break;
    case BLUE:
        found = isPresent(blue);
        break;
    default:
        menuUnimplemented();
    }

    string sentence = found ? " est bien " : " n'est pas ";
    cout << "La couleur " << C_MENU[color-1] << sentence << "présente dans l'image.\n";
}

/**
 * Mohamed Yaiche
* Commande pour écrire la négation d'une image
*/
void neg(string path,
    const vector<vector<int>>& red,
    const vector<vector<int>>& green,
    const vector<vector<int>>& blue)
{
    vector<vector<int>> ored = red, ogreen = green, oblue = blue;

    for (int i = 0; i < red.size(); i++)
    {
        for (int j = 0; j < red.size(); j++)
        {
            ored[i][j] = 255 - red[i][j];
            ogreen[i][j] = 255 - green[i][j];
            oblue[i][j] = 255 - blue[i][j];
        }
    }

    writePicture(path, ored, ogreen, oblue);
}

/**
 * Mohamed Yaiche
* Commande pour binariser une image
*/
void bin(string path,
    const vector<vector<int>>& red,
    const vector<vector<int>>& green,
    const vector<vector<int>>& blue)
{
    vector<vector<int>> ored = red, ogreen = green, oblue = blue;
    int seuil = menuAskNum("Entrez un seuil pour la binarisation", 0, 255);

    for (int i = 0; i < red.size(); i++)
    {
        for (int j = 0; j < red.size(); j++)
        {
            if (red[i][j] > seuil && green[i][j] > seuil && blue[i][j] > seuil)
            {
                ored[i][j] = 255;
                ogreen[i][j] = 255;
                oblue[i][j] = 255;
            }
            else
            {
                ored[i][j] = 0;
                ogreen[i][j] = 0;
                oblue[i][j] = 0;
            }
        }
    }

    writePicture(path, ored, ogreen, oblue);
}

/**
 * Ahmad Baalbaky
 * Procédure utilisée pour normaliser un pixel des trois composantes
 * Elle garantie que le pixel est compris entre 0 et 255 inclus
 *
 * @param red La composante rouge
 * @param green La composante verte 
 * @param blue La composante bleue
 */
void normalize(int& red, int& green, int& blue)
{
    if (red > 255) red = 255;
    else if (red < 0) red = 0;

    if (green > 255) green = 255;
    else if (green < 0) green = 0;

    if (blue > 255) blue = 255;
    else if (blue < 0) blue = 0;
}

/**
 * Mohamed Yaiche
* Commande pour augmenter ou diminuer la luminosité d'une image
*/
void lum(string path,
    const vector<vector<int>>& red,
    const vector<vector<int>>& green,
    const vector<vector<int>>& blue)
{
    vector<vector<int>> ored = red, ogreen = green, oblue = blue;
    int a = menuAskNum("Entrez un seuil pour changer la luminosité", 0, 255);

    for (int i = 0; i < red.size(); i++)
    {
        for (int j = 0; j < red.size(); j++)
        {
            ored[i][j] = a*red[i][j];
            ogreen[i][j] = a*green[i][j];
            oblue[i][j] = a*blue[i][j];

            normalize(ored[i][j], ogreen[i][j], oblue[i][j]);
        }
    }

    writePicture(path, ored, ogreen, oblue);
}

/**
 * Mohamed Yaiche
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
            // On inverse l'ordre des colonnes
            // Donc on assigne au pixel à la colonne j le pixel à la colonne n-j
            // (avec n la taille de l'image)
            // Les indices commencent à 0, donc on n'oublie pas de soustraire - 1
            // pour éviter de donner un indice trop grand
            oblue[i][j] = blue[i][blue.size()-j-1];
            ogreen[i][j] = green[i][green.size()-j-1];
            ored[i][j] = red[i][red.size()-j-1];
        }
    }

    writePicture(path, ored, ogreen, oblue);
}

/**
 * Mohamed Yaiche
* Commande pour appliquer une symmétrie horizontale à une image
*/
void horiSym(string path,
    const vector<vector<int>>& red,
    const vector<vector<int>>& green,
    const vector<vector<int>>& blue)
{
    // Les composantes en retour (o pour output)
    vector<vector<int>> ored = red, ogreen = green, oblue = blue;

    for (int i = 0; i < oblue.size(); i++)
    {
        // On inverse l'ordre des lignes
        // Donc on assigne au pixel à la ligne i le pixel à la ligne n-i
        // (avec n la taille de l'image)
        // Sans oublier le -1 car les indices commencent à 0
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
    // Les composantes en retour (o pour output)
    vector<vector<int>> ored = red, ogreen = green, oblue = blue;

    for (int i = 0; i < oblue.size(); i++)
    {
        for (int j = 0; j < oblue.size(); j++)
        {
            // Pour tourner l'image à 90°, on inverse les lignes et les colonnes
            // Cela a pour effect d'appliquer une symmétrie diagonale
            // il faut donc en plus appliquer une symmétrie horizontale, 
            // pour pouvoir la tourner dans le sens inverse des aiguilles d'une montre
            oblue[i][j] = blue[j][blue.size()-i-1];
            ogreen[i][j] = green[j][green.size()-i-1];
            ored[i][j] = red[j][red.size()-i-1];
        }
    }

    writePicture(path, ored, ogreen, oblue);
}

/**
 * Commande pour appliquer un filtre à une image
 */
void filter(string path,
    const vector<vector<int>>& red,
    const vector<vector<int>>& green,
    const vector<vector<int>>& blue)
{
    // On demande à l'utilisateur de saisir le filtre
    vector<vector<double>> filter = menuGetFilter();
    // L'indice du milieu du filtre
    int mid = filter.size()/2;

    // On initialise toutes les composantes de sortie en noir
    vector<vector<int>> ored = black(red), ogreen = ored, oblue = ogreen;

    // On parcourt toute l'image du premier pixel jusqu'au nImage-nFiltre-ième pixel
    // avec nImage la taille de l'image et nFiltre la taille du filtre
    // pour opérer sur les pixels visés par le milieu du filtre (i+mid, j+mid)
    // Ainsi, les pixels au bord de l'image ne sont pas touchés
    for (int i = 0; i <= oblue.size()-filter.size(); i++)
    {
        for (int j = 0; j <= oblue.size()-filter.size(); j++)
        {
            // Les valeurs qui vont être assignées aux composantes de chaque pixel
            int curR = 0, curG = 0, curB = 0;

            // On parcourt le filtre à chaque pixel
            for (int fline = 0; fline < filter.size(); fline++)
            {
                for (int fcol = 0; fcol < filter.size(); fcol++)
                {
                    // On multiplie la valeur dans le filtre
                    // par le pixel à l'indice [i+fline][j+fcol]
                    // et on additionne le résultat à la composante en sortie
                    curR += filter[fline][fcol] * (double) red[i+fline][j+fcol];
                    curG += filter[fline][fcol] * (double) green[i+fline][j+fcol];
                    curB += filter[fline][fcol] * (double) blue[i+fline][j+fcol];
                }
            }

            // On normalise les valeurs pour qu'elles soient comprises
            // entre 0 et 255
            normalize(curR, curG, curB);

            // On assigne aux pixels des composantes en sortie leur valeur correspondante
            ored[i+mid][j+mid] = curR;
            ogreen[i+mid][j+mid] = curG;
            oblue[i+mid][j+mid] = curB;
        }
    }

    writePicture(path, ored, ogreen, oblue);
}

/**
* Commande pour appliquer les filtres de Sobel à une image
*/
void sobelFilter(string path,
    const vector<vector<int>>& red,
    const vector<vector<int>>& green,
    const vector<vector<int>>& blue)
{
    vector<vector<int>> filterA = {
        {-1, -2, -1},
        {0, 0, 0},
        {1, 2, 1}
    }, filterB = {
        {1, 0, -1},
        {2, 0, -2},
        {1, 0, -1}
    };
    // L'indice du milieu du filtre
    int mid = 1;

    // On initialise toutes les composantes de sortie en noir
    vector<vector<int>> ored = black(red), ogreen = ored, oblue = ogreen;

    for (int i = 0; i <= oblue.size()-filterA.size(); i++)
    {
        for (int j = 0; j <= oblue.size()-filterA.size(); j++)
        {
            // Les valeurs qui vont être assignées aux composantes de chaque pixel
            int curRA = 0, curGA = 0, curBA = 0,
                curRB = 0, curGB = 0, curBB = 0;

            // On parcourt le filtre à chaque pixel
            for (int fline = 0; fline < filterA.size(); fline++)
            {
                for (int fcol = 0; fcol < filterA.size(); fcol++)
                {
                    // On multiplie la valeur dans le filtre
                    // par le pixel à l'indice [i+fline][j+fcol]
                    // et on additionne le résultat à la composante en sortie
                    curRA += filterA[fline][fcol] * (double) red[i+fline][j+fcol];
                    curGA += filterA[fline][fcol] * (double) green[i+fline][j+fcol];
                    curBA += filterA[fline][fcol] * (double) blue[i+fline][j+fcol];

                    // On fait la même chose pour le filtre B
                    curRB += filterB[fline][fcol] * (double) red[i+fline][j+fcol];
                    curGB += filterB[fline][fcol] * (double) green[i+fline][j+fcol];
                    curBB += filterB[fline][fcol] * (double) blue[i+fline][j+fcol];
                }
            }

            // On normalise les valeurs pour qu'elles soient comprises
            // entre 0 et 255
            normalize(curRA, curGA, curBA);
            normalize(curRB, curGB, curBB);
            // On assigne aux pixels des composantes en sortie leur valeur correspondante
            ored[i+mid][j+mid] = sqrt(curRA*curRA + curRB*curRB);
            ogreen[i+mid][j+mid] = sqrt(curGA*curGA + curGB*curGB);
            oblue[i+mid][j+mid] = sqrt(curBA*curBA + curBB*curBB);
        }
    }

    writePicture(path, ored, ogreen, oblue);
}
