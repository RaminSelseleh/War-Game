/**
 * @file Player.h
 * 
 */
#ifndef PLAYER_H_
#define PLAYER_H_

#include <vector>

#include "Card.h"

#define MAX_HAND_SIZE 3

/**
 * Abstract Player class
 */
class Player {
public:
	/**
	 * @brief Destroy the Player object
	 * 
	 */
	virtual ~Player() {
		// empty
	}

     /**
      * @brief Play a card. If the opponentCard is a joker then this player is going first else
	  * this player is going second and the opponentCard is the card our opponent played
      * 
      * @param opponentCard 
      * @return Card 
      */
	virtual Card playCard(const Card& opponentCard) = 0;

     /**
      * @brief Receive a card from the dealer
      * 
      * @param c 
      */
	void receiveCard(const Card& c) {
		hand.push_back(c);
	}

     /**
      * @brief Add points to the score
      * 
      * @param s 
      */
	void addScore(unsigned s) {
		score += s;
	}
     /**
      * @brief Get the score
      * 
      * @return int 
      */
	int getScore() const {
		return score;
	}

     /**
      * @brief Reset the score to zero
      * 
      */
	void resetScore() {
		score = 0;
	}

     /**
      * @brief Return true if the player has cards in their hand
      * 
      * @return true 
      * @return false 
      */
	bool hasCards() const {
		return (hand.size() != 0);
	}

     /**
      * @brief Receive the cards played from the completed round. This member function would
	  * be used by a computer player that may need to 'see' what cards were played.
      * 
      * @param card1 
      * @param card2 
      */
	void playedCards(const Card& card1, const Card& card2) {
		// default empty
	}

     /**
      * @brief Output the player's name
      * 
      * @param out 
      * @param p 
      * @return std::ostream& 
      */
	friend std::ostream& operator <<(std::ostream& out, const Player& p);

protected:
     /**
      * @brief Construct a new Player object. Since this is an abstract class we do not 
      * want anyone instantiating a player class so we make it protected.
      * 
      * @param name 
      */
	Player(std::string name) :
			score(0), name(name), hand(0) {
	}

	int score;
	std::string name;
	std::vector<Card> hand;
};

#endif /* PLAYER_H_ */
