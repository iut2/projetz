#ifndef _LUMIERE_H
#define _LUMIERE_H

class Point;

class Lumiere {
  private:
    Point m_point;


  public:
    float getx();

    float gety();

    float getz();
    
    Point getPoint();

};
#endif
