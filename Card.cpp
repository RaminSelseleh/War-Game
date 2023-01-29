/**
 * @file Card.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */

 #include "Card.h"
 #include "Deck.h"



    Card::Card(Suit s, Rank r) {
        cardRank = r;
        cardSuit = s;
    }


    Card::Card() {
	    cardRank=Joker;
	    cardSuit=Spades;
    }

    std::ostream& operator <<(std::ostream& os, const Card& c) {
        if (c.cardRank == 0) {
            // return just joker
            return os << rankNames[c.cardRank];
        }
        else {
            // "rank" of "suit"
            return os << rankNames[c.cardRank] << " of " << suitNames[c.cardSuit];
        }
    }


    bool operator ==(const Card &lhs, const Card &rhs) {
        return lhs.cardRank == rhs.cardRank;
    }


	bool operator <(const Card &lhs, const Card &rhs) {
        return lhs.cardRank < rhs.cardRank;
    }
