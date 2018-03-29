//
//  Card.hpp
//  Pontoon
//
//  Created by Soheil on 27/03/2018.
//  Copyright © 2018 Soheil Novinfard. All rights reserved.
//

#ifndef Card_hpp
#define Card_hpp

#include <stdio.h>
#include <string>
#include <map>

enum Face
{
	ACE = 1,
	TWO = 2,
	THREE = 3,
	FOUR = 4,
	FIVE = 5,
	SIX = 6,
	SEVEN = 7,
	EIGHT = 8,
	NINE = 9,
	TEN = 10,
	JACK = 11,
	QUEEN = 12,
	KING = 13
};
enum Suit
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
};

class Card {
public:
	Card(Suit, Face);
	
	std::string getName() const;
	int getValue() const;

private:
	Face currentFace;
	Suit currentSuit;
	int currentValue;
	std::map<Face,std::string> faceMap;
	std::map<Suit,std::string> suitMap;
	bool used;
};


#endif /* Card_hpp */
