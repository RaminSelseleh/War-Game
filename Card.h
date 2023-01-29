/**
 * @file Card.h
 *
 */
#ifndef CARD_H_
#define CARD_H_

#include <iostream>
#include <string>

 /**
  * @brief String constants for the suits. Use these for the << operator. Use the ordinal value
  * of the Suit enum as an index to fetch the Card suit name
  */
 static const std::string suitNames[] =
		{ "Spades", "Hearts", "Diamonds", "Clubs" };

 /**
  * @brief String constants for the rank. Use these for the << operator. Use the ordinal value
  * of the Rank enum as an index to fetch the Card rank name
  * 
  */
static const std::string rankNames[] = { "Joker", "Two", "Three", "Four",
		"Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King",
		"Ace" };

 /**
  * @brief Card class to represent a single playing card
  * 
  */
class Card {
public:
     /**
      * @brief Suit enumerations
      * 
      */
	enum Suit {
		Spades = 0, Hearts, Diamonds, Clubs
	};

     /**
      * @brief Rank enumerations ordered by value for game of war
      * 
      */
	enum Rank {
		Joker = 0,
		Two,
		Three,
		Four,
		Five,
		Six,
		Seven,
		Eight,
		Nine,
		Ten,
		Jack,
		Queen,
		King,
		Ace
	};

     /**
      * @brief Construct a new Card object
      * 
      * @param s 
      * @param r 
      */
	Card(Suit s, Rank r);

     /**
      * @brief Construct a new Card object. The empty constructor will create a joker card.
	 * The joker card is a special card given to the player going first.
      * 
      */
	Card();

     /**
      * @brief Destroy the Card object
      * 
      */
	virtual ~Card() {
		// empty
	}

	/**
	 * Return true if this card is a joker
	 */
	bool isJoker() const {
		return (cardRank == Joker);
	}

     /**
      * @brief Output the card to an output stream as "rank of suit", except for the joker which 
      * is just output as "Joker"
      * 
      * @return std::ostream& 
      */
	friend std::ostream& operator <<(std::ostream&, const Card&);

    /**
     * @brief == compare operator. For the game of war we only care about the rank value
     * 
     * @param lhs 
     * @param rhs 
     * @return true 
     * @return false 
     */
	friend bool operator ==(const Card &lhs, const Card &rhs);

    /**
     * @brief < compare operator. For the game of war we only care about the rank value
     * 
     * @param lhs 
     * @param rhs 
     * @return true 
     * @return false 
     */
	friend bool operator <(const Card &lhs, const Card &rhs);

private:
	Suit cardSuit;
	Rank cardRank;
};

#endif /* CARD_H_ */
