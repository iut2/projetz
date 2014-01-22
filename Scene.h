#ifndef _SCENE_H
#define _SCENE_H

#include <vector>
#include "Objet.h"
#include "Couleur.h"
#include "Segment.h"
#include "Sphere.h"
#include "Cylindre.h"
#include <wx/wx.h>
#include <wx/image.h>
#include <map>


using namespace std;

class Molecule;
class Camera;
class Image;
class Point;
class Lumiere;

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

	map<int,Sphere> mapSpheres;


  public:
    wxImage rendu(int resx, int resy);
    Scene() ;
    Sphere chercheSphere(int i);
  //  Scene(Point p2,float tx, int res_x, int res_y, float x, float y, float z);


  private:

    //Méthode de calcul de la couleur du pixel donné. Ce pixel appartient donc au plan de vue.
    Couleur calculCouleur(const Point & pt);

	void actualiser(int resx, int resy);
	bool compare(Objet * obja, Objet * objb); //retourne vrai si obja > objb

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

wxImage renduSimple(vector<Segment> listeSeg);

Molecule projeter();

vector<Segment> getObjEcran();

void initMolecule();

void setMolecule(Molecule mol);

void enregSphere(Sphere * sp, int num);

};
#endif
