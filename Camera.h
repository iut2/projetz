#ifndef _CAMERA_H
#define _CAMERA_H


#include "Point.h"

using namespace std;

class Segment;
class Scene;

class Camera {
  private:
    //r�solution de la cam�ra (donc du rendu voulu) suivant l'axe X (relatif � la cam�ra).
    //
    //La valeur initiale donn�e est purement conventionnelle : choisie � 64 afin de simplifier les calculs pour des rendu en 640 pixels de largeur.
    float taille_x;

    //r�solution de la cam�ra (donc du rendu voulu) suivant l'axe Y (relatif � la cam�ra).
    //Il est calcul� en fonction de la taille de l'image voulue suivant y
    float taille_y;

    Segment * m_segment;

    //Point repr�sentant le haut pour la cam�ra.
    Point * PointHaut;


  public:
    Point getCoin(); //retourne le coin haut-gauche de l'�cran de projection

  private:
    //pas pour le changement du pixel courant (lors du calcul de rendu)
    //Est calcul� en fonction de la taille de la cam�ra et du nombre de pixels voulus (taille de l'image)
    float pas;


  public:

    Camera(float tx, int res_x, int res_y, Point p2);

    void calculAttributs();

    float setPas(float p);

    void setTaillex(float tx);

    void setTailley(float ty);

    float getTaillex();

    float getPas();

    float getFocale();

};
#endif
