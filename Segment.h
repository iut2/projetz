#ifndef _SEGMENT_H
#define _SEGMENT_H


class Point;
class Cylindre;
class Camera;

class Segment {
  private:
    Point * point;

    Cylindre * appartientACylindre;

    Camera * appartientA;

    //Longueur du segment, de type réel. Calculée à partir des points qui constituent le segment.
    float longueur;

};
#endif
