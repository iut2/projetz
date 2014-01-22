#include "Camera.h"
#include "Segment.h"
#include "Scene.h"

Camera::Camera(float tx, int res_x, int res_y, Point p2){

     Point p1;

     taille_x = tx;
     taille_y = ((tx*res_y)/res_x);
     m_segment = new Segment(&p1, &p2);
     PointHaut = new Point(0,1,0);

}

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

float Camera::getFocale() {
    return this->m_segment->getPoint2().getz();
}

