//
//  main.cpp
//  Pontoon
//
//  Created by Soheil on 27/03/2018.
//  Copyright © 2018 Soheil Novinfard. All rights reserved.
//

#include <iostream>
#include "Game.hpp"
using namespace std;

int main() {
	
	Game *game = new Game();
	
	string line;
	while ( getline(std::cin, line) )
	{
		if (line.empty()) // an empty line might be read
			continue;
		
		game->performCommand(line.at(0));
	}

	return 0;
}
