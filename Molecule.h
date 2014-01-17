#ifndef _MOLECULE_H
#define _MOLECULE_H


#include "Scene.h"
#include "Point.h"
#include <vector>

class Sphere;
class Cylindre;
class Objet;

class Molecule : public Scene {
  private:
    Sphere * ;

    Cylindre * ;

    Objet * ;

    Scene * appartientAScene;


  public:
    //calcul du barycentre de la molécule avec une pondération de 1 pour chaque atome
    Point calculCentre();

    vector<Objets> getObjets();

};
#endif
