
#include "Couleur.h"
#include "Texture.h"
#include "Image.h"


Couleur::Couleur(int r, int v, int b) {
    this->rouge = r;
    this->vert = v;
    this->bleu = b;
}

void Couleur::setcouleur(int r, int v, int b){

    this->rouge = r;
    vert = v;
    bleu = b;
}

        int Couleur::getRouge() {
        return this->rouge;
    }

        int Couleur::getBleu() {
        return this->bleu;
    }

        int Couleur::getVert() {
        return this->vert;
    }

