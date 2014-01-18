#ifndef _SCENE_H
#define _SCENE_H


#include "Objet.h"
#include "Couleur.h"

class Molecule;
class Camera;
class Image;
class Point;

class Scene {
  private:
    Molecule * molecule;

    Camera * possedeCamera;


  public:
      Scene();
      void rendu(int resx, int resy);


  private:
    Image * aPourImage;

    //Tampon de profondeur : vecteur d'objets de classe "Objet" ; ces objets sont insérés dans un ordre précis : du plus lointain de la caméra au plus proche, afin d'être affichés dans cet ordre, ce qui permet de bien réaliser les chevauchements.
    //
    //Les objets situés derrière la caméra sont ignorés : ils n'apparaissent pas dans le vecteur.
    //Idem pour les objets intégralement cachés.
    //
    //Les objets de ce vecteur ont leurs coordonnées dans le repère de la caméra.
    Objet zbuffer;

    //Méthode de calcul de la couleur du pixel donné. Ce pixel appartient donc au plan de vue.
    Couleur calculCouleur(const Point & pt);


  public:
    void actualiser(int resx, int resy);

    //Retourne le rapport entre la résolution suivant x et la résolution suivant y de l'image associée à la scène
    float getRapport();

    int getResx();

};
#endif
