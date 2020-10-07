#include "Personnage.hpp"

//On initialise la position des éléments
Personnage::Personnage(){
	x=20;
	y=20;
}


Personnage::Personnage(int _x, int _y){
	x=_x;
	y=_y;
}

Personnage::~Personnage(){ }

void Personnage::respawn(int _x,int _y){
	x=_x;
	y=_y;
}
