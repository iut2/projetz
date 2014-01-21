
#include "Couleur.h"
#include "Texture.h"


Couleur::Couleur(int r, int v, int b) {
    this->rouge = r;
    this->vert = v;
    this->bleu = b;
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

