#ifndef _CYLINDRE_H
#define _CYLINDRE_H


#include "Objet.h"
#include "Segment.h"
#include "Sphere.h"
#include <stdlib.h>

class Molecule;
class Texture;
class Segment;
class Sphere;

class Cylindre : public Objet {
  public :
    Cylindre(Sphere *S1 = NULL, Sphere *S2 = NULL);
    inline float gethauteur() { return m_segment->gettaille(); }
	inline Sphere getsphere1() {return *m_sphere1;}
	inline Sphere getsphere2() {return *m_sphere2;}
	float getz(); //retourne le z du point le plus proche

  private:
    Segment * m_segment;

    Sphere * m_sphere1;

    Sphere * m_sphere2;

};
#endif
