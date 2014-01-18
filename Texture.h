#ifndef _TEXTURE_H
#define _TEXTURE_H


class Sphere;
class Cylindre;
class Couleur;

//Classe contenant la description d'une texture
class Texture {
  private:
    Sphere * sphere;

    Cylindre * cylindre;

    Sphere * estUtiliseParSphere;

    Cylindre * estUtiliseParCylindre;

    Couleur * aPourCouleur;

};
#endif
