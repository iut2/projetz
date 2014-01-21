#include "Scene.h"
#include "Molecule.h"
#include "Camera.h"
#include "Image.h"
#include "Point.h"
#include "Sphere.h"
#include "Cylindre.h"
#include "Lumiere.h"
#include "wx/image.h"
#include <math.h>
#include <algorithm>
#include <vector>
#include <wx/gdicmn.h>

using namespace std;

//Constructeur de la classe Scene
//Scene::Scene() {
	//TODO HUGO
//}

//Méthode appelée par l'application utilisant le moteur ; retourne une image bitmap utilisable par wxWidget
wxImage Scene::rendu(int resx, int resy) {
	//On actualise les éléments relatifs à notre scène
	this->actualiser(resx,resy);

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
	Point pix = (*m_camera).getCoin();
	float p = (*m_camera).getPas();
	//Initialisation des coordonnées du pixel courant
	float px = (float)pix.getx();
	float py = (float)pix.gety();
	float pz = (float)pix.getz();

	//Objets pour les itérations
	Cylindre cy;
	Sphere sp;
	unsigned int taille_c = this->zbuffer_c.size(); //récupération du nombre de cylindres
	unsigned int taille_s = this->zbuffer_s.size(); //récupération du nombre de sphères



	for (int x=0 ; x<resx ; x++) {
		for (int y=0 ; y<resy ; y++) {
			//TODO calcul d'un point d'intersection rayon/cylindre : itération sur zbuffer_c
			//JEAN-DENIS (inspire toi de mon code)

			for (unsigned int i=0 ; i<taille_c ; i++) {
			    //on récupère le cylindre de rayon R et d'axe(O,vect(N))
			    //le plus proche suivant z
				cy = zbuffer_c[i];

                Point m = cy.getsphere1().getCentre(); //On résupère le centre de la sphère à l'extrimité 1
				float mx = m.getx();
				float my = m.gety();
				float mz = m.getz();

				Point n = cy.getsphere2().getCentre(); //On résupère le centre de la sphère à l'extrimité 2
				float nx = n.getx();
				float ny = n.gety();
				float nz = n.getz();

                // vect(N) = (d,e,f);
				float d = nx-mx;
				float e = ny-my;
				float f = nz-mz;

                //On calcul le déterminant delta = b²-4ac
				float a = px*px + py*py + pz*pz - (((d*px + e*py + f*pz)*(d*px + e*py + f*pz))/(d*d+e*e+f*f));
                float b = -2 * (px * mx + py * my + pz * mz);
				float c = ( mx*mx + my*my + mz*mz - cy.getRayon()*cy.getRayon());
				float delta = b*b - 4.0 * a * c;

				if (delta > 0) {
					float k = (-b + sqrt(delta))/(2*a);
					//calcul des coordonnées des points du cylindre
					float psx = px * k;
					float psy = py * k;
					float psz = pz * k;
                    //calcul distance du point d'intersection avec les centres des sphères
                    float ds1 = sqrt((psx-mx)*(psx-mx)+(psy-my)*(psy-my)+(psz-mz)*(psz-mz));
                    float ds2 = sqrt((psx- nx)*(psx- nx)+(psy- ny)*(psy- ny)+(psz- nz)*(psz- nz));

                    if(cy.getsphere1().getRayon()<ds1 && cy.getsphere2().getRayon()<ds2) {
                        //float lx = *(this->m_lumiere).getx();
                        //calcul du vecteur lumière vers du cylindre
                        float vx;

                        vx = psx - this->m_lumiere->getx();
                        float vy;
                        vy = psy - this->m_lumiere->gety();
                        float vz;
                        vz = psz - this->m_lumiere->getz();

                        //On a maintenant deux vecteurs : le rayon partant de la caméra, et celui allant vers la lumière
                        //On peut alors calculer l'angle entre eux, et ainsi définir un "taux" de lumière réfléchie
                        //	calcul du produit scalaire entre les deux vecteurs et des tailles de ces vecteurs
                        float scal = px * vx + py * vy + pz * vz;
                        float taille_p = sqrt(px*px + py*py + pz*pz);
                        float taille_v = sqrt(vx*vx + vy*vy + vz*vz);
                        float angle = acos(scal/(taille_p*taille_v));
                        float rapport = angle / (M_PI/2);
                        float rapinv;
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


                            //wxRect pixel = wxRect(x,y,1,1);
                            int x, y;
                            image.setRGB(x, y, ucr, ucv, ucb);
                        } //pas de sinon, l'image est initialisée en noir
                    }//pas de sinon car caché
				}
			}


			//Détermination d'un potentiel point d'intersection avec une sphère
			//Itération sur zbuffer_s
			for (unsigned int i=0 ; i<taille_s ; i++) {
				//on récupère la sphère la plus proche suivant z
				sp = zbuffer_s[i];
				//On calcul le déterminant delta = b²-4ac
				float a = px*px + py*py + pz*pz;
				Point m = sp.getCentre(); //On résupère le centre de la sphère
				float mx = m.getx();
				float my = m.gety();
				float mz = m.getz();
				float r = sp.getRayon();
				float b = -2 * (px * mx + py * my + pz * mz);
				float c = ( mx*mx + my*my + mz*mz - r*r);
				float delta = b*b - 4.0 * a * c;
				//Si un point d'intersection existe, on le calcule
				if (delta > 0) {
					float k = (-b + sqrt(delta))/(2*a);
					//calcul des coordonnées des points de la sphère
					float psx = px * k;
					float psy = py * k;
					float psz = pz * k;
					//calcul du vecteur lumière vers point sphère
					float vx = psx - (*this->m_lumiere).getx();
					float vy = psy - (*this->m_lumiere).gety();
					float vz = psz - (*this->m_lumiere).getz();

					//On a maintenant deux vecteurs : le rayon partant de la caméra, et celui allant vers la lumière
					//On peut alors calculer l'angle entre eux, et ainsi définir un "taux" de lumière réfléchie
					//	calcul du produit scalaire entre les deux vecteurs et des tailles de ces vecteurs
					float scal = px * vx + py * vy + pz * vz;
					float taille_p = sqrt(px*px + py*py + pz*pz);
					float taille_v = sqrt(vx*vx + vy*vy + vz*vz);
					float angle = acos(scal/(taille_p*taille_v));
					float rapport = angle / (M_PI/2);
					//variables pour les couleurs
					int rouge, vert, bleu;
					if (rapport<1) {
						float rapinv = 1-rapport;
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
						/*unsigned char ucr = static_cast<unsigned char>(rouge);
						unsigned char ucv = static_cast<unsigned char>(vert);
						unsigned char ucb = static_cast<unsigned char>(bleu);*/
						int x1, y1;
						unsigned char red, green, blue;

						//wxRect pixel = wxRect(x,y,1,1);
						//image.setRGB(&pixel,ucr,ucv,ucb);
						image.setRGB(x1, y1, red, green, blue);
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

//Méthode de rendu simplifiée
wxImage Scene::renduSimple(int resx, int resy) {
	//actualisation simplifiée
	float tx = (*m_camera).getTaillex();
	(*m_camera).setTailley(tx*(((float)resy)/((float)resx)));
	(*m_camera).setPas(tx/(float)resx);

	//récupération des points à projeter
	vector<Sphere> ensSpheres = this->m_molecule.getSpheres();

	nbatomes = ensSpheres.size();

	for (unsigned int i = 0; i<nbatomes; i++) {
        //faire projection+visualisation+calcul rayon+tracage sphere
	}

}


bool Scene::compare(Objet obja, Objet objb) {
	float za = obja.getz();
	float zb = objb.getz();
	return za>zb;
}

void Scene::actualiser(int resx, int resy) {
	//calcul des attributs de la caméra
	float tx = (*m_camera).getTaillex();
	(*m_camera).setTailley(tx*(((float)resy)/((float)resx)));
	(*m_camera).setPas(tx/(float)resx);
	//calcul des zbuffers
	for (int i; zbuffer_s.size(); i++){
        this.zbuffer_s[i] = this.m_molecule.getSpheres[i];
	}
	for (int j; zbuffer_c.size(); j++){
        this.zbuffer_c[j] = this.m_molecule.getCylindres[j];///////////////////////////////////////////////////////chelou
	}

/* ENLEVÉ, la caméra ne bouge plus
    Point pt;
	for(unsigned int i=0; i<zbuffer_s.size(); i++) {
	    //récupération du point d'origine
        pt = zbuffer_s[i].getCentre();
        //récupération du nouveau repère
        ptprime =
        zbuffer_s[i].setCentre();
	}
*/
	sort (zbuffer_s.begin(), zbuffer_s.end(), compare);
	sort (zbuffer_c.begin(), zbuffer_c.end(), compare);
}

//Retourne le rapport entre la résolution suivant x et la résolution suivant y de l'image associée à la scène
//float Scene::getRapport() {
//}

//Changement de repère
//rx, ry, rz : angles suivant axes respectifs
//tx, ty, tz : translation suivant axes respectifs
//p : point à déplacer
Point Scene::changementRepere(Point p, float rx,float ry, float rz, float tx, float ty, float tz) {


float x,y,z,x2,y2,z2;

x = p.getx();
y = p.gety();
z = p.getz();
Point p2;



x2 = (tx + x) * (cos(ry) * cos(rz)) + (ty + y) * ( -sin(rz) * cos(rx) + sin(rx) * sin(ry) * cos(rz)) + (tz + z) * (sin(rz) * sin(rx) + cos(rx) * cos(rz) * sin(ry));

y2 = (tx + x) * (cos(ry) * sin(rz)) + (ty + y) * ( cos(rx) * cos(rz) + sin(rx) * sin(ry) * sin(rz)) + (tz + z) * (cos(rz) * -sin(rx) + cos(rx) * sin(ry) * sin(rz));

z2 = (tx + x) * (-sin(ry)) + (ty + y) * (cos(ry) * sin(rx)) + (tx + x) * (cos(rx) * cos(ry));

p2 = new Point(x2,y2,z2);

return p2;

}

Molecule Scene::chgtRepBary(Molecule m){

    Point bary;
    int i;
    float bx,by,bz,sx,sy,sz,nx,ny,nz;

    Sphere s;
    Point p;

    bary = m.getCentre();

    bx = bary.getx();
    by = bary.gety();
    bz = bary.getz();

    for(i=1;i<=m.ensSpheres.size();i++) {

        s = m.ensSpheres[i];
        p = s.getCentre();

        sx = p.getx();
        sy = p.gety();
        sz = p.getz();

        nx = sx + bx;
        ny = sy + by;
        nz = sz + bz;

        p.setx(nx);
        p.sety(ny);
        p.setz(nz);

        s.setCentre(p);


    }

    return m;


}

Molecule rotationMolecule(Molecule m, float angleX, float angleY, float angleZ) {

    int i;
    float sx,sy,sz,nx,ny,nz;
    Sphere s;
    Point p;

    for(i=1;i<=m.ensSpheres.size();i++) {

        s = m.ensSpheres[i];
        p = s.getCentre();

        sx = p.getx();
        sy = p.gety();
        sz = p.getz();

        nx = sx * cos(angleY) * cos(angleZ) + sy * (cos(angleX) * -sin(angleZ) + sin(angleX) * cos(angleZ) * sin(angleY)) + sz * ( sin(angleZ) * sin(angleX) + cos(angleX) * cos(angleZ) * sin(angleY));

        ny = sx * cos(angleY) * sin(angleZ) + sy * (cos(angleX) * cos(angleZ) + sin(angleX) * sin(angleZ) * sin(angleY)) + sz * ( cos(angleZ) * -sin(angleX) + cos(angleX) * sin(angleZ) * sin(angleY));

        nz = sx * -sin(angleY) + sy * cos(angleY) * cos sin(angleX) + sz * cos(angleX) * cos(angleY);

        p.setx(nx);
        p.sety(ny);
        p.setz(nz);

        s.setCentre(p);
}

 return m;

}

Molecule Scene::retourRepAvBary(Molecule m){

    Point bary;
    int i;
    float bx,by,bz,sx,sy,sz,nx,ny,nz;

    Sphere s;
    Point p;

    bary = m.getCentre();

    bx = bary.getx();
    by = bary.gety();
    bz = bary.getz();

    for(i=1;i<=m.ensSpheres.size();i++) {

        s = m.ensSpheres[i];
        p = s.getCentre();

        sx = p.getx();
        sy = p.gety();
        sz = p.getz();

        nx = sx - bx;
        ny = sy - by;
        nz = sz - bz;

        p.setx(nx);
        p.sety(ny);
        p.setz(nz);

        s.setCentre(p);


    }

    return m;


}
