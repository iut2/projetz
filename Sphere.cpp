
#include "Sphere.h"
#include "Molecule.h"
#include "Texture.h"
#include "Point.h"
#include "Cylindre.h"

Sphere::Sphere(Point centre, int r, int v, int b) {
    this->m_centre = centre;
    Texture tex(r,v,b);
    this->m_texture = &tex;
    ensSpheresLiees = new vector<Sphere>;
}

Point Sphere::getCentre() {
    return this->m_centre;
}

Texture Sphere::getTexture() {
    return this->m_texture;
}

Couleur Sphere::getCouleur() {
    Texture tex = getTexture();
    return tex.getCouleur();
}
