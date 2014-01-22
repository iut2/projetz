#ifndef _LUMIERE_H
#define _LUMIERE_H

class Point;

class Lumiere {
  private:
    Point * m_point;


  public:

    Lumiere(float x, float y, float z);

    float getx();

    float gety();

    float getz();

    Point getPoint();

};
#endif
