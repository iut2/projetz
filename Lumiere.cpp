#include "Lumiere.h"
#include "Point.h"

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
