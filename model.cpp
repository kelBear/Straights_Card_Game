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


#include "model.h"
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

Model::Model(){
	for (int i = 0; i < 4; i++){
		playersType_[i] = "H";
	}
	round_ = 0;		//initialize round to 0
	playerindex_ = 0;    //initialize the player index to determine who's playing
	deck_ = new Deck();            // deck object of current deck
	nowinner_ = true, firstround_ = true;     // boolenan flags
	moves_ = "";		//no moves made yet
}

Card* cards_[CARD_COUNT];               //global Card array to represent deck_

void Model::setPlayerType(int num, string type) {		//set player type based on index
	playersType_[num - 1] = type;
}

void Model::quitGame() {
	exit(0);
}

int Model::getplayerindex() const {		//accessor - gets current player's index
	return playerindex_;
}

Player* Model::getcurrentplayer() const {		//accessor - gets current player
	return players_[playerindex_];
}
void Model::startGame(int seed){		//start new game
	players_.clear();		//clears all players
	firstround_ = true;
	startplay(seed);
}

void Model::startplay(int seed){		//start round
	nowinner_ = true;			//initialize values
	round_ = 0;
	moves_ = "";
	deck_->shuffleDeck(seed);		//shuffle deck
	for (int i = 1; i <= 4; i++) {      //creates player objects and deals cards
		if (firstround_ == true) {
			if (playersType_[i - 1] == "H")		//create players if first round and deal cards
				players_.push_back(new HumanPlayer(deck_->deal(i), i));
			else
				players_.push_back(new ComputerPlayer(deck_->deal(i), i));
		}
		else {
			players_[i - 1]->deal(deck_->deal(i));
		}
	}
	firstround_ = false;
	for (int i = 0; i < 4; i++) {               //find spade seven to determine the first player
		if (players_[i]->gethand()->findCard(SPADE, SEVEN) != -1){
			playerindex_ = i;
			break;
		}
	}
	//============================================================
	table = new Table;                     //initialize the table for play
	nextRound();							//plays a card
}
void Model::Playcard(int index){			//when a card is played
	round_++;
	if (round_ >= 52){
		calculatescore();		//calculate score when 52 turns are completed
		return;
	}
	moves_ = players_[playerindex_]->play(table, index) + moves_;		//keeps track of moves made by players
	playerindex_++;
	playerindex_ = playerindex_ % 4;
	nextRound();		//plays a card
}
void Model::nextRound(){		//helper function to play a card
	if (players_[playerindex_]->getType() == "H"){
		notify();
	}
	else Playcard(-1);

}
void Model::calculatescore(){		//helper function to calculate score
	stringstream msg;
	stringstream msgwinner;
    vector<int> winnerindex;
	int max = 0;      //minimum score that can be achieved (initial min value)
	int min = 364;    //maximum score that can be achieved (initial max value)
	for (int i = 0; i < players_.size(); i++){       //analyze all player's scores
		int oldscore = players_[i]->getScore();
		int newscore = players_[i]->calculateScore();
		msg << "Player " << i + 1 << "'s discards: ";
		for (int j = 0; j < players_[i]->getdisard()->getdiscard().size(); j++) {
			msg << *players_[i]->getdisard()->getdiscard()[j] << " ";		//adds all discards to message for end of game pop up box
		}
		msg << "\n";
		msg << "Player " << i + 1 << "'s score: " << oldscore << " + " << newscore << " = " << players_[i]->getScore() << endl;
		if (players_[i]->getScore() > max){      // finds max score
			max = players_[i]->getScore();
		}
		else if (players_[i]->getScore() < min){     // finds min score
			min = players_[i]->getScore();
            winnerindex.clear();
            winnerindex.push_back(i+1);
		}
		else if (players_[i]->getScore() == min){        // add additional winner
            winnerindex.push_back(i+1);
		}
		msg << endl << endl;
	}
	message = msg.str();		//assign message to string
	if (max >= 80){     // if score reach at least 80 - end game
		nowinner_ = false;
        for (int i = 0; i < winnerindex.size(); i++) {
            msgwinner << "Player " << winnerindex[i] << " wins!" << endl;		//add winners to message at end of game
        }
		winner = msgwinner.str();	//assign message to string
	}
	notify();
}

int Model::getround() const {		//accessor - gets round number
	return round_;
}

std::string Model::getendgamemsgs() const {		//accessor - gets message for end of game
	return message;
}

std::string Model::getwinners() const {		//accessor - gets winner message
	return winner;
}

bool Model::getwinner() const {		//accessor - gets whether winner exists
	return nowinner_;
}

std::vector<bool> Model::getTable() const{		//accessor - gets cards on table
	vector<bool> tablelist;
	for (int i = 0; i < 52; i++){
		tablelist.push_back(false);			//initialize vector
	}
	for (int k = 0; k < table->getcards().size(); k++){			//if card is on the table, set the index of vector to true to flip the card over on the table
		int place = table->getcards()[k]->getRank() + 13 * table->getcards()[k]->getSuit();
		tablelist.at(place) = true;
	}
	return tablelist;
}

std::vector<bool> Model::convertLegal() const{		//helper function - determine which cards are legal in a player's hand and add into vector as bool values
	vector<bool> legallist;
	table->legalPlay(players_[playerindex_]->gethand());
	for (int i = 0; i < players_[playerindex_]->gethand()->gethand().size(); i++){	//determine bool of legal play for colour coding in UI
		legallist.push_back(table->checkLegal(players_[playerindex_]->gethand()->gethand()[i]));
	}
	return legallist;		//return vector of true/false for green/red
}


void Model::init(int seed){
	playerindex_ = 0;    //initialize the player index to determine who's playing
	//deck_ = new Deck();            // deck object of current deck
	startplay(seed);
}

void Model::ragequit(){		//rage quit
	ComputerPlayer *newPlayer = new ComputerPlayer(*players_[playerindex_]);	//copies human player to new computer player
	Player* temp = players_[playerindex_];		//assigns temp player to delete
	playersType_[playerindex_] = "C";		//set type as computer player
	players_[playerindex_] = newPlayer;		//assigns human player to computer player
	delete temp;		//delete old human player
	Playcard(-1);		//computer player plays card
}

vector<int> Model::getDiscardSize() const{		//accessor - gets number of discards of all players
	vector<int> discardSize;
	for (int i = 0; i < players_.size(); i++){
		discardSize.push_back(players_[i]->getdisard()->getdiscard().size());
	}
	return discardSize;		//returns number of discards for all players
}
vector<string> Model::getPlayerTypes() const{		//accessor - gets player types of all players
	vector<string> playersType;
	for (int i = 0; i < 4; i++){
		playersType.push_back(players_[i]->getType());
	}
	return playersType;		//returns vector of all player types
}
vector<int> Model::getScores() const{		//accessor - gets scores of all players
	vector<int> scores;
	for (int i = 0; i < players_.size(); i++){
		scores.push_back(players_[i]->getScore());
	}
	return scores;
}

string Model::getmoves() const {		//accessor - gets moves made by all players
	return moves_;
}