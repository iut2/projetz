#ifndef _COULEUR_H
#define _COULEUR_H


class Texture;
class Image;

//Couleur de type RVB
class Couleur {
  private:
    //Valeur RVB pour le rouge : la couleur est contenue dans un entier compris entre 0 et 255
    int rouge;

    //Valeur RVB pour le vert : la couleur est contenue dans un entier compris entre 0 et 255
    int vert;

    //Valeur RVB pour le bleu : la couleur est contenue dans un entier compris entre 0 et 255
    int bleu;

  public:
    int getRouge();
    int getVert();
    int getBleu();
    Couleur(int r=0, int v=0, int b=0);

	void setcouleur(int r, int v, int b);




};
#endif
