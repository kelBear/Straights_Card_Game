//
//  Hand.cpp
//  project part 1
//
//  Created by Tianyi Li on 2015-06-14.
//  Copyright (c) 2015 Tianyi Li. All rights reserved.
//

#include "Hand.h"

using namespace std;

Hand::Hand(vector<Card*> card) {        // constructor - adds card in hand vector
	for (int i = 0; i < CARD_COUNT / 4; i++) {
		hand_.push_back(card[i]);
	}
}

Hand::~Hand() {     // destructor - clears hand vector
	hand_.clear();
}

std::vector<Card*> Hand::gethand() const {     // accessor - gets hand vector
	return hand_;
}

int Hand::findCard(Suit suit, Rank rank) {      // finds card in hand given suit and rank - returns index if found, -1 if not found
	for (int i = 0; i < hand_.size(); i++) {
		if (hand_[i]->getSuit() == suit && hand_[i]->getRank() == rank)
			return i;
	}
	return -1;
}

void Hand::removeCard(Suit suit, Rank rank) {   // removes card from hand based on suit and rank
	int index = findCard(suit, rank);
	if (index != -1) {
		hand_.erase(hand_.begin() + index);
	}
}

Hand& Hand::operator=(const Hand& hand){        // assignment operator - assigns all cards in hand
	hand_.clear();
	for (int i = 0; i < hand.hand_.size(); i++) {
		hand_.push_back(hand.hand_[i]);
	}
	return *this;
}

ostream& operator<<(std::ostream &sout, Hand &hand) {   // output operator - outputs all cards in hand

	for (int i = 0; i < hand.gethand().size(); i++) {
		sout << *hand.gethand()[i] << " ";
	}
	sout << endl;
	return sout;
}
