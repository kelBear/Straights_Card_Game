//
//  Table.cpp
//  project part 1
//

#include "Table.h"
#include "cmath"
#include <string>

using namespace std;

Table::Table(){}

Table::~Table() {		//destructor
	cardsOnTable_.clear();
	legal_.clear();
}

vector<Card*> Table::getcards() const {		//accessor - gets cards on the table
	return cardsOnTable_;
}

void Table::addCard(Card* newcard) {            //sort while add from smallest to largest wrt RANK
	for (int i = 0; i < cardsOnTable_.size(); i++) {
		if (newcard->getRank() < cardsOnTable_[i]->getRank()){
			cardsOnTable_.insert(cardsOnTable_.begin() + i, newcard);
			return;
		}
	}
	cardsOnTable_.push_back(newcard);
}

vector<Card*> Table::legalPlay(Hand* hand){		//determines legal play based on cards on the table
	legal_.clear();
	for (int i = 0; i < hand->gethand().size(); i++){
		if (hand->gethand()[i]->getRank() == SEVEN){		//if seven of spades is on hand, it's the only legal play
			if (hand->gethand()[i]->getSuit() == SPADE){
				legal_.clear();
				legal_.push_back(hand->gethand()[i]);
				return legal_;
			}
			else legal_.push_back(hand->gethand()[i]);
		}
		for (int j = 0; j < cardsOnTable_.size(); j++){			//adds legal plays in vector

			if (cardsOnTable_[j]->getSuit() == hand->gethand()[i]->getSuit() && abs(cardsOnTable_[j]->getRank() - hand->gethand()[i]->getRank()) == 1){
				legal_.push_back(hand->gethand()[i]);
			}
		}
	}
	return legal_;
}

bool Table::checkLegal(Card* card){		//helper function - checks if a card is a legal play
	for (int i = 0; i < legal_.size(); i++){
		if (*card == *legal_[i]){
			return true;
		}
	}
	return false;
}

std::vector<Card*> Table::getLegal() const {		//accessor - gets legal play vector
	return legal_;
}

ostream& operator<<(std::ostream &sout, Table &table) {
	sout << "Cards on the table:" << endl;
	string suitarray[SUIT_COUNT] = { "Clubs: ", "Diamonds: ", "Hearts: ", "Spades: " };
	string convertranks[RANK_COUNT] = { "A", "2", "3", "4", "5", "6",
		"7", "8", "9", "10", "J", "Q", "K" };
	for (int i = 0; i < SUIT_COUNT; i++) {
		sout << suitarray[i];
		for (int j = 0; j < table.getcards().size(); j++){
			if (table.getcards()[j]->getSuit() == i){
				sout << convertranks[table.getcards()[j]->getRank()] << " ";
			}
		}
		sout << endl;
	}
	return sout;
}
