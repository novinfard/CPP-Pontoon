//
//  Player.cpp
//  Pontoon
//
//  Created by Soheil on 28/03/2018.
//  Copyright © 2018 Soheil Novinfard. All rights reserved.
//

#include "Player.hpp"
#include <iostream>
using namespace std;

Player::Player() {
	
}

void Player::viewCards() {
	cout << "your hand is :" << endl;
	Actor::viewCards();
}
