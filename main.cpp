/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief main
 * 
 */
 
#include <iostream>
#include <vector>
#include "Card.h"
#include "Deck.h"
#include "ComputerPlayer.h"
#include "TerminalPlayer.h"
#include "Player.h"
#include <assert.h>


using namespace std;

int main()
{
	TerminalPlayer player1 = TerminalPlayer("Steve");
	ComputerPlayer player2 = ComputerPlayer("Computer");
	Deck deck = Deck();
    Card joker;
    player1.receiveCard(deck.draw());
    player2.receiveCard(deck.draw());
    player1.receiveCard(deck.draw());
    player2.receiveCard(deck.draw());
    player1.receiveCard(deck.draw());
    player2.receiveCard(deck.draw());

	int player1First = rand() % 2; 
	Card player1Card; 
	Card player2Card; 


	while (player1.hasCards() && player2.hasCards()) {

		if (player1First == false) {
			player1Card = player1.playCard(joker);
			player2Card = player2.playCard(player1Card);
		}

		else {
			player2Card = player2.playCard(joker);
			player1Card = player1.playCard(player2Card);
		}

    	if (player1First == false) {
			cout << "Player1 played "<< player1Card << endl;
			cout << "Player2 played " << player2Card << endl;
		}
		else {
			cout << "Player2 played " << player2Card<< endl;
			cout << "Player1 played " << player1Card<< endl;
        }


        // check the two cards to see who wins

		if (player1Card < player2Card) {
	    	cout << "Player 2 wins this round" << endl;
			player2.addScore(2);
			player1First = true;
		}
        else if (player2Card < player1Card) {
        	cout << "Player 1 wins this round" << endl;
			player1.addScore(2);
			player1First = false;
        }

        else {
            player1.addScore(1);
            player2.addScore(1);
            cout << "Tie this round" << endl;
        }
		cout << "\n============================================" << endl;


        // update the score 

        // based on the winner we need to determine who goes first fro the next round 

        // if there are cards left in teh deck, draw cards for the players
        
    	if (!deck.isEmpty() && player1First == false) {
			player1.receiveCard(deck.draw());
			player2.receiveCard(deck.draw());
		}
		else if (!deck.isEmpty() && player1First == true) {
			player2.receiveCard(deck.draw());
			player1.receiveCard(deck.draw());
		
        }
    }


	if (player2.getScore() < player1.getScore()) {
		cout << "Player 1 wins at end of game" << endl;
	}
	else if (player1.getScore() < player2.getScore()) {
		cout << "Player 2 wins at end of game" << endl;
	}
	else {
		cout << "The game ends in tie" << endl;
	}


	return 0;
}
