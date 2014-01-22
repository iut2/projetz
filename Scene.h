#ifndef _SCENE_H
#define _SCENE_H

#include <vector>
#include "Objet.h"
#include "Couleur.h"
#include <wx/wx.h>
#include <wx/image.h>


using namespace std;

class Molecule;
class Camera;
class Image;
class Point;
class Lumiere;
class Sphere;
class Cylindre;

//définition de la variable pi
#ifndef M_PI
const double M_PI = 3.14159265358979323846;
#endif

class Scene {
  private:
    Molecule * m_molecule;

    Camera * m_camera;

    Lumiere * m_lumiere;

    //Tampon de profondeur : vecteur d'objets de classe "Objet" ; ces objets sont insérés dans un ordre précis : du plus lointain de la caméra au plus proche, afin d'être affichés dans cet ordre, ce qui permet de bien réaliser les chevauchements.
    //
    //Les objets situés derrière la caméra sont ignorés : ils n'apparaissent pas dans le vecteur.
    //
    //Les objets de ce vecteur ont leurs coordonnées dans le repère de la caméra.
    //
    //Un tampon de profondeur pour les sphères, un pour les cylindres
    vector<Sphere> zbuffer_s;
	vector<Cylindre> zbuffer_c;


  public:
    wxImage rendu(int resx, int resy);
    wxImage renduSimple(int resx, int resy);

  private:

    //Méthode de calcul de la couleur du pixel donné. Ce pixel appartient donc au plan de vue.
    Couleur calculCouleur(const Point & pt);

	void actualiser(int resx, int resy);
	bool compare(Objet obja, Objet objb); //retourne vrai si obja > objb

  public:

    //Retourne le rapport entre la résolution suivant x et la résolution suivant y de l'image associée à la scène
 //   float getRapport();

//Changement de repère
//rx, ry, rz : angles suivant axes respectifs
//tx, ty, tz : translation suivant axes respectifs
//p : point à déplacer
    Point changementRepere(Point p, float rx,float ry, float rz, float tx, float ty, float tz);

Molecule chgtRepBary(Molecule m);

Molecule rotationMolecule(Molecule m, float angleX, float angleY, float angleZ);

Molecule retourRepAvBary(Molecule m);

void dessineSeg(Segment s, wxImage &img);

};
#endif
