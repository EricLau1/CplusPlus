#include <iostream>
#include "game.h"


int main() {
	Game *g = new Game(20, 20);
	
	g->run();
	
	return 0;
}
