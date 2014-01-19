#ifndef _IMAGE_H
#define _IMAGE_H


class Couleur;
class Scene;

class Image {
  private:
    //Nombre de pixels de l'image suivant l'axe x
    int m_x;

    //Nombre de pixels de l'image suivant l'axe y
    int m_y;

    Couleur * ;

    Couleur * ;

    //l'image est celle qui est rendu par la méthode rendu() de la classe scene. Elle correspond donc à un instantané pris avec une certaine position de la caméra, qui n'est peut etre pas actuelle.
    Scene * estRenduDe;


  public:
    int getx();
    void setx();
    void sety();

};
#endif
