//
//  Log.hpp
//  Pontoon
//
//  Created by Soheil on 28/03/2018.
//  Copyright © 2018 Soheil Novinfard. All rights reserved.
//

#ifndef Log_hpp
#define Log_hpp

#include <stdio.h>
#include <vector>
#include <ctime>

class Log
{
public:
	Log();
	
	void addWon();
	void addLost();
	void finishLogging();
	void startLogging();
	
private:
	int round;
	int won;
	int lost;
	time_t startTime;
	time_t endTime;
	
	std::vector<std::string> results;
};

#endif /* Log_hpp */
