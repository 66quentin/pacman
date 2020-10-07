#include "Ouverture.hpp"

SDL_Texture* loadTexture(SDL_Renderer *rendu, const char* filePath) {
	SDL_Surface* surface(SDL_LoadBMP(filePath));
	if (surface) {
		SDL_Texture* texture(SDL_CreateTextureFromSurface(rendu, surface));
		if (texture) {
			printf("Fichier texture bien ouvert %s\n", filePath);
			return texture;
		}
		printf("Echec lors de l'ouverture du fichir texture: %s\n", filePath);
		return nullptr;
	}
	printf("Fichier introuvable: %s\n", filePath);
	return nullptr;
}
