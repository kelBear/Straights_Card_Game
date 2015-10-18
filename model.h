/*
 * MVC example of GTKmm program
 *
 * Model class.  Is responsible keeping track of the deck of cards.  
 * It knows nothing about views or controllers.
 *
 *  Created by Jo Atlee on 06/07/09.
 *  Copyright 2009 UW. All rights reserved.
 *
 */


#ifndef MVC_MODEL_H
#define MVC_MODEL_H

#include <vector>
#include <string>

#include "subject.h"
#include "Player.h"
#include "Table.h"
#include "Deck.h"
#include <vector>

//const int numFaces = 6;
//const int numSuits = 4;
//const int numCards = numFaces * numSuits;

//enum Faces { NINE, TEN, JACK, QUEEN, KING, ACE, NOFACE };
//enum Suits { DIAMOND, CLUB, HEART, SPADE, NOSUIT };

class Model : public Subject {
public:
    Model();
    void startGame(int);			//initialize game
    void startplay(int);			//begins first round of game
    void Playcard(int);				//player plays a card
    void quitGame();
    void setPlayerType(int, std::string);
    int getplayerindex() const;			//accessor - gets current player index
    Player* getcurrentplayer() const;	//accessor - gets current Player
    std::vector<bool> getTable() const;			//accessor - gets table
    std::vector<bool> convertLegal() const;		//converts legal play cards into boolean values
    int getround() const;				// accessor - gets current round number
    std::string getendgamemsgs() const;		//accessor - gets messages at end of game
    std::string getwinners() const;			//accessor - gets messages of winners
    bool getwinner() const;			// accessor - gets boolean of whether winner exists
    void init(int);			// setup game
    void setTable();		// setup table
    std::vector<int> getDiscardSize() const;		//accessor - get number of discards
    std::vector<int> getScores() const;		// accessor - gets scores
    std::vector<std::string> getPlayerTypes() const;		// accessor - gets type of player (of all players)
    void ragequit();		
    std::string getmoves() const;		// accessor - gets moves made of player
private:
    Table *table;
    int round_;
    int playerindex_;		// current player index
    std::string playersType_ [4];	//player types of all players
    std::vector<Player*> players_;            // vector of all players
    Deck* deck_;            // Deck object of current deck
    std::string playCode_;                    // command
    bool nowinner_;			//whether winner exists of not
    bool firstround_;     // boolenan flags for first round
    void calculatescore();		//helper function to calculate score
    std::string message;		//message for end of game
    std::string winner;			//message for winners
    std::string moves_;			//textual of moves made
    void nextRound();		//helper function - play a card & call notify() if human player
}; // Model


#endif
