//
//  Discard.h
//  project part 1
//
//  Created by Tianyi Li on 2015-06-14.
//  Copyright (c) 2015 Tianyi Li. All rights reserved.
//

#ifndef __project_part_1__Discard__
#define __project_part_1__Discard__

#include "Card.h"
#include <vector>

class Discard {     // Discard class
public:
    Discard();      // constructor
	~Discard();     // destructor
    std::vector<Card*> getdiscard() const;        // accessor - gets discard
    void addCard(Card*);        // function to add a card into discard
    Discard& operator=(const Discard& discard);     // assignment operator
private:
    std::vector<Card*> discard_;    // discard vector
};

#endif /* defined(__project_part_1__Discard__) */
