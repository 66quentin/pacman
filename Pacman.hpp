#include <iostream>
#include <SDL2/SDL.h>
#include "Personnage.hpp"
#include <map>

#ifndef __PACMAN__HPP__
#define __PACMAN__HPP__

class Pacman: public Personnage {
	public:
	int score;
	int vies;
	int enCours;
	std::map<int,int> touche;
	int vitesse;
	Pacman();
	void manger();
	int mort();
	void appuyer(SDL_Event*);
	void relacher(SDL_Event*);
	~Pacman();
};
#endif

