#include "ppmio.h"
#include <string>
#include <iostream>
#include <fstream>

/*
======================================================================================================
Definitions des fonctions de lecture et d'ecriture
======================================================================================================

Un fichier .ppm peut �tre ouvert soit par un editeur de texte, soit par un visionneur (gimp par exemple).
Il est de la forme suivante :
P3 (ou P6) : format : P3 indique un codage en ASCII
longueur
largeur
max : valeur du pixel maximal (255)
donnees de l'image : chaque pixel est donne de la forme suivante R G B

par exemple :
P3
2
2
255
255 0 0   100 125 120
0 0 255   255 255 0

Un fichier au format ppm contient donc des entiers separes soit par ' ' ou bien \n ou bien \t
*/


// loadPicture : prend le nom d'un fichier contenant une image au format ppm,
// remplit 3 tableaux 2D avec les donnees de cette image, et renvoie la taille
// effective de ces tableaux (identique pour les 3 tableaux).
// parametres (D) image : cha�ne de caracteres
//  		 (R) tabR, tabB, tabG : tableaux [0,MAX-1][0,MAX-1] d�entiers
void loadPicture(string picture,
        vector <vector <int> > & red,
        vector <vector <int> > & green,
        vector <vector <int> > & blue )
{
    // Declaration des variables
    string line; // pour recuperer les lignes du fichier image au format .ppm, qui est code en ASCII.
    string format; //pour recuperer le format de l'image : celui-ci doit �tre de la forme P3
    string name; // au cas o� l'utilisateur se trompe dans le nom de l'image a charger, on redemande le nom.
    int taille;
    vector <int> mypixels; // pour recuperer les donnees du fichier de maniere lineaire. On repartira ensuite ces donnees dans les tableaux correspondants
    ifstream in; // Declaration d'un "flux" qui permettra ensuite de lire les donnees de l'image.
    streambuf* oldbuf; // declaration d'un "buffer" qui permettra de rediriger les entrees standard (cin) sur le fichier image portant le nom picture
    int hauteur; // pour bien verifier que l'image est carree, et de taille respectant les conditions fixees par l'enonce
    // Initialisation des variables
    name = picture;
    // Permet d'ouvrir le fichier portant le nom picture et de rediriger l'entree standard sur le fichier portant le nom picture :
    // ouverture du fichier portant le nom picture
    in.open(name.c_str( ));
    // redirection de l'entree standard (cin) vers le fichier image.
    oldbuf = cin.rdbuf(in.rdbuf());

    // On verifie que le fichier a bien ete ouvert. Si �a n'est pas le cas, on redemande un nom de fichier valide
    while (!in)
    {
        cin.rdbuf(oldbuf);
        cerr << "Erreur! Impossible de lire de fichier " << name << " ! " << endl;
        cerr << "Redonnez le nom du fichier a ouvrir SVP. Attention ce fichier doit avoir un nom du type nom.ppm." << endl;
        cin >> name;
        in.open(name.c_str( )); // relance
        oldbuf = cin.rdbuf(in.rdbuf());
    }

    // Lecture du nombre definissant le format (ici P3)
    //getline(cin, format);
    cin >> format;
    // on finit de lire la ligne (caractere d'espacement)
    getline(cin, line);

    // Lecture du commentaire
    getline(cin, line);

    //lecture des dimensions
    cin >> taille >> hauteur;
    getline(cin, line); // on finit de lire la ligne (caractere d'espacement)

    // On verifie que l'image a une taille qui verifie bien les conditions requises par l'enonce.
    // Si �a n'est pas le cas, on redemande un fichier valide, et ce, tant que necessaire.
    while (taille != hauteur  || format != "P3")
    {
        if (format != "P3")
        {
            cerr << "Erreur! L'image que vous nous avez donnee a un format ne verifiant pas les conditions requises." << endl;
            cerr << "L'image que vous nous avez donnee doit etre codee en ASCII et non en brut." << endl;
        }

        if (taille != hauteur)
            cerr << "Erreur! L'image que vous nous avez donne n'est pas carree." << endl;

	in.close();

        // On va redemander un nom de fichier valide.
        do
        {
            cin.rdbuf(oldbuf);
            cerr << "Veuillez redonner un nom de fichier qui respecte les conditions de format et de taille. Attention, ce nom doit etre de la forme nom.ppm." << endl;
            cin >> name;
            in.open(name.c_str( )); // relance
            oldbuf = cin.rdbuf(in.rdbuf());
        }while(!in);

         // Lecture du nombre definissant le format (ici P3)
       // getline(cin, format);
         cin >> format;
         getline(cin, line); // on finit de lire la ligne (caractere d'espacement)

        // Lecture du commentaire
        getline(cin, line);

        //lecture des dimensions
        cin >> taille >> hauteur; // relance
        getline(cin, line); // on finit de lire la ligne (caractere d'espacement)
    }

    //Lecture de la valeur max
    getline(cin, line);

    //Lecture des donnees et ecriture dans les tableaux :
    // Pour plus de simplicite, on stocke d'abord toutes les donnees dans mypixels
    // dans l'ordre de lecture puis ensuite on les repartira dans les differents tableaux.
    //Les donnees stockees dans mypixels sont de la forme RGB RGB RGB ....
    // Il faudra donc repartir les valeurs R correspondant a la composante rouge de l'image
    // dans le tableau red, de m�me pour G et B.
    int pix;
    mypixels.resize(3*taille*taille); // taille fixe : on alloue une fois pour toutes
    for (int i = 0; i < 3*taille*taille; i++)
    {
      cin >> pix;
      mypixels[i]=pix;
    }

    // Remplissage des 3 tableaux : on repartit maintenant les valeurs dans les bonnes composantes
    // Comme dans mypixels, les donnees sont stockees de la maniere suivante : RGB RGB RGB, il faut mettre
    // les valeurs correspondant a la composante rouge dans red, ...
    // Ainsi, les valeurs de la composante rouge correspondent aux valeurs stockes aux indices
    // congrus a 0 mod 3 dans mypixels, que les valeurs de la composante verte correspond aux valeurs
    // stockes aux indices sont congrus a 1 mod 3, ...
     // les valeurs d'une ligne
    int val;
    red.resize(taille);
    green.resize(taille);
    blue.resize(taille);
    for (int i = 0; i < taille; i++){
      vector <int> ligneR(taille);
      vector <int> ligneB(taille);  // les lignes ont toutes la m�me taille
      vector <int> ligneG(taille);  
      for (int j = 0; j < taille; j++){
	val =  mypixels[3*j + 3*taille*i];;
	ligneR[j]=val;
	val = mypixels[3*j + 1 + 3*taille*i];
	ligneG[j]=val;
	val = mypixels[3*j + 2 + 3*taille*i];
	ligneB[j]=val;
        }
      red[i]=ligneR;
      green[i]=ligneG;
      blue[i]=ligneB;     
    }

    // Informations a l'utilisateur pour dire que tout s'est bien passe
    cout << " L'image " << name << " a bien ete chargee dans les tableaux ." << endl;
  
 
     in.close();
    // On remet a nouveau l'entree standard sur la console
    cin.rdbuf(oldbuf);
}

