#ifndef _SPHERE_H
#define _SPHERE_H

//TEST DE PUSH

#include "Objet.h"

class Molecule;
class Texture;
class Point;
class Cylindre;

class Sphere : public Objet {
  private:
    Molecule * ;

    Texture * ;

    Point * possedePoint;

    Texture * sphereUtilise;

    Cylindre * aPourLien;

};
#endif
