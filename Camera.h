#ifndef _CAMERA_H 0
#define _CAMERA_H


#include "Point.h"

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

    Segment * possedeSegment;

    Scene * scene;

    //Point repr�sentant le haut pour la cam�ra.
    Point * PointHaut;


  public:
    Point getCoin();


  private:
    //pas pour le changement du pixel courant (lors du calcul de rendu)
    //Est calcul� en fonction de la taille de la cam�ra et du nombre de pixels voulus (taille de l'image)
    float pas;


  public:
     calculAttributs();

    float setPas(float p);

     setTaillex();

     setTailley();

    float getTaillex();

};
#endif
