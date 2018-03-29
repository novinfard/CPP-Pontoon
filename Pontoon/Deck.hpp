//
//  Deck.hpp
//  Pontoon
//
//  Created by Soheil on 27/03/2018.
//  Copyright © 2018 Soheil Novinfard. All rights reserved.
//

#ifndef Deck_hpp
#define Deck_hpp

#include <stdio.h>
#include <vector>
#include "Card.hpp"

class Deck
{
public:
	Deck();

	void setupDeck();
	void shuffle();
	int getSize() const;
	bool isEmpty() const;
	Card getTopCard();
	void useTopCard();

	// for debugging purpose
	void printCurrentCards();
	void printUsedCards();
private:
	std::vector<Card*> availableCards;
	std::vector<Card*> usedCards;
};
#endif /* Deck_hpp */
