#ifndef _SEGMENT_H
#define _SEGMENT_H


class Point;
class Camera;

class Segment {

  public:

   Segment(Point *p1, Point *p2);
   float gettaille();
   Point getPoint1();
   Point getPoint2();
   Segment projeter(float zp);

  private:
    Point * point1, * point2;

};
#endif
