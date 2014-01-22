#include "Lumiere.h"
#include "Point.h"

Lumiere::Lumiere(float x, float y, float z)
{
    m_point = new Point(x,y,z);
}

float Lumiere::getx() {
    return getPoint().getx();
}

float Lumiere::gety() {
    return getPoint().gety();
}

float Lumiere::getz() {
    return getPoint().getz();
}

Point Lumiere::getPoint(){
    return *(this->m_point);
}
