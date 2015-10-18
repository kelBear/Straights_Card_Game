//
//  Player.h
//  project part 1
//
//  Created by Tianyi Li on 2015-06-14.
//  Copyright (c) 2015 Tianyi Li. All rights reserved.
//

#ifndef __project_part_1__Player__
#define __project_part_1__Player__

//#include "Card.h"
//#include "Hand.h"
#include "Table.h"
#include "Discard.h"

class Player{
public:
    ~Player();      //destructor
    Player(std::vector<Card*>, int);    //constructor
    Player(Player const &);     //copy constructor
    std::string virtual play(Table*, int) = 0;     //pure virtual function of play
	int calculateScore();       // calculates score of current round
	void deal(std::vector<Card*>);        // deals cards to hand
	int getScore() const;       // accessor - gets score
	Hand* gethand() const;      // accessor - gets cards in hand
	Discard* getdisard() const;     // accessor - gets discarded cards
    std::string virtual getType()=0;		// pure virtual gettype function to return type of player
    class IllegalPlayException {		//illegal play exception class
    public:
        IllegalPlayException();
    };
protected:
    int getID() const;      // accessor - gets player ID
private:
    int id_;        // player ID
    int score_;     // current score
    Hand* hand_;        // cards in hand
    Discard* discard_;      // cards discarded
    std::string type;		// type of player
    
};

class HumanPlayer : public Player{      //HumanPlayer class - inherits from Player
public:
    std::string getType();				// accessor - gets type of player
    HumanPlayer(std::vector<Card*>, int);       // constructor
private:
    std::string play(Table*, int);     // overridded play function
};

class ComputerPlayer : public Player{      //ComputerPlayer class - inherits from Player
public:
    std::string getType();				// accessor - gets type of player
    ComputerPlayer(Player const &);         // constructor
    ComputerPlayer(std::vector<Card*>, int);    //copy constructor
private:
    std::string play(Table*, int);     // overrided play function
};
const int PLAYER_COUNT = 4;
#endif /* defined(__project_part_1__Player__) */
