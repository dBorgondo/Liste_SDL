#ifndef VUES_H_INCLUDED
#define VUES_H_INCLUDED
extern int initAll();
extern int drawImage(SDL_Renderer* renderer,SDL_Texture* img, int x, int y,int largeur, int hauteur);
extern void drawObjects(SDL_Renderer* renderer,liActeur *liste);
extern int createWindow(SDL_Window** window,SDL_Renderer** renderer,int Width,int Height,char* Title);


#endif // VUES_H_INCLUDED
