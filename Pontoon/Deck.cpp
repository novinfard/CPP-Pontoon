//
//  Deck.cpp
//  Pontoon
//
//  Created by Soheil on 27/03/2018.
//  Copyright © 2018 Soheil Novinfard. All rights reserved.
//

#include "Deck.hpp"
#include <iostream>
#include <ctime>
using namespace std;

int myrandom (int i) { return rand()%i;}

Deck::Deck()
{
	//Initialisation
	setupDeck();
	shuffle();
}

void Deck::setupDeck(){
	availableCards.clear();
	usedCards.clear();
	for(int i = 1; i <= 13; ++i)
	{
		for(int n = 0; n <= 3; ++n)
		{
			availableCards.push_back(new Card(static_cast<Suit>(n), static_cast<Face>(i) ));
		}
	}
}

void Deck::shuffle(){
	srand((unsigned)time(0));
	std::random_shuffle(availableCards.begin(), availableCards.end(), myrandom);
}

bool Deck::isEmpty() const{
	return (availableCards.size() == 0);
}

int Deck::getSize() const{
	return (int) availableCards.size();
}

Card Deck::getTopCard() {
	return *availableCards[0];
}

void Deck::useTopCard() {
	usedCards.push_back(*availableCards.begin());
	availableCards.erase(availableCards.begin());
}

void Deck::printCurrentCards(){
	for (size_t x = 0; x < availableCards.size(); ++x)
	{
		cout << availableCards[x]->getName() << endl;
		
	}
}

void Deck::printUsedCards(){
	for (size_t x = 0; x < usedCards.size(); ++x)
	{
		cout << usedCards[x]->getName() << endl;
		
	}
}


//Card Deck::giveTopCard()
//{
//	for(int i = 0; i < currentDeck.size(); ++i)
//	{
//		if(!currentDeck[i]->isUsed())
//		{
//			currentDeck[i]->setUsed(true);
//			return (*currentDeck[i]);
//		}
//	}
//}

