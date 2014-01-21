#ifndef _SPHERE_H
#define _SPHERE_H

//TEST DE PUSH

#include <vector>
#include "Objet.h"

using namespace std;

class Molecule;
class Texture;
class Point;
class Cylindre;
class Couleur;

class Sphere : public Objet {
  private:
    Point m_centre;

    Texture * m_texture;

    //on ne définit pas les cylindres utilisés ici, on en a pas besoin.
    vector<Sphere> ensSpheresLiees;

public:

    Point getCentre();

    Couleur getCouleur();

    Texture getTexture();

};
#endif
