//
//  Bank.cpp
//  Pontoon
//
//  Created by Soheil on 28/03/2018.
//  Copyright © 2018 Soheil Novinfard. All rights reserved.
//

#include "Bank.hpp"
#include <iostream>
using namespace std;

Bank::Bank() {

}

void Bank::viewCards() {
	cout << "the banks hand is :" << endl;
	Actor::viewCards();
}
