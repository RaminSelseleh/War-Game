/**
 * @file Deck.h
 * 
 */
#ifndef DECK_H_
#define DECK_H_

#include <vector>

#include "Card.h"

#define MaxCards 52

 /**
  * @brief The Deck class holds a deck of 52 cards. Cards are not removed from the Deck.
  * 
  */
class Deck {
public:
    /**
     * @brief Construct a new Deck object
     * 
     */
	Deck();

    /**
     * @brief Destroy the Deck object
     * 
     */
	virtual ~Deck() {
		// empty
	}

	/**
	 * @brief shuffle the deck
     * 
     * https://www.cplusplus.com/reference/algorithm/shuffle/
	 */
	void shuffle();

    /**
     * @brief Return true if the deck is empty (next available card is past the end of the deck)
     * 
     * @return true 
     * @return false 
     */
	bool isEmpty() const;

     /**
      * @brief Draw a card from the deck. If someone attempts to draw a card when the deck is
	 *  empty then throw an out-of-range exception.
      * 
      * @return Card 
      */
	Card draw();

private:
	unsigned nextCard;
	std::vector<Card> cardDeck;
};

#endif /* DECK_H_ */
