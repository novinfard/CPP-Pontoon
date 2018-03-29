//
//  Bank.hpp
//  Pontoon
//
//  Created by Soheil on 28/03/2018.
//  Copyright © 2018 Soheil Novinfard. All rights reserved.
//

#ifndef Bank_hpp
#define Bank_hpp

#include <stdio.h>
#include "Actor.hpp"

class Bank: public Actor
{
public:
	Bank();
	void viewCards();
};

#endif /* Bank_hpp */
