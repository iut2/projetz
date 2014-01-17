#ifndef _POINT_H
#define _POINT_H


class Sphere;
class Segment;
class Camera;

class Point {
  private:
    Sphere * appartientA;

    Segment * appartientASegment;

    float x;

    float y;

    float z;

    Camera * appartientACamera;


  public:
    float getx();

    float gety();

    float getz();

};
#endif
