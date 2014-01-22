
#include "Point.h"
#include "Sphere.h"
#include "Segment.h"
#include "Camera.h"


Point::Point(float mx, float my, float mz) {
    this->x = mx;
    this->y = my;
    this->z = mz;
}

float Point::getx() {
    return this->x;
}

float Point::gety() {
    return this->y;
}

float Point::getz() {
    return this->z;
}

void Point::setx(float x) {
    this->x = x;
}

void Point::sety(float y) {
    this->y = y;
}

void Point::setz(float z) {
    this->z = z;
}

Point Point::projeter(float zp) {
    float xdep = this->getx();
    float ydep = this->gety();

    float xfin = (-zp * xdep)/(1-zp);
    float yfin = (-zp * ydep)/(1-zp);

    Point pfin(xfin,yfin,0);
    return pfin;
}
