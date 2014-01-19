#ifndef _CAMERA_H 0
#define _CAMERA_H


#include "Point.h"

class Segment;
class Scene;

class Camera {
  private:
    //résolution de la caméra (donc du rendu voulu) suivant l'axe X (relatif à la caméra).
    //
    //La valeur initiale donnée est purement conventionnelle : choisie à 64 afin de simplifier les calculs pour des rendu en 640 pixels de largeur.
    float taille_x;

    //résolution de la caméra (donc du rendu voulu) suivant l'axe Y (relatif à la caméra).
    //Il est calculé en fonction de la taille de l'image voulue suivant y
    float taille_y;

    Segment * possedeSegment;

    Scene * scene;

    //Point représentant le haut pour la caméra.
    Point * PointHaut;


  public:
    Point getCoin();


  private:
    //pas pour le changement du pixel courant (lors du calcul de rendu)
    //Est calculé en fonction de la taille de la caméra et du nombre de pixels voulus (taille de l'image)
    float pas;


  public:
     calculAttributs();

    float setPas(float p);

     setTaillex();

     setTailley();

    float getTaillex();

};
#endif
