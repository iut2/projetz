#ifndef _SCENE_H
#define _SCENE_H


#include "Objet.h"
#include "Couleur.h"

class Molecule;
class Camera;
class Image;
class Point;

//définition de la variable pi
const double M_PI = 3.14159265358979323846;

class Scene {
  private:
    Molecule m_molecule;

    Camera m_camera;
    
    Lumiere m_lumiere;

    //Tampon de profondeur : vecteur d'objets de classe "Objet" ; ces objets sont insérés dans un ordre précis : du plus lointain de la caméra au plus proche, afin d'être affichés dans cet ordre, ce qui permet de bien réaliser les chevauchements.
    //
    //Les objets situés derrière la caméra sont ignorés : ils n'apparaissent pas dans le vecteur.
    //
    //Les objets de ce vecteur ont leurs coordonnées dans le repère de la caméra.
    //
    //Un tampon de profondeur pour les sphères, un pour les cylindres
    vector<Sphere> zbuffer_s;
	vector<Cylindres> zbuffer_c;


  public:
    wxImage rendu(int resx, int resy);


  private:
    
    //Méthode de calcul de la couleur du pixel donné. Ce pixel appartient donc au plan de vue.
    Couleur calculCouleur(const Point & pt);

	actualiser(int resx, int resy);

  public:

    //Retourne le rapport entre la résolution suivant x et la résolution suivant y de l'image associée à la scène
    float getRapport();

    int getResx();

};
#endif
