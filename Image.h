#ifndef _IMAGE_H
#define _IMAGE_H


class Couleur;
class Scene;

class Image {
  private:
    //Nombre de pixels de l'image suivant l'axe x
    int t_x;

    //Nombre de pixels de l'image suivant l'axe y
    int t_y;

    //l'image est celle qui est rendu par la m�thode rendu() de la classe scene. Elle correspond donc � un instantan� pris avec une certaine position de la cam�ra, qui n'est peut etre pas actuelle.
public:
    int getx();

};
#endif
