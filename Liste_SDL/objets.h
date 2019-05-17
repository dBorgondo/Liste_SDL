#ifndef OBJETS_H_INCLUDED
#define OBJETS_H_INCLUDED
extern void initList(liActeur** liste);
extern void ajouterElement(liActeur* liste,tActeur* Acteur);
extern void supprElement(liActeur* liste);
extern void afficherListe(liActeur* liste);
extern tActeur creeActeur(SDL_Renderer* renderer,char* chemin,int x, int y,int largeur,int hauteur);


#endif // OBJETS_H_INCLUDED
