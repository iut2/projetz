
#include "Molecule.h"
#include "Sphere.h"
#include "Cylindre.h"
#include "Objet.h"

//calcul du barycentre de la mol�cule avec une pond�ration de 1 pour chaque atome
Point Molecule::calculCentre() {
    Point p;
    return p;
}

vector<Sphere> Molecule::getSpheres() {
    return this->ensSpheres;
}

vector<Cylindre> Molecule::getCylindres() {
    return this->ensCylindres;
}
