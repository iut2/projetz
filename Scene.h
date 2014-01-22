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

//d�finition de la variable pi
#ifndef M_PI
const double M_PI = 3.14159265358979323846;
#endif

class Scene {
  private:
    Molecule * m_molecule;

    Camera * m_camera;

    Lumiere * m_lumiere;

    //Tampon de profondeur : vecteur d'objets de classe "Objet" ; ces objets sont ins�r�s dans un ordre pr�cis : du plus lointain de la cam�ra au plus proche, afin d'�tre affich�s dans cet ordre, ce qui permet de bien r�aliser les chevauchements.
    //
    //Les objets situ�s derri�re la cam�ra sont ignor�s : ils n'apparaissent pas dans le vecteur.
    //
    //Les objets de ce vecteur ont leurs coordonn�es dans le rep�re de la cam�ra.
    //
    //Un tampon de profondeur pour les sph�res, un pour les cylindres
    vector<Sphere> zbuffer_s;
	vector<Cylindre> zbuffer_c;

	map<int,Sphere> mapSpheres;


  public:
    wxImage rendu(int resx, int resy);
    Scene() ;
    Sphere chercheSphere(int i);
  //  Scene(Point p2,float tx, int res_x, int res_y, float x, float y, float z);


  private:

    //M�thode de calcul de la couleur du pixel donn�. Ce pixel appartient donc au plan de vue.
    Couleur calculCouleur(const Point & pt);

	void actualiser(int resx, int resy);
	bool compare(Objet * obja, Objet * objb); //retourne vrai si obja > objb

  public:

    //Retourne le rapport entre la r�solution suivant x et la r�solution suivant y de l'image associ�e � la sc�ne
 //   float getRapport();

//Changement de rep�re
//rx, ry, rz : angles suivant axes respectifs
//tx, ty, tz : translation suivant axes respectifs
//p : point � d�placer
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
