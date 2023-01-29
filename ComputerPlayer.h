/**
 * @file Player.h
 * 
 */
#ifndef COMPUTERPLAYER_H_
#define COMPUTERPLAYER_H_

#include <vector>

#include "Card.h"
#include "Player.h"

#define MAX_HAND_SIZE 3

/**
 * Abstract Player class
 */
class ComputerPlayer : public Player {
public:
     /**
      * @brief Construct a new TerminalPlayer object. 
      * 
      * @param name 
      */
	ComputerPlayer(std::string name) : Player(name) {
        // empty
	}

	/**
	 * @brief Destroy the Player object
	 * 
	 */
	virtual ~ComputerPlayer() {
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

};

#endif /* COMPUTERPLAYER_H_ */
