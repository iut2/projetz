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
     rendu(int resx, int resy);


  private:
    Image * aPourImage;

    //Tampon de profondeur : vecteur d'objets de classe "Objet" ; ces objets sont ins�r�s dans un ordre pr�cis : du plus lointain de la cam�ra au plus proche, afin d'�tre affich�s dans cet ordre, ce qui permet de bien r�aliser les chevauchements.
    //
    //Les objets situ�s derri�re la cam�ra sont ignor�s : ils n'apparaissent pas dans le vecteur.
    //Idem pour les objets int�gralement cach�s.
    //
    //Les objets de ce vecteur ont leurs coordonn�es dans le rep�re de la cam�ra.
    Objet zbuffer;

    //M�thode de calcul de la couleur du pixel donn�. Ce pixel appartient donc au plan de vue.
    Couleur calculCouleur(const Point & pt);


  public:
     actualiser(int resx, int resy);

    //Retourne le rapport entre la r�solution suivant x et la r�solution suivant y de l'image associ�e � la sc�ne
    float getRapport();

    int getResx();

};
#endif
