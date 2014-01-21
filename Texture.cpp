
#include "Texture.h"
#include "Sphere.h"
#include "Cylindre.h"
#include "Couleur.h"


Texture::Texture(int r, int v, int b) {
    Couleur c(r,v,b);
    this->m_couleur = &c;
    
}

Couleur Texture::getCouleur() {
    return this->m_couleur;
}