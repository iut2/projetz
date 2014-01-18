#ifndef LECTEURSYMBOLE_H_
#define LECTEURSYMBOLE_H_
#include <fstream>
#include <string>
using namespace std;
#include "LecteurCaractere.h"
#include "Symbole.h"

class LecteurSymbole {
public:
	LecteurSymbole(string nomFich);    // r�sultat : symCour = premier symbole du fichier nomFich
	void suivant();                    // passe au symbole suivant du fichier
	inline Symbole getSymCour()      { return symCour; } // accesseur
private:
	LecteurCaractere lc;         // le lecteur de caracteres
	Symbole symCour;             // le symbole courant du lecteur de symboles
	bool sauterSeparateurs();    // saute dans lc une suite de separateurs consecutif, retourne VRAI si il a rencontr� un retour chariot
	void sauterCommentaire();	//sauter les commentaires
	string motSuivant();         // lit dans lc la chaine du prochain symbole et la renvoie en resultat
};
#endif /* LECTEURSYMBOLE_H_ */
