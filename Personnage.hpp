#include <iostream>

#ifndef __PERSONNAGE__HPP__
#define __PERSONNAGE__HPP__

class Personnage {
public:
	int x;
	int y;
	void respawn(int,int);
	void bouger(int);
	Personnage(int,int);
	Personnage();
	~Personnage();
};

#endif
