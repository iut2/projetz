
#include "Molecule.h"
#include "Sphere.h"
#include "Point.h"
#include "Cylindre.h"
#include "Objet.h"


Molecule::Molecule() {
    this->m_centre = calculCentre();
}

Molecule::Molecule(Point centre, vector<Sphere> ensS, vector<Cylindre> ensC) {
    this->m_centre = centre;
    this->ensSpheres = ensS;
    this->ensCylindres = ensC;
}


//calcul du barycentre de la mol�cule avec une pond�ration de 1 pour chaque atome
Point Molecule::calculCentre() {


    int i;
    int nb;
    float x;
    float y;
    float z;
    Point p;

    x=0;
    y=0;
    z=0;

    nb = this->getnbSpheres();

    for(i=1;i<=nb;i++) {
        p = ensSpheres[i].getCentre();
        x = p.getx() + x;
        y = p.gety() + y;
        z = p.getz() + z;
    }

    x = x / nb;
    y = y / nb;
    z = z / nb;

    p.setx(x);
    p.sety(y);
    p.setz(z);

    return p;

}



void Molecule::ajouterSphere(Sphere s) {
    ensSpheres.push_back(s);
}

vector<Sphere> Molecule::getSpheres() {
    return this->ensSpheres;
}

void Molecule::ajouterCylindre(Cylindre c) {
    ensCylindres.push_back(c);
}

vector<Cylindre> Molecule::getCylindres() {
    return this->ensCylindres;
}

int Molecule::getnbCylindres() {
    return ensCylindres.size();
}

int Molecule::getnbSpheres() {
    return ensSpheres.size();
}

Point Molecule::getCentre() {
    return this->m_centre;
}

Molecule Molecule::projeter(float zp) {
    vector<Sphere> m_ensS = this->getSpheres();
    vector<Cylindre> m_ensC = this->getCylindres();
    unsigned int nbs = m_ensS.size();
    unsigned int nbc = m_ensC.size();
    vector<Sphere> ensS;
    vector<Cylindre> ensC;

    for(unsigned int i = 0; i<nbs; i++) {
        ensS[i] = m_ensS[i].projeter(zp);
    }

    for (unsigned int i = 0; i<nbc; i++) {
        ensC[i] = m_ensC[i].projeter(zp);
    }

    Point bary = this->m_centre.projeter(zp);
    Molecule m(bary,ensS,ensC);
    return m;
}