// writePicture : prend 3 tableaux 2D, leur taille effective (identique pour les 3),
// cree une image au format ppm a partir des donnees de ces tableaux, et l�enregistre
// dans un fichier.
// parametres (D) tabR, tabB, tabG : tableaux [0,MAX-1][0,MAX-1] d�entiers
//	      (D) image : cha�ne de caracteres

void writePicture( string picture,
        const vector<vector <int> > & red,
        const vector<vector <int> > & green,
        const  vector<vector <int> >  & blue)
{
    // Declaration des variables
    ofstream out;
    streambuf* oldbuf;
    int taille=red.size();  // par exemple. Cela pourrait �tre green ou blue qui de toutes fa�ons doivent avoir la m�me taille. En principe il faudrait verifier
    // Initialisation des variables
    /*On redirige la sortie standard sur le fichier portant le nom picture.
    De cette maniere, lorsque l'on fera appel a cout, la sortie sera ecrite dans le fichier portant le nom picture et non pas sur la console */

    // ouverture (voire creation) du fichier portant le nom picture pour ecrire les donnees
    out.open(picture.c_str( ));
    // redirection de la sortie standard (cout) vers le fichier image.
    oldbuf = std::cout.rdbuf(out.rdbuf());

    // On verifie que le fichier a bien ete cree
    if (!out)
    {
        cerr << "Impossible de creer le fichier " << picture << " ! " << endl;
    }

    else
    {
        // Creer le format, la largeur (les parametres qui ne sont pas dans le tableau
        // Ecriture du nombre definissant le format. On n'utilise que le codage ASCII
        cout << "P3" << endl;
        // Ecriture d'un commentaire (pour calquer au format de Gimp)
        cout << "# Created by IUT d'Informatique d'Orsay Team" << endl;
        // Ecriture des dimensions
        cout << taille << ' ' << taille << endl;
        // Ecriture de la valeur maximale : cette valeur vaut toujours 255 avec le codage RGB
        cout << 255 << endl;

        // Ecriture des donnees, qui se trouvent dans les tableaux fournis par l'utilisateur
        for (int i = 0; i < taille; i++)
        {
            for (int j = 0; j < taille; j++)
            {
                cout << red[i][j] << endl;
                cout << green[i][j] << endl;
                cout << blue[i][j] << endl;
            }
        }

        // Fermeture du fichier une fois que l'on a plus besoin de travailler dessus
        out.close();
        // Redirection de la sortie standard sur la console
        cout.rdbuf(oldbuf);

        // Informations a l'utilisateur pour dire que tout s'est deroule correctement
        cout << "L'image " << picture << " a bien ete cree sur votre disque. " << endl;
    }
}

