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

    Point m_centre;

    Texture * sphereUtilise;

    Cylindre * aPourLien;

public:

    Point getCentre();

};
#endif
