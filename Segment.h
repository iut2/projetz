#ifndef _SEGMENT_H
#define _SEGMENT_H


class Point;
class Cylindre;
class Camera;

class Segment {

  public:

   Segment(Point *p1, Point *p2);
   float gettaille();
   Point getPoint1();
   Point getPoint2();

  private:
    Point * point1, * point2;

};
#endif
