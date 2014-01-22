#ifndef _SPHERE_H
#define _SPHERE_H

//TEST DE PUSH

#include <vector>
#include "Objet.h"
#include "Point.h"

class Scene;

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

    Scene * m_scene;

    //on ne définit pas les cylindres utilisés ici, on en a pas besoin.
    vector<Sphere> ensSpheresLiees;

    int m_numero;

public:

    Sphere(Point centre = Point(), int r = 0, int v = 0, int b = 0);

    Point getCentre();

    Couleur getCouleur();

    Texture getTexture();

    void setCentre(Point p);

	void ajoutSphere(Sphere s) {ensSpheresLiees.push_back(s);}

    void setNum(int num);

    void ajouterLiaison(int num); //ajoute la sphère liée

    float getz();

    Sphere projeter(float zp);

};
#endif
