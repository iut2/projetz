
#include "Sphere.h"
#include "Molecule.h"
#include "Texture.h"
#include "Point.h"
#include "Cylindre.h"
#include "Couleur.h"
#include "Scene.h"

using namespace std;

Sphere::Sphere(Point centre, int r, int v, int b) {
    this->m_centre = centre;
    Texture tex(r,v,b);
    this->m_texture = &tex;
}

Point Sphere::getCentre() {
    return this->m_centre;
}

Texture Sphere::getTexture() {
    return *(this->m_texture);
}

Couleur Sphere::getCouleur() {
    Texture tex = getTexture();
    return tex.getCouleur();
}

void Sphere::setCentre(Point p) {
    this->m_centre = p;
}

float Sphere::getz() {
    return this->getCentre().getz();
}

Sphere Sphere::projeter(float zp) {
    Point c = this->m_centre.projeter(zp);
    Couleur coul = this->getTexture().getCouleur();
    Sphere s(c,coul.getRouge(),coul.getVert(),coul.getBleu());
    return s;
}

void Sphere::setNum(int num) {
    this->m_numero = num;
    this->m_scene->enregSphere(this,num);
}

void Sphere::ajouterLiaison(int num) {
    Sphere sp = this->m_scene->chercheSphere(num);
    this->ensSpheresLiees.push_back(sp);
}

