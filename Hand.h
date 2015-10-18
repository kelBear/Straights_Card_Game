//
//  Hand.h
//  project part 1
//
//  Created by Tianyi Li on 2015-06-14.
//  Copyright (c) 2015 Tianyi Li. All rights reserved.
//

#ifndef __project_part_1__Hand__
#define __project_part_1__Hand__

#include <stdio.h>
#include "Card.h"
#include <vector>

class Hand {        // Hand class
public:
    Hand(std::vector<Card*>);       // constructor
	~Hand();        // destructor
    std::vector<Card*> gethand() const;       // accessor - gets hand
    int findCard(Suit, Rank);       // function to find card in hand
    void removeCard(Suit, Rank);    // function to remove card from hand
    Hand& operator=(const Hand& hand);      // assignment operator
private:
    std::vector<Card*> hand_;       // hand - represented by vector of cards
};

std::ostream& operator<<(std::ostream &sout, Hand &hand);       // output operator

#endif /* defined(__project_part_1__Hand__) */
