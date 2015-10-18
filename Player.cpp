//
//  Player.cpp
//  project part 1
//
//  Created by Tianyi Li on 2015-06-14.
//  Copyright (c) 2015 Tianyi Li. All rights reserved.
//

#include "Player.h"
#include <sstream>

using namespace std;

Player::Player(vector<Card*> cards, int id){        // constructor
	hand_ = new Hand(cards);
	discard_ = new Discard();
	id_ = id;
	score_ = 0;
}

Player::Player(Player const &player) {      // copy constructor - copies ID, hand, discard
	id_ = player.id_;
	vector<Card*> cards;
	for (int i = 0; i < player.hand_->gethand().size(); i++) {
		cards.push_back(player.hand_->gethand()[i]);
	}
    score_=player.score_;
	hand_ = new Hand(cards);
	*hand_ = *player.hand_;
	discard_ = new Discard;
	*discard_ = *player.discard_;
}

Player::~Player() {     // destructor
	delete hand_;
	delete discard_;
}

Hand* Player::gethand() const{      // accessor - gets hand
	return hand_;
}
string HumanPlayer::getType(){
    return "H";
}
string ComputerPlayer::getType(){
    return "C";
}
int Player::getID() const {     // accessor - gets ID
	return id_;
}

Discard* Player::getdisard() const{     // accessor - gets discard
	return discard_;
}

void Player::deal(std::vector<Card*> cards) {       // function - deals cards - clears hand & discard, create new objects
	delete discard_;
	delete hand_;
	hand_ = new Hand(cards);
	discard_ = new Discard();
}

int Player::getScore() const {      // accessor - gets current score
	return score_;
}

int Player::calculateScore(){       // updates score by adding current score with new score from discarded cards from this round
	int score = 0;
	for (int i = 0; i < getdisard()->getdiscard().size(); i++){
		score += getdisard()->getdiscard()[i]->getRank() + 1;
	}
	score_ += score;
	return score;
}

HumanPlayer::HumanPlayer(vector<Card*> cards, int id) : Player(cards, id) {
}    // HumanPlayer constructor

string HumanPlayer::play(Table* table, int index) {    // HumanPlayer play function - handles commands
    stringstream ssm;
    Card *cardplayed=gethand()->gethand()[index-1];
    table->legalPlay(gethand());
    if(table->checkLegal(cardplayed)){
        table->addCard(cardplayed);
        gethand()->removeCard(cardplayed->getSuit(), cardplayed->getRank());
        ssm << "Player " << getID() << " plays " << *cardplayed << "." << endl;
    }
    else if(table->getLegal().size()!=0){
        throw IllegalPlayException();
    }
    else{
        getdisard()->addCard(cardplayed);
        ssm<<"Player "<<getID()<<" discards a card."<<endl;
        gethand()->removeCard(cardplayed->getSuit(), cardplayed->getRank());
    }
    return ssm.str();
}

ComputerPlayer::ComputerPlayer(Player const & oldplayer) : Player(oldplayer){}  // ComputerPlayer constructor

ComputerPlayer::ComputerPlayer(vector<Card*> cards, int id) : Player(cards, id) {}  // ComputerPlayer copy constructor

string ComputerPlayer::play(Table* table, int index) {     // ComputerPlayer play function
    stringstream ssm;
	if (table->legalPlay(gethand()).size() > 0) {       //play first legal card & remove from hand
        Card* played=table->getLegal()[0];
		table->addCard(played);
		ssm << "Player " << getID() << " plays " << *played << "." << endl;
		gethand()->removeCard(played->getSuit(), played->getRank());
	}
	else {      //discard first card and remove from hand
        Card* discarded=gethand()->gethand()[0];
		getdisard()->addCard(discarded);
		ssm << "Player " << getID() << " discards a card."<<endl;
		gethand()->removeCard(discarded->getSuit(), discarded->getRank());
	}
    return ssm.str();
}

Player::IllegalPlayException::IllegalPlayException(){

}