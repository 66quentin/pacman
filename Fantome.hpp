#include <iostream>
#include "Personnage.hpp"
#include "Ouverture.hpp"

#ifndef __FANTOME__HPP__
#define __FANTOME__HPP__

class Fantome: public Personnage{
public:
	int valeur_vulnerable;
	const char* fichier;
	Fantome(char);
	void deplacement(SDL_Rect*);
	void tuer();
	void chrono_vulnerable();
	~Fantome();
};

#endif

