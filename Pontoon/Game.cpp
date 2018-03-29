//
//  Game.cpp
//  Pontoon
//
//  Created by Soheil on 28/03/2018.
//  Copyright © 2018 Soheil Novinfard. All rights reserved.
//

#include <iostream>
#include "Game.hpp"
using namespace std;

Game::Game(): readyForNextCommand(false), isFinished(false) {
	start();
}

void Game::performCommand(char ch) {
	readyForNextCommand = false;
	if(isFinished) {
		switch (ch) {
			case 'y':
				start();
				break;
			case 'n':
				quit();
				break;
			default:
				cout << "do you want to play again ([y]es/[n]o)?" << endl;
				break;
		}
	} else {
		switch (ch) {
			case 's':
				stick();
				break;
			case 't':
				twist();
				break;
			default:
				cout << "[s]tick or [t]wist?" << endl;
				break;
		}
	}
	readyForNextCommand = true;
}

void Game::start() {
	// fill the deck with cards
	deck.setupDeck();
	
	// shuffle the deck
	deck.shuffle();
	
	// initiate log
	log.startLogging();
	
	// reset hands
	bank.resetHand();
	player.resetHand();
	
	// deals two cards for bank
	giveCard(&bank);
	giveCard(&bank);

	// deals two cards for player
	giveCard(&player);
	giveCard(&player);
	
	isFinished = false;
	
	// view player cards
	showCards(&player);
	
	cout << "[s]tick or [t]wist?" << endl;
	
	readyForNextCommand = true;
}

void Game::quit() {
	// finalise logging and creat report
	log.finishLogging();
	
	cout << endl << "Thanks, bye!" << endl;
	
	// kill the program
	exit(0);
}

void Game::twist() {
	giveCard(&player);
	
	int playerValue = player.getSum();
	
	// view player cards
	showCards(&player);
	
	if(playerValue < 21 && player.numberOfCards() < 5) {
		cout << "[s]tick or [t]wist?" << endl;
	} else {
		finishRound();
	}
	
}

void Game::stick() {
	int playerValue = player.getSum();
	int bankValue = bank.getSum();
	
	// view bank cards
	showCards(&bank);
	
	while(bankValue < 21 && (bankValue < playerValue) && bank.numberOfCards() < 5) {
		cout << endl << "the bank draws a card ..." << endl;
		
		giveCard(&bank);
		
		// view bank cards
		showCards(&bank);
		
		bankValue = bank.getSum();
	}
	
	finishRound();
}

void Game::finishRound() {
	int playerValue = player.getSum();
	int bankValue = bank.getSum();
	
	// check the winner
	string drawingWinner = "";
	if (playerValue == bankValue && player.numberOfCards() == bank.numberOfCards() && bankValue <= 21 && playerValue <= 21) {
		cout << "Both of you and the bank are in the same status. Now its time to draw ..." << endl;
		// draw between player and bank
		int randNum = rand()%(10 + 1);
		if(randNum > 5)
			drawingWinner = "bank";
		else
			drawingWinner = "player";
	}
	
	if( (bankValue > 21)
	   || (playerValue <= 21 && playerValue > bankValue)
	   || (playerValue == bankValue && player.numberOfCards() > bank.numberOfCards())
	   || drawingWinner == "player"
	   ) {
		// player is winner
		log.addWon();
		cout << "Well done, you won!!!" << endl << endl;
	} else {
		// bank is winner
		log.addLost();
		cout << "Bad luck, the bank won." << endl << endl;
	}
	
	isFinished = true;
	
	cout << "do you want to play again ([y]es/[n]o)?" << endl;
}

void Game::showCards(Actor *actor) {
	actor->viewCards();
}

void Game::giveCard(Actor *actor) {
	actor->addCard(deck.getTopCard());
	deck.useTopCard();
}
