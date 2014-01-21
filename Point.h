#ifndef _POINT_H
#define _POINT_H


class Sphere;
class Segment;
class Camera;

class Point {
  private:




    float x;

    float y;

    float z;




  public:
      
    
    Point(float mx, float my, float mz);

    float getx();

    float gety();

    float getz();

    void setx(float x);

    void sety(float y);

    void setz(float z);

};
#endif
