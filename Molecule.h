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
        vector<Sphere> ensSpheres;

        vector<Cylindre> ensCylindres;

        Point m_centre;

    //calcul du barycentre de la molécule avec une pondération de 1 pour chaque atome
    Point calculCentre();


  public:

    Molecule();

    Point getCentre();

    vector<Sphere> getSpheres();

    vector<Cylindre> getCylindres();

    int getnbSpheres();

    int getnbCylindres();

    void ajouterSphere(Sphere s);

    void ajouterCylindre(Cylindre c);

};
#endif
