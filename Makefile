CFLAGS=-Wall -g -std=gnu++0x

pacman: Main.o Ouverture.o Jeu.o Personnage.o Fantome.o Pacman.o
	g++ -o pacman Main.o Ouverture.o Jeu.o Personnage.o Fantome.o Pacman.o `sdl2-config --cflags --libs` -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf -std=gnu++0x

%.o: %.cpp
	g++ -o $@ $< $(CFLAGS) -c

.PHONY: clean
clean:
	rm -f *.o pacman
