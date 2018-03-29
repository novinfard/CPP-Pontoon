//
//  Player.hpp
//  Pontoon
//
//  Created by Soheil on 28/03/2018.
//  Copyright © 2018 Soheil Novinfard. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include "Actor.hpp"

class Player: public Actor
{
public:
	Player();
	void viewCards();
	
};


#endif /* Player_hpp */
