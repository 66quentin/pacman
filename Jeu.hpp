#include <iostream>
#include "Ouverture.hpp"

#ifndef __JEU__HPP__
#define __JEU__HPP__


class Jeu {
public:
	int bonus_restant;
	void compte_a_rebours();
	void debut();
	void fin();
	void bonus();
	int collision(SDL_Rect,SDL_Rect,SDL_Rect);
	Jeu(int);
	Jeu();
	~Jeu();
};
#endif
