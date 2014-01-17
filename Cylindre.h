#ifndef _CYLINDRE_H
#define _CYLINDRE_H


#include "Objet.h"

class Molecule;
class Texture;
class Segment;
class Sphere;

class Cylindre : public Objet {
  private:
    Molecule * ;

    Texture * ;

    Segment * possedeSegment;

    Texture * cylindreUtilise;

    Sphere * lieSpheres;

};
#endif
