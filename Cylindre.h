#ifndef _CYLINDRE_H
#define _CYLINDRE_H


#include "Objet.h"

class Molecule;
class Texture;
class Segment;
class Sphere;

class Cylindre : public Objet {
  private:
    Segment * m_segment;

    Sphere * m_sphere1;

    Sphere * m_sphere2;

};
#endif
