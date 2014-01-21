
#include "Segment.h"
#include "Point.h"
#include "Cylindre.h"
#include "Camera.h"

Segment::Segment(Point* p1, Point* p2)
{
    point1 = p1;
    point2 = p2;
}

float Segment::gettaille()
{
    x = p2->getx() - p1->getx();
    y = p2->gety() - p1->gety();
    z = p2->getz() - p1->getz();

   return sqrt(x²+y²+z²);

}
