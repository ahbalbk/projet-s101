/**
 * Fichier d'en-tête contenant les deux fonctions principales gérant 
 * les entrées/sorties avec les images au format PPM
 */
#ifndef PPMIO_H
#define PPMIt_H

#include <vector>
#include <string>

using namespace std;

const int MAX = 100;

/**
 * Procédure qui charge une image au format PPM à parti d'un chemin
 * Elle remplit les vecteurs entrées en paramètre
 * Utilisation:
 * ```cpp
 * vector<vector<int>> red, green, blue;
 * loadPicture("./image.ppm", red, green, blue);
 * ```
 * @param picture Le chemin d'accès vers l'image en entrée
 * @param red Le vecteur à deux dimensions pour représenter la composante rouge
 * @param green La composante verte
 * @param blue La composante bleue
 */
void loadPicture(string picture,
        vector<vector<int>>& red,
        vector<vector<int>>& green,
        vector<vector<int>>& blue);

/**
 * Procédure qui écrit une image au format PPM au chemin indiqué
 * Elle écrit à partir des trois composantes normalisées entrées en paramètre
 * Utilisation (exemple de copie d'image):
 * ```cpp
 * vector<vector<int>> red, green, blue;
 * loadPicture("./image.ppm", red, green, blue);
 * writePicture("./image-copy.ppm", red, green, blue);
 * ```
 * @param picture Le chemin d'accès vers l'image en sortie
 * @param red La composante rouge représentée par un vecteur bidimensionnel
 * @param La composante verte
 * @param La composante bleue
 */
void writePicture(string picture,
        const vector<vector<int>>& red,
        const vector<vector<int>>& green,
        const vector<vector<int>>& blue);

#endif 

