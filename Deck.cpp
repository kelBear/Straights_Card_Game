//
//  Deck.cpp
//  project part 1
//
//  Created by Tianyi Li on 2015-06-17.
//  Copyright (c) 2015 Tianyi Li. All rights reserved.
//

#include "Deck.h"

using namespace std;


Deck::Deck() {		//constructor - pushes cards to deck
	int k = 0;
	for (int i = 0; i < SUIT_COUNT; i++){
		for (int j = 0; j < RANK_COUNT; j++){
			cards_[k] = new Card(static_cast<Suit>(i), static_cast<Rank>(j));
			deck_.push_back(cards_[k]);
			k++;

		}
	}
}

vector<Card*> Deck::getDeck() const {		//accessor - gets deck
	return deck_;
}

void Deck::shuffleDeck(int seed) {
	shuffle(seed);                                  //shuffle the card, game begins
	deck_.clear();
	for (int i = 0; i < CARD_COUNT; i++){
		deck_.push_back(cards_[i]);
	}
}
std::vector<Card*> Deck::deal(int playernum){		//deal cards to player's hand
	vector<Card*> hand;
	hand.clear();
	int index = (CARD_COUNT / 4)*(playernum - 1);
	int last = index + CARD_COUNT / 4;
	for (int i = index; i < last; i++){
		hand.push_back(deck_[i]);
	}
	return hand;		//returns hand of the player
}
ostream& operator<<(std::ostream &sout, Deck& deck) {		//output operator
	for (int i = 0; i < CARD_COUNT; i++){
		if ((i + 1) % RANK_COUNT == 0){
			sout << *(deck.getDeck()[i]) << endl;
		}
		else sout << *(deck.getDeck()[i]) << " ";
	}
	return sout;
}
