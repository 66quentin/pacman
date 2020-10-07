#include "Fantome.hpp"
#include "Jeu.hpp"
#include "Pacman.hpp"
#include "Ouverture.hpp"

int main (void) {

	//Initialisation du jeu et des fantomes
	Jeu *J= new Jeu();
	Pacman *p=new Pacman();
	Fantome *f1=new Fantome('r');
	Fantome *f2=new Fantome('b');
	J->debut();
	
	//Ouverture de la carte et de la fenetre
	
	bool quitter = false;

	const int lignes = 18;
	const int colonnes = 22;
	const int taille = 32;

	int carte[lignes][colonnes];
	std::ifstream fs("carte.txt", std::ifstream::in);
	for(int r = 0; r < lignes; r++){
		for(int c = 0; c < colonnes; c++){
			fs >> carte[r][c];
		}
	}
	SDL_Rect DestR={330, 287, TAILLE, TAILLE };
	SDL_Rect DestR2={350, 210, TAILLE, TAILLE };
	SDL_Rect DestR3={290, 210, TAILLE, TAILLE };

	SDL_Event event;	

	SDL_Init( SDL_INIT_EVERYTHING );
	SDL_Window* fenetre = SDL_CreateWindow( "Pacman POO", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, LARGEUR, HAUTEUR, 0 );

	//Declaration des différents éléments
	SDL_Renderer * rendu = SDL_CreateRenderer(fenetre, -1, 0);
	SDL_Texture* cible =SDL_CreateTexture(rendu, SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_STREAMING, 8, 8);
	SDL_SetRenderTarget(rendu, cible);
	SDL_Surface * imagePacman = IMG_Load("sprite/pacman.png");
	SDL_Texture * texture = SDL_CreateTextureFromSurface(rendu,imagePacman);
	SDL_Texture * texture2 = loadTexture(rendu, "sprite/carte.bmp");
	SDL_Surface * Fantome1 = IMG_Load(f1->fichier);
	SDL_Texture * texture3 = SDL_CreateTextureFromSurface(rendu,Fantome1);
	SDL_Surface * Fantome2 = IMG_Load(f2->fichier);
	SDL_Texture * texture4 = SDL_CreateTextureFromSurface(rendu,Fantome2);

   	SDL_RenderClear(rendu);
	SDL_SetRenderTarget(rendu, NULL);

	SDL_RenderPresent(rendu);


	//Jeu en cours ici
	while (!quitter) {
		//Detection des touches
		if (SDL_PollEvent(&event)) {
			switch (event.type) {
				case SDL_KEYDOWN: p->appuyer(&event);
					break ;
				case SDL_KEYUP:	 p->relacher(&event);
					break ;
			}
		}
		
		
		//Mouvement (on vérifie à chaque fois qu'on ne rentre pas dans un mur)
		if (p->touche[SDLK_LEFT] && carte[(DestR.y+16)/32][(DestR.x-p->vitesse)/32]==0) {
			DestR.x -= p->vitesse ;

			SDL_RenderCopyEx(rendu, texture, nullptr, &DestR, 180, nullptr, SDL_FLIP_NONE);
			SDL_RenderPresent(rendu);
		} else if (p->touche[SDLK_RIGHT] && carte[(DestR.y+16)/32][(DestR.x+32)/32]==0) {
			DestR.x += p->vitesse ;
		} else if (p->touche[SDLK_UP] && carte[(DestR.y-p->vitesse)/32][(DestR.x+16)/32]==0) {
			DestR.y -= p->vitesse ;
			SDL_RenderCopyEx(rendu, texture, nullptr, &DestR, 270, nullptr, SDL_FLIP_NONE);
			SDL_RenderPresent(rendu);
		} else if (p->touche[SDLK_DOWN] && carte[(DestR.y+32)/32][(DestR.x+16)/32]==0) {
			SDL_RenderCopyEx(rendu, texture, nullptr, &DestR, 90, nullptr, SDL_FLIP_NONE);
			SDL_RenderPresent(rendu);
			DestR.y += p->vitesse ;
		}
		
		if (DestR.x < 0) {
			DestR.x = 0;
		}
		else if ( DestR.x > LARGEUR-TAILLE ) {
			DestR.x = LARGEUR-TAILLE;
		}
		if ( DestR.y < 0 ) {
			DestR.y = 0;
		}
		else if ( DestR.y > HAUTEUR-TAILLE ) {
			DestR.y = HAUTEUR-TAILLE;
		}
		if(event.type==SDL_QUIT){
			quitter = true;
		
		}

		SDL_RenderClear(rendu);
		SDL_PollEvent(&event);
		
		//On charge la carte
		for (int i = 0; i < lignes; ++i) {
			for (int j = 0; j < colonnes; ++j) {
				const SDL_Rect dstRect = {j * taille, i * taille, taille, taille};
				const SDL_Rect srcRect = {carte[i][j] * taille, 0, taille, taille};
				SDL_RenderCopy(rendu, texture2, &srcRect, &dstRect);
			}
		}
		SDL_RenderCopy(rendu, texture,NULL, &DestR );
		SDL_RenderCopy(rendu, texture3,NULL, &DestR2 );
		SDL_RenderCopy(rendu, texture4, NULL, &DestR3);


		f1->deplacement(&DestR2);
		f2->deplacement(&DestR3);
		SDL_RenderPresent(rendu);
		
		//On vérifie les collisions et tue éventuellement Pacman
		if(J->collision(DestR,DestR2,DestR3)){
			DestR.x=330;
			DestR.y=287;
			p->vies--;
			quitter=p->mort();
			const char *vies[]={"Perdu","Une vie", "Deux vies"};
			const char *vie=vies[p->vies];
			SDL_SetWindowTitle(fenetre,vie); //Affichage provisoire
		}
	}

	//On ferme tout ce qu'on a ouvert
	SDL_DestroyTexture(texture);
	SDL_DestroyTexture(texture2);
	SDL_DestroyTexture(texture3);
	SDL_DestroyTexture(texture4);
	SDL_FreeSurface(imagePacman);
	SDL_FreeSurface(Fantome1);
	SDL_FreeSurface(Fantome2);
	SDL_DestroyRenderer(rendu);
	SDL_DestroyWindow(fenetre);
	IMG_Quit();
	SDL_Quit();


	return 0;
}


