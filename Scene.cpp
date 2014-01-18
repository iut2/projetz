
#include "Scene.h"
#include "Molecule.h"
#include "Camera.h"
#include "Image.h"
#include "Point.h"
#include "LecteurSymbole.h"
using namespace std;



//Constructeur de la classe Scene
Scene::Scene() { //HUGO
    string nomFichier;
	cout << "Nom fichier de la scène ? : " ; cin >> nomFichier;
	LecteurSymbole(nomFichier); //On appelle LecteurSymbole sur le fichier
	/* Lui il va lire tout le fichier et faire des setters pour toutes les class mais j'ai la flemme !
    tous les setters sont bien public ?*/

}

 Scene::rendu(int resx, int resy) {
}

//Méthode de calcul de la couleur du pixel donné. Ce pixel appartient donc au plan de vue.
Couleur Scene::calculCouleur(const Point & pt) {
}

 Scene::actualiser(int resx, int resy) {
}

//Retourne le rapport entre la résolution suivant x et la résolution suivant y de l'image associée à la scène
float Scene::getRapport() {
}

int Scene::getResx() {
}

