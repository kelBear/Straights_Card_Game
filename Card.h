//
//  Card.h
//  project part 1
//
//  Created by Tianyi Li on 2015-06-12.
//  Copyright (c) 2015 Tianyi Li. All rights reserved.
//

#ifndef _CARD_
#define _CARD_

#include <ostream>
#include <istream>

enum Suit { CLUB, DIAMOND, HEART, SPADE, SUIT_COUNT };
enum Rank { ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN,
    EIGHT, NINE, TEN, JACK, QUEEN, KING, RANK_COUNT };

class Card{
    friend std::istream &operator>>(std::istream &, Card &);
    
public:
    Card(Suit, Rank);
    Suit getSuit() const;
    Rank getRank() const;
    
private:
    Suit suit_;
    Rank rank_;
};

bool operator==(const Card &, const Card &);

//output/input Card in the format <rank><suit>
std::ostream &operator<<(std::ostream &, const Card &);
std::istream &operator>>(std::istream &, Card &);
const int CARD_COUNT=52;
#endif