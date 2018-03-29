//
//  Game.hpp
//  Pontoon
//
//  Created by Soheil on 28/03/2018.
//  Copyright © 2018 Soheil Novinfard. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include "Deck.hpp"
#include "Bank.hpp"
#include "Player.hpp"
#include "Log.hpp"

class Game
{
public:
	Game();
	
	void performCommand(char);
	
private:
	void start();
	void quit();
	void stick();
	void twist();
	void finishRound();
	void showCards(Actor*);
	void giveCard(Actor*);
	
	Deck deck;
	Log log;
	Player player;
	Bank bank;
	bool isFinished;
	bool readyForNextCommand;
};

#endif /* Game_hpp */
