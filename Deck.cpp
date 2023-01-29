/**
 * @file Deck.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */

 #include "Deck.h"
 #include "Card.h"
 #include <iostream>
 #include <ostream>
 #include <stdexcept>
#include <iostream>     // std::cout
#include <algorithm>    // std::shuffle
#include <array>        // std::array
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock   

 Deck::Deck() {
     // for loop for the card suit
     for (unsigned int s = 0; s < 4; s++) {
        // for for the card rank
        for (unsigned int r = 1; r < 14; r++) {
            // insintiate a card(suit, rank)

            // add this new card to the Deck vector
			cardDeck.push_back(Card(Card::Suit(s), Card::Rank(r)));
     }
     }
    // set next card = 0
    nextCard = 0;
 }


 Card Deck::draw() {
     // check the next card > max cards
	if (nextCard >= 52) {
         // if it is throw ourt of range exception
        throw std::out_of_range("out of range!");
    }
     // else get the next card 
    else {

       Card c = cardDeck[nextCard];
    //increment next card 
        nextCard ++;

     // returen the card we fetched
     return c;
    }
 }


 bool Deck::isEmpty() const {
	return nextCard == 52;
}


void Deck::shuffle() {
  // using built-in random generator:
  //std::random_shuffle ( cardDeck.begin(), cardDeck.end() );
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle (cardDeck.begin(), cardDeck.end(), std::default_random_engine(seed));
    nextCard = 0;

}



