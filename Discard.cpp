//
//  Discard.cpp
//  project part 1
//
//  Created by Tianyi Li on 2015-06-14.
//  Copyright (c) 2015 Tianyi Li. All rights reserved.
//

#include "Discard.h"

Discard::Discard() {        // constructor - clears discard initially
	discard_.clear();
}

Discard::~Discard() {       // destructor
	discard_.clear();
}

std::vector<Card*> Discard::getdiscard() const {  // accessor - returns discard vector
	return discard_;
}

void Discard::addCard(Card* card) {     // adds card into discard vector
	discard_.push_back(card);
}

Discard& Discard::operator=(const Discard& discard){    // assignment operator - assigns all discarded cards
	discard_.clear();
	for (int i = 0; i < discard.discard_.size(); i++) {
		discard_.push_back(discard.discard_[i]);
	}
	return *this;
}