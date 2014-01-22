
#include "Cylindre.h"
#include "Molecule.h"
#include "Texture.h"
#include "Segment.h"
#include "Sphere.h"
#include "Point.h"


Cylindre::Cylindre(Sphere *S1, Sphere *S2){

    m_sphere1 = S1;
    m_sphere2 = S2;

    Point p1 = m_sphere1->getCentre();
    Point p2 = m_sphere2->getCentre();

    Segment seg(&p1,&p2);

    this->m_segment = &seg;

    setRayon(5.0);
}

float Cylindre::getz() {
    Point p1 = this->m_segment->getPoint1();
    Point p2 = this->m_segment->getPoint2();
    float z1 = p1.getz();
    float z2 = p2.getz();

    if (z1<z2) {
        return z2;
    } else {
        return z1;
    }
}

Cylindre Cylindre::projeter(float zp) {
    Cylindre cyl(this->m_sphere1,this->m_sphere2);
    cyl.getSegment()->projeter(zp);
    return cyl;
}

Segment * Cylindre::getSegment() {
    return this->m_segment;
}
