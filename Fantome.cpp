#include "Fantome.hpp"

Fantome::Fantome(char couleur):Personnage(x,y){
	valeur_vulnerable=0;
	if(couleur=='b')
		fichier="sprite/fantome_bleu.png";
	else if(couleur=='r')
		fichier="sprite/fantome_rouge.png";
}

Fantome::~Fantome(){}

//Déplacement arbitraire des fantomes
void Fantome::deplacement(SDL_Rect *a){
	if(a->y<224)
		a->y++;
	else
		a->y=194;
}
	

