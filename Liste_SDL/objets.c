#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include "values.h"
void initList(liActeur** liste){
    if(!((*liste)=malloc(sizeof(liActeur)))){
        EXIT_FAILURE;
    }
    (*liste)->premier=NULL;
    (*liste)->taille=0;
}

void ajouterElement(liActeur* liste,tActeur* Acteur){
    Element* element = malloc(sizeof(Element));
    if(liste->premier!=NULL){
        liste->dernier->suivant=element;
        liste->dernier=element;
    }
    else{
        liste->premier=element;
        liste->dernier=element;
    }
    element->acteur=Acteur;
    element->suivant=NULL;
    liste->taille++;
}

void supprElement(liActeur* liste){
    if(liste->taille>0){
    Element* Holder=liste->premier;
    liste->premier=liste->premier->suivant;
    free(Holder);
    (liste->taille)--;
    }
}

void afficherListe(liActeur* liste){
    int compteur=0;
    Element* Actuel=liste->premier;
    for(compteur=0;compteur<liste->taille;compteur++){
        printf("%d->",Actuel->acteur->hauteur);
        Actuel=Actuel->suivant;
    }
    printf("NULL\n");
}

tActeur creeActeur(SDL_Renderer* renderer,char* chemin,int x, int y,int largeur,int hauteur){
    tActeur Acteur;
    Acteur.vect.nX=x;
    Acteur.vect.nY=y;
    Acteur.hauteur=hauteur;
    Acteur.largeur=largeur;
    if(!(Acteur.textActeur = IMG_LoadTexture(renderer,chemin))){
        printf("Erreur de chargement de l'image: %s \n", SDL_GetError());
    }
    return Acteur;
}
