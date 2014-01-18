#include "LecteurSymbole.h"
#include <ctype.h>
#include <string.h>
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////////////////////
LecteurSymbole::LecteurSymbole(string nomFich) :
	lc(nomFich), symCour("") {
	suivant(); // pour lire le premier symbole
}
////////////////////////////////////////////////////////////////////////////////
void LecteurSymbole::suivant() {

	sauterSeparateurs(); // saute les s�parateurs, on arrive au premier caract�re significatif
	sauterCommentaire(); // saute les commentaire
	// on est maintenant positionn� sur le premier caract�re d'un symbole
	symCour=Symbole(motSuivant()); // on reconstruit symCour avec le nouveau mot lu
}
////////////////////////////////////////////////////////////////////////////////
bool LecteurSymbole::sauterSeparateurs() {
	bool rc = false;
	while (lc.getCarCour()==' '  ||
		   lc.getCarCour()=='\t' ||
		   lc.getCarCour()=='\r' ||
		   lc.getCarCour()=='\n')
		   {
		if (lc.getCarCour()=='\n') {
			rc = true;
		}
		lc.suivant();
	}
	return rc;
}
////////////////////////////////////////////////////////////////////////////////
void LecteurSymbole::sauterCommentaire() {

	sauterSeparateurs();
	if (lc.getCarCour()=='#') {
		while (lc.getCarCour()!='\n') {
			lc.suivant();
		}
		sauterCommentaire();
	}
}
////////////////////////////////////////////////////////////////////////////////
string LecteurSymbole::motSuivant() {
	static string  s;
	s="";

	sauterSeparateurs();
	sauterCommentaire();

	if (lc.getCarCour()!=EOF)
	// c'est un caractere
	{
		s=lc.getCarCour();
		lc.suivant();
	}
	return s;
}
