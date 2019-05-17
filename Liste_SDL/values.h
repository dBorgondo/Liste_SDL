#ifndef VALUES_H_INCLUDED
#define VALUES_H_INCLUDED
#define FLARGEUR 1200
#define FHAUTEUR 800
typedef struct tVecteur2d{
    int nX;
    int nY;
}tVecteur2d;

typedef struct tActeur{
    SDL_Texture * textActeur;
    tVecteur2d   vect;
    int hauteur;
    int largeur;
}tActeur;


typedef struct Element{
    tActeur* acteur;
    struct Element* suivant;
}Element;

typedef struct liActeur{
    Element* premier;
    Element* dernier;
    int taille;
}liActeur;


#endif // VALUES_H_INCLUDED
