#include "Pacman.hpp"

Pacman::Pacman():Personnage(){
	score=0;
	vies=3;
	vitesse=1;
}

Pacman::~Pacman(){}

void Pacman::appuyer(SDL_Event* evt) {
		touche[ evt->key.keysym.sym ] = 1 ;
}

void Pacman::relacher(SDL_Event* evt) {
		touche[ evt->key.keysym.sym ] = 0 ;
}

int Pacman::mort(){
	if(vies==0)
		return 1;
	return 0;
}
		
