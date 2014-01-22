#include "Camera.h"
#include "Segment.h"
#include "Scene.h"


Point Camera::getCoin() {
    Point p;
    p = this->m_segment->getPoint2();
    float px = p.getx();
    float py = p.gety();

    px = px + taille_x/2.0;
    py = py + taille_y/2.0;

    p.setx(px);
    p.sety(py);

    return p;
}

void Camera::calculAttributs() {
}

float Camera::setPas(float p) {
    return 0.0;
}

void Camera::setTaillex(float tx) {
    this->taille_x = tx;
}

void Camera::setTailley(float ty) {
    this->taille_y = ty;
}

float Camera::getTaillex() {
    return this->taille_x;
}

