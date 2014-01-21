#ifndef _SEGMENT_H
#define _SEGMENT_H


class Point;
class Cylindre;
class Camera;

class Segment {

  public:

   Segment(Point*p1, Point *p2);
   float gettaille();

  private:
    Point * point1, * point2;

    Cylindre * appartientACylindre;

    Camera * appartientA;
};
#endif
