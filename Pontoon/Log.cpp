//
//  Log.cpp
//  Pontoon
//
//  Created by Soheil on 28/03/2018.
//  Copyright © 2018 Soheil Novinfard. All rights reserved.
//

#include "Log.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <fstream>

using namespace std;

Log::Log() {
	round = 0;
	won = 0;
	lost = 0;
}

void Log::addWon() {
	++round;
	++won;
	
	string result = "Round " + to_string(round) + ": won.";
	results.push_back(result);
}

void Log::addLost() {
	++round;
	++lost;
	
	string result = "Round " + to_string(round) + ": lost.";
	results.push_back(result);
}

void Log::startLogging() {
	startTime = time(0);
}

void Log::finishLogging() {
	endTime = time(0);
	
	// convert date to string
	char startString [80];
	char tmpString [80];
	tm *start = localtime (&startTime);
	strftime (startString, 80, "%H:%M %Y-%b-%d", start);
	strftime (tmpString, 80, "%y%m%d-%H%M", start);
	
	char endString [80];
	tm *end = localtime (&endTime);
	strftime (endString, 80, "%H:%M %Y-%b-%d", end);
	
	// prepare output
	string output = "";
	output.append("Game started at: ").append( startString ).append("\r\n");
	output.append("Game finished at: ").append( endString ).append("\r\n");
	output.append("Rounds: " + to_string(round) + "\r\n");
	output.append("Won: " + to_string(won) + "\r\n");
	output.append("Lost: " + to_string(lost) + "\r\n");
	output.append("--").append("\r\n");
	for (size_t x = 0; x < results.size(); ++x) {
		output.append(results[x] + "\r\n");
	}
	
	// save output as text file
	string fileName =  string(tmpString) + ".txt";
	std::ofstream theStream;
	theStream.open(fileName);
	if(theStream.is_open()) {
		theStream << output;
	} else {
		cout << "Unable to open a file in your operating system. The results is as follows: \r\n";
	}
	cout << endl << fileName << endl;
	cout << output;
	theStream.close();
}




