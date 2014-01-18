#include <ctype.h>
#include <iostream>
#include <fstream>
using namespace std;

#include "Symbole.h"

////////////////////////////////////////////////////////////////////////////////
Symbole::Symbole(string s) {
	this->chaine=s;
}


/*A MODIFIER Faudrai transformer ça en procédure qui boucle et qui fait tous les setters
Mais avant de faire ça j'aimerai mieux comprendre ce que fait cette fonction */
////////////////////////////////////////////////////////////////////////////////
bool Symbole::isMotCle(string s) {
	static vector <string> motsCles; // vecteur pour stocker les mots clés du langage
	// si on n'a pas encore chargé les mots clés dans le vecteur, on le fait !
	if (!motsCles.size()) {
		ifstream fichier(FICHIER_MOTS_CLE, ifstream::in);
		while (!fichier.eof()) {
			string mot;
			getline(fichier, mot);
			if (mot!="") { // insertion triée de s dans le vecteur des mots clés
  				vector<string>::iterator it = motsCles.begin();
  				while (it<motsCles.end() && *it < mot) it++;
  				if (it==motsCles.end() || *it != mot) // si pas trouvé...
    					motsCles.insert(it, mot);
			}
		}
		fichier.close();
	}
 	// on recherche  s dans le vecteur des mots clés triés
	unsigned int i;
	for (i=0; i<motsCles.size() && motsCles[i]<s; i++) ;
	return (i<motsCles.size() && motsCles[i]==s);
}
