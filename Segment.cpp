#include "Segment.h"
#include "Point.h"
#include "Cylindre.h"
#include "Camera.h"
#include <stdio.h>
#include <math.h>

Segment::Segment(Point* p1, Point* p2)
{
    point1 = p1;
    point2 = p2;
}

float Segment::gettaille()
{
    float x = point2->getx() - point1->getx();
    float y = point2->gety() - point1->gety();
    float z = point2->getz() - point1->getz();

   return sqrt(x*x+y*y+z*z);

}

   Point Segment::getPoint1(){
        return *point1;
   }
   Point Segment::getPoint2(){
        return *point2;
   }
