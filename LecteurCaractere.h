#ifndef LECTEURCARACTERE_H_
#define LECTEURCARACTERE_H_
#include <fstream>
using namespace std;

class LecteurCaractere {
  ////////////////////////////////////////////////////////////////////////////////
  public :
    LecteurCaractere(string nomFich); // construit le lecteur pour parcourir nomFich
    inline char         getCarCour() { return carCour; } // accesseur
    void suivant(); // passe au caractere suivant, s'il existe
  ////////////////////////////////////////////////////////////////////////////////
  private :
    ifstream f;           // le fichier texte que l'on parcourt
    char carCour;         // le caractere courant
};
#endif /* LECTEURCARACTERE_H_ */
