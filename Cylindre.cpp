
#include "Cylindre.h"
#include "Molecule.h"
#include "Texture.h"
#include "Segment.h"
#include "Sphere.h"


Cylindre::Cylindre(Sphere *S1, Sphere *S2){

    m_sphere1 = S1;
    m_sphere2 = S2;
    setRayon(/* A definir */ 0.0);
}
