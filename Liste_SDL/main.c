#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include "values.h"
#include "vues.h"
#include "objets.h"
int main( int argc, char* args[] )
{
    SDL_Renderer* renderer = NULL;
    SDL_Window* window = NULL;
    SDL_Event event;
    const Uint8 *keys = SDL_GetKeyboardState(NULL);
    liActeur* Acteurs=NULL;
    initList(&Acteurs);
    initAll();
    if(!(createWindow(&window,&renderer,FLARGEUR,FHAUTEUR,"Demo Liste"))){
        return 0;
    }
    tActeur Fond=creeActeur(renderer,"assets/fond.jpg",0,0,1200,800);
    ajouterElement(Acteurs,&Fond);
    tActeur Trainee=creeActeur(renderer,"assets/trainee.png",0,100,547,433);
    ajouterElement(Acteurs,&Trainee);
    tActeur Licorne=creeActeur(renderer,"assets/licorne.png",200,100,547,433);
    ajouterElement(Acteurs,&Licorne);
    tActeur Shrek=creeActeur(renderer,"assets/shrek.png",800,420,400,400);
    ajouterElement(Acteurs,&Shrek);
    tActeur Doge=creeActeur(renderer,"assets/doge.png",1000,50,150,150);
    ajouterElement(Acteurs,&Doge);
    drawObjects(renderer,Acteurs);
    SDL_RenderPresent(renderer);
    while(!(keys[SDL_SCANCODE_ESCAPE]))
    {
        SDL_WaitEvent(&event);
    }
    return 0;
}



