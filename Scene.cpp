#include "Scene.h"
#include "Molecule.h"
#include "Camera.h"
#include "Image.h"
#include "Point.h"
#include <math.h>

//Constructeur de la classe Scene
Scene::Scene() {
	//TODO HUGO
}

//Méthode appelée par l'application utilisant le moteur ; retourne une image bitmap utilisable par wxWidget
wxImage Scene::rendu(int resx, int resy) {
	//On actualise les éléments relatifs à notre scène
	this->actualiser();
	
	//Après actualisation, nous sommes plaçés dans un repère relatif à la caméra :
	//		l'axe des x vers le haut,
	//		des y vers la droite,
	//		des z vers l'avant.
	//Le point de vue de l'observateur est alors 0,0,0
	
	//Création d'une nouvelle image de taille resx,resy ; vierge (noire) grâce au true
	wxImage image = wxImage(resx,resy,true);
	
	//TODO on enregistre les paramètres de l'image : à voir si c'est réellement nécéssaire, sinon, supprimer la classe Image
	
	//on calcule la couleur de chaque pixel de l'image
	
	//initialisation des variables :
	//		pix est le point à calculer,
	//		p le pas à appliquer à chaque itération
	Point pix = m_camera.getCoin();
	float p = m_camera.getPas();
	//Initialisation des coordonnées du pixel courant
	float px = (float)pix.getx();
	float py = (float)pix.gety();
	float pz = (float)pix.getz();
	
	//Objets pour les itérations
	Cylindre cy;
	Sphere sp;
	unsigned int taille_c = this->zbuffer_c.getsize(); //récupération du nombre de cylindres
	unsigned int taille_s = this->zbuffer_s.getsize(); //récupération du nombre de sphères
	
	
	
	for (unsigned int x=0 ; x<resx ; x++) {
		for (unsigned int y=0 ; y<resy ; y++) {
			//TODO calcul d'un point d'intersection rayon/cylindre : itération sur zbuffer_c
			//JEAN-DENIS (inspire toi de mon code)
			
			//Détermination d'un potentiel point d'intersection avec une sphère
			//Itération sur zbuffer_s
			for (unsigned int i=0 ; i<taille_s ; i++) {
				//on récupère la sphère la plus proche suivant z
				sp = zbuffer_s[i];
				//On calcul le déterminant delta = b²-4ac
				float a = px^2 + py^2 + pz^2;
				Point m = sp.getCentre(); //On résupère le centre de la sphère
				float mx = m.getx();
				float my = m.gety();
				float mz = m.getz();
				float b = -2 * (px * mx + py * my + pz * mz);
				float c = ( mx^2 + my^2 + mz^2 - sp.getRayon()^2);
				float delta = b^2 - 4.0 * a * c;
				//Si un point d'intersection existe, on le calcule
				if (delta > 0) {
					float k = (-b + sqrt(delta))/(2*a);
					//calcul des coordonnées des points de la sphère
					float psx = px * k;
					float psy = py * k;
					float psz = pz * k;
					//calcul du vecteur lumière vers point sphère
					float vx = psx - this->m_lumiere.getx();
					float vy = psy - this->m_lumiere.gety();
					float vz = psz - this->m_lumiere.getz();
					
					//On a maintenant deux vecteurs : le rayon partant de la caméra, et celui allant vers la lumière
					//On peut alors calculer l'angle entre eux, et ainsi définir un "taux" de lumière réfléchie
					//	calcul du produit scalaire entre les deux vecteurs et des tailles de ces vecteurs
					float scal = px * vx + py * vy + pz * vz;
					float taille_p = sqrt(px^2 + py^2 + pz^2);
					float taille_v = sqrt(vx^2 + vy^2 + vz^2);
					float angle = acos(scal/(taille_p*taille_v);
					float rapport = angle / (M_PI/2);
					//variables pour les couleurs
					int rouge, vert, bleu;
					if (rapport<1) {
						rapinv = 1-rapport;
						Couleur coul = sp.getCouleur();
						//on calcule la couleur du pixel
						float frouge = 2 * coul.getRouge() * rapinv;
						float fvert = 2 * coul.getVert() * rapinv;
						float fbleu = 2 * coul.getBleu() * rapinv;
						
						//on vérifie que ces variables ne dépassent pas 255
						if (frouge>255) frouge=255.0;
						if (fvert>255) fvert=255.0;
						if (fbleu>255) fbleu=255.0;
						
						//on ajoute 0,5 pour faire l'arrondi, car floor() arrondi à la valeur inférieur
						rouge = floor(frouge + 0.5);
						vert = floor(fvert + 0.5);
						bleu = floor(fbleu + 0.5);
						//on converti en unsigned char
						unsigned char ucr = static_cast<unsigned char>(rouge);
						unsigned char ucv = static_cast<unsigned char>(vert);
						unsigned char ucb = static_cast<unsigned char>(bleu);
						
						wxRect pixel = wxRect(x,y,1,1);
						image.setRGB(&pixel,ucr,ucv,ucb);
					} //pas de sinon, l'image est initialisée en noir
				} 
			}
			// on passe à la colonne suivante
			py = py + p;
		}//fin itération sur y
		//on passe à la ligne suivante
		px = px + p;
	}//fin itération sur x
	
	//On retourne l'image obtenue
	return image;

}

bool Scene::compare(Objet obja, Objet objb) {
	float za = obja.getz();
	float zb = objb.getz();
	return za>zb;
}

Scene::actualiser(int resx, int resy) {
	//calcul des attributs de la caméra
	float tx = m_camera.getTaillex()
	m_camera.setTailley(tx*(((float)resy)/((float)resx)));
	m_camera.setPas(tx/(float)resx));
	//calcul des zbuffers
	this->zbuffer_s = this-> m_molecule;
	this->zbuffer_c = this-> m_molecule;
	
	sort(zbuffer_s.begin(), zbuffer_s.end(), compare);
	sort(zbuffer_c.begin(), zbuffer_c.end(), compare);	
}

//Retourne le rapport entre la résolution suivant x et la résolution suivant y de l'image associée à la scène
float Scene::getRapport() {
}

int Scene::getResx() {
}
