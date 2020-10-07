#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include <cstdio>
#include <fstream>
#include <iostream>

#define TAILLE 32
#define LARGEUR 704
#define HAUTEUR 576

SDL_Texture* loadTexture(SDL_Renderer *rendu, const char* filePath);
void ouverture();
