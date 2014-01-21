#ifndef _SPHERE_H
#define _SPHERE_H

//TEST DE PUSH

#include <vector>
#include "Objet.h"
#include "Point.h"

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
    vector<int> ensSpheresLiees;

    int m_numero;

public:
    
    Sphere(Point centre, int r, int v, int b);
    
    Point getCentre();

    Couleur getCouleur();

    Texture getTexture();

    void setCentre(Point p);

    void setNum(int num);

    void ajouterLiaison(int num); //ajoute le numéro de la sphère liée

};
#endif
