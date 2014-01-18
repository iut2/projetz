#include <stdlib.h>
#include <iostream>
using namespace std;
#include "LecteurCaractere.h"
////////////////////////////////////////////////////////////////////////////////
LecteurCaractere::LecteurCaractere(string nomFich) : f(nomFich.data())
{
  try {

	if (f.fail())
	{
		throw 1;
	}
	else
	  suivant();
  }
  catch (int) {
	   cout << "Fichier \"" << nomFich << "\" non trouve." << endl;
  }
}
////////////////////////////////////////////////////////////////////////////////
void LecteurCaractere::suivant()
{
  if (f.peek()==EOF)
    carCour=EOF;
  else
  {
    f.get(carCour);
  }
}
