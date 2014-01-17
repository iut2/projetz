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

    //la multiplicité en 1 permet d'éviter la réutilisation d'une couleur, ce qui empêcherais de la modifier pour un type d'objet sans la modifier pour un autre.
    Texture * appartientATexture;

    Image * ;

    Image * ;

};
#endif
