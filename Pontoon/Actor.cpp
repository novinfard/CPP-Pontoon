//
//  Actor.cpp
//  Pontoon
//
//  Created by Soheil on 28/03/2018.
//  Copyright © 2018 Soheil Novinfard. All rights reserved.
//

#include "Actor.hpp"
#include <iostream>
using namespace std;

Actor::Actor() {
	
}

void Actor::addCard(Card newCard) {
	hand.push_back(newCard);
}

void Actor::viewCards() {
	int valueSum = 0;
	for (size_t x = 0; x < hand.size(); ++x) {
		valueSum += hand[x].getValue();
		cout << hand[x].getName() << endl;
	}
	if(valueSum > 21)
		cout << "BUST!!!" << endl << endl;
	else
		cout << "value = " << to_string(valueSum) << endl << endl;
}

void Actor::resetHand() {
	hand.clear();
}

int Actor::getSum() {
	int valueSum = 0;
	for (size_t x = 0; x < hand.size(); ++x) {
		valueSum += hand[x].getValue();
	}
	return valueSum;
}

int Actor::numberOfCards() {
	return (int) hand.size();
}
