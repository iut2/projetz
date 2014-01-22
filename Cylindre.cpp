
#include "Cylindre.h"
#include "Molecule.h"
#include "Texture.h"
#include "Segment.h"
#include "Sphere.h"


Cylindre::Cylindre(Sphere *S1, Sphere *S2){

    m_sphere1 = S1;
    m_sphere2 = S2;
    setRayon(5.0);
}

float Cylindre::getz() {
    Point this->m_segment->getPoint1();
    Point this->m_segment->getPoint2();
    float z1 = p1.getz();
    float z2 = p2.getz();

    if (z1<z2) {
        return z2;
    } else {
        return z1;
    }
}
