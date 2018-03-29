# Pantoon (Blackjack) Game in C++
This is a Pantoon (Blackjack) game which is written in C++ language based on object-oriented principles.

## Structure of Program
I tried to use the object-oriented programming principles as much as I can, even a little more than normal level it should be to demonstrate the power of OOP covered. The different classes used in the program described shortly as follows.

## Card Class
In this class, game cards defined. I used enumerators in this class, because it prevents of inserting invalid values and it is a best-practice way (comparing with character for each value). I used 11, 12 and 13 number when I defined `Face`, but it`s a trick to overcome one of the shortages of enumerators in C++ where you should allocate different values to each enumerator member to make it recognisable.

The class is encapsulated. In addition, the map is used to make connection between enumerator values and the related label. 

I wrote a template named `as_integer` as well to convert enumerator to its integer value which encapsulate the logic into a function template.

## Deck Class
In Deck class, I put two vectors, one for available cards and one for used card. The member functions named "printCurrentCards" and "printUsedCards" are written for debugging. The `setupDeck` will fill the deck with 52 cards.

The `shuffle` is one of the important member functions which shuffle the deck. The `random_shuffle` should shuffle the vector, but it does not work properly without adding more programming salt to. First, it needs to random iterator, I used rand function of standard library for it. However, this function gives the same number in every start of the program, so by using `srand` and passing the current time to it, I finally get the desired result.

## Actor, Player and Bank Class
We have 2 actors in this program, "the bank" and "the player". They have very similar behaviours and there was a possibility to use only one class for both of them. However, I implemented `Actor` as parent class for both of them and then two inherited class `Player` and `Bank` was written. There are two reasons for this. First, I tried to show the power of OOP and polymorphism by this decision as I described it in the following "game class" section. Second, I increased the reusability of the class, so that any other roles in this game or other card games could be written based on this (inheritance).
The `hand` functionality relates to actors, so I implemented it inside this class.

## Game Class
This is the heart of the program, where all parts come together and create the game. The `performCommand` member, get a character and based on that perform different actions in the game.

By "showCards" method, I demonstrated the polymorphism. Just look at line 95,110 and 161 in Game.cpp. In `showCards` it calls each `viewCards` member function of "Player" and "Bank" class rather than "Actor" class because it is marked as `virtual` by `Actor` class, thus, inherited classes have the responsibility of implementing this function.

NOTE: In "stick" member function, I considered that we should check the condition of giving new card at first and then we the bank give a card. If the logic of game is something that should give new card even if conditions does not meet at first try (like when the bank cards has more value than the player at first) we should just change the "while" loop to "do while" loop in this method.

## Log Class
When the game starts, it calls `startLogging` to set the start time of the game. After that, whenever player win or lose a game, it is recorded by `addLost` and `addWon` function. The `finishLogging` has the responsibility to prepare the log and write it to a text file. The program outputs the log file content as well as writing to a text file to show the result to the player.


## How to Run the Program
This program is built with the power of latest version of Xcode (9.2) editor (https://developer.apple.com/xcode/) available free for MacOS. The version of C++ language used to compile this project is C++ 11.

To run the project, open the "Pontoon" folder and compile it with any C++ 11 compiler which supports C++ Standard Library(STL).

The compiled program "PontoonGame" is located in the root folder with a sample log file, "180329-1729.txt", created by the program.