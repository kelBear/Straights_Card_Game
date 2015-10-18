//
//  Table.h
//  project part 1
//
//  Created by Tianyi Li on 2015-06-16.
//  Copyright (c) 2015 Tianyi Li. All rights reserved.
//

#ifndef __project_part_1__Table__
#define __project_part_1__Table__

#include <iostream>
#include <vector>
#include "Card.h"
#include "Hand.h"

class Table {       // table class
public:
	Table();        // constructor
	~Table();       // destructor
	std::vector<Card*> getcards() const;    // accessor - gets cards on table
	void addCard(Card*);		// adds card on table
	std::vector<Card*> legalPlay(Hand*);		// vector of legal plays
	std::vector<Card*> getLegal() const;		//accessor - gets all legal plays
	bool checkLegal(Card*);		// checks if a card is legal play
private:
	std::vector<Card*> legal_;
	std::vector<Card*> cardsOnTable_;
};

std::ostream& operator<<(std::ostream &, Table&);

#endif /* defined(__project_part_1__Table__) */
