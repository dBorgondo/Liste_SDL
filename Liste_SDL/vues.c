#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include "values.h"
#include "objets.h"
//Entree :
//Sortie :
//Commentaire : Initilaise toute la sdl
int initAll(){
        if (SDL_Init(SDL_INIT_EVERYTHING)!= 0) {
            printf("Erreur d'initialisation de la SDL: %s\n", SDL_GetError());
            return 0;
        }
        printf("Toutes les initialisations ont ete effectue avec succes.\n");
        return 1;
}
//Entree : fenetre à créé, renderer de la fenetre, largeur de la fenetre, hauteur de la fenetre, titre de la fenetre
//Sortie : Fenetre créé et 1 si créé avec succés, 0 sinon
//Commentaire : Créé une fenetre SDL
int createWindow(SDL_Window** window,SDL_Renderer** renderer,int Width,int Height,char* Title){
    if(!(window = SDL_CreateWindow(Title,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,Width,Height,SDL_WINDOW_SHOWN))){
        printf("Erreur de creation de la fenetre : %s \n", SDL_GetError());
        return 0;
    }
    if(!(*renderer = SDL_CreateRenderer(window,-1,0))){
        printf("Erreur de creation du creation : %s \n", SDL_GetError());
        return 0;
    }
    return 1;
}
//Entree :renderer,Image à dessiner,coordonnée en x et en y
//Sortie : Image dessiné
//Commentaire : Dessine une image à l'ecran
int drawImage(SDL_Renderer* renderer,SDL_Texture* img, int x, int y,int largeur, int hauteur){
    SDL_Rect canva;
    canva.x = x;
    canva.y = y;
    canva.w = largeur;
    canva.h = hauteur;
    SDL_RenderCopy(renderer, img, NULL, &canva);
    return 1;
}
//Entree : renderer, liste d'objet
//Sortie : Objets dessinée
//Commentaire : Dessines tout les objets de la liste chainée d'objets
void drawObjects(SDL_Renderer* renderer,liActeur *liste){
    Element* Actuel=liste->premier;
    int compteur=0;
    for(compteur=0;compteur<liste->taille;compteur++){
        drawImage(renderer,Actuel->acteur->textActeur, Actuel->acteur->vect.nX,Actuel->acteur->vect.nY,Actuel->acteur->largeur,Actuel->acteur->hauteur);
        Actuel=Actuel->suivant;
    }
}
