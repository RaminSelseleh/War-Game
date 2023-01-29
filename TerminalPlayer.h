/**
 * @file Player.h
 * 
 */
#ifndef TERMINALPLAYER_H_
#define TERMINALPLAYER_H_

#include <vector>

#include "Card.h"
#include "Player.h"

#define MAX_HAND_SIZE 3

/**
 * Abstract Player class
 */
class TerminalPlayer : public Player {
public:
     /**
      * @brief Construct a new TerminalPlayer object. 
      * 
      * @param name 
      */
	TerminalPlayer(std::string name) : Player(name) {
        // empty
	}

	/**
	 * @brief Destroy the Player object
	 * 
	 */
	virtual ~TerminalPlayer() {
		// empty
	}

     /**
      * @brief Play a card. If the opponentCard is a joker then this player is going first else
	  * this player is going second and the opponentCard is the card our opponent played
      * 
      * @param opponentCard 
      * @return Card 
      */
	Card playCard(const Card& opponentCard);

     /**
      * @brief Output the player's name
      * 
      * @param out 
      * @param p 
      * @return std::ostream& 
      */
	friend std::ostream& operator <<(std::ostream& out, const Player& p);

//protected:

//	int score;
//	std::string name;
//	std::vector<Card> hand;
};

#endif /* TERMINALPLAYER_H_ */
