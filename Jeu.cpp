#include "Jeu.hpp"
#include "Pacman.hpp"

Jeu::Jeu(){
	bonus_restant=6;
}

Jeu::Jeu(int x){
	bonus_restant=x;
}

Jeu::~Jeu(){}

void Jeu::compte_a_rebours(){
	//Afficher compte à rebours en SDL
}

void Jeu::debut(){
	compte_a_rebours();
}

//Detecttion de la collision. Dans l'ideal chaque classe fille (fantomes, pacman) devrait assigner x et y leurs positions à leur classe mère et on devrait comparer ces valeurs là.
int Jeu::collision(SDL_Rect a, SDL_Rect b, SDL_Rect c){
	if(a.x+16>=b.x && a.x <= b.x+32 && a.y+16 >= b.y && a.y <= b.y+32)
		return 1;
	else if(a.x+16>=c.x && a.x <= c.x+32 && a.y+16 >= c.y && a.y <= c.y+32)
		return 1;
	return 0;
}




