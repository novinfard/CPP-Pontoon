//
//  Card.cpp
//  Pontoon
//
//  Created by Soheil on 27/03/2018.
//  Copyright © 2018 Soheil Novinfard. All rights reserved.
//

#include "Card.hpp"
using namespace std;

template <typename Enumeration>
auto as_integer(Enumeration const value)
-> typename std::underlying_type<Enumeration>::type
{
	return static_cast<typename std::underlying_type<Enumeration>::type>(value);
}

Card::Card(Suit s, Face f): currentSuit(s), currentFace(f){
	// initialise face title map
	faceMap[ACE] = "Ace";
	faceMap[TWO] = "Two";
	faceMap[THREE] = "Three";
	faceMap[FOUR] = "Four";
	faceMap[FIVE] = "Five";
	faceMap[SIX] = "Six";
	faceMap[SEVEN] = "Seven";
	faceMap[EIGHT] = "Eight";
	faceMap[NINE] = "Nine";
	faceMap[TEN] = "Ten";
	faceMap[JACK] = "Jack";
	faceMap[QUEEN] = "Queen";
	faceMap[KING] = "King";

	// initialise suit title map
	suitMap[SPADE] = "Spades";
	suitMap[HEART] = "Hearts";
	suitMap[CLUB] = "Clubs";
	suitMap[DIAMOND] = "Diamonds";
	
	int faceValue = as_integer(currentFace);
	currentValue = (faceValue > 10) ? 10 : faceValue;
	
	used = false;
}

string Card::getName() const{
	return faceMap.at(currentFace) + " of " + suitMap.at(currentSuit);
}

int Card::getValue() const{
	return currentValue;
}

