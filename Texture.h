#ifndef _TEXTURE_H
#define _TEXTURE_H


class Sphere;
class Cylindre;
class Couleur;

//Classe contenant la description d'une texture
class Texture {
  private:
    Couleur * m_couleur;
    
public :
    
    Texture(int r, int v, int b);
    
    Couleur getCouleur();

};
#endif
