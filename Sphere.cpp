
#include "Sphere.h"
#include "Molecule.h"
#include "Texture.h"
#include "Point.h"
#include "Cylindre.h"

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
