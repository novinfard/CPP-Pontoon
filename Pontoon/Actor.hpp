//
//  Actor.hpp
//  Pontoon
//
//  Created by Soheil on 28/03/2018.
//  Copyright © 2018 Soheil Novinfard. All rights reserved.
//

#ifndef Actor_hpp
#define Actor_hpp

#include <stdio.h>
#include <vector>
#include "Card.hpp"

class Actor
{
public:
	Actor();
	void addCard(Card);
	virtual void viewCards();
	int getSum();
	int numberOfCards();
	void resetHand();
	
private:
	std::vector<Card> hand;
};

#endif /* Actor_hpp */
