#ifndef _MOLECULE_H
#define _MOLECULE_H

using namespace std;

#include "Scene.h"
#include "Point.h"
#include "Objet.h"

#include <vector>

class Sphere;
class Cylindre;
class Objet;

class Molecule : public Scene {
  private:
    Sphere * sphere;

    Cylindre * cylindre;

    Objet * objet;

    Scene scene;


  public:
    //calcul du barycentre de la mol�cule avec une pond�ration de 1 pour chaque atome
    Point calculCentre();

    vector<Objet> getObjets();

};
#endif
