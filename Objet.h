#ifndef _OBJET_H
#define _OBJET_H


class Molecule;
class Texture;

class Objet {
  private:
    float rayon;
    Texture * m_texture;

  public:
    float getRayon();
    void setRayon(float r);
    virtual float getz() = 0; //récupération du z, à redéfinir dans les héritages

};
#endif
