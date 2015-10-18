//
//  Deck.h
//  project part 1
//
//  Created by Tianyi Li on 2015-06-17.
//  Copyright (c) 2015 Tianyi Li. All rights reserved.
//

#ifndef __project_part_1__Deck__
#define __project_part_1__Deck__

#include <stdio.h>
#include <vector>
#include "Card.h"
#include "shuffle.h"

class Deck {
public:
	Deck();
	std::vector<Card*> getDeck() const;
	void shuffleDeck(int);
	std::vector<Card*> deal(int);		//deal cards to players
private:
	std::vector<Card*> deck_;
};

std::ostream& operator<<(std::ostream &, Deck&);

#endif /* defined(__project_part_1__Deck__) */
