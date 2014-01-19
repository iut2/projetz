#ifndef _LUMIERE_H
#define _LUMIERE_H

class Point;

class Lumiere {
  private:
    Point m_point;


  public:
    float getx();
    void setx();

    float gety();
    void sety);

    float getz();
    void setz();

    Point getPoint();

};
#endif
