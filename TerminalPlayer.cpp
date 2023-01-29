/**
 * @file TerminalPlayer.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */


 #include "TerminalPlayer.h"
 #include <iostream>
 #include <iostream>
 #include <ostream>
 #include <stdexcept>   


    Card TerminalPlayer :: playCard(const Card& opponentCard) {
        // if the opponent card is a joker we are going first
        if (opponentCard.isJoker()) {
            std::cout << "You are going first! " << std::endl;
        }
       // if the opponent card is not a joker we are going second and opponent card is what our opponent played
        else {
            std::cout << "The opponent goes first! " << opponentCard << std::endl;
        }

        // display players hand  
        std::cout << "cards in hand are: " << std::endl;

        for (unsigned int i = 0; i < hand.size(); i++) {
            std::cout << i << " is " << hand[i] << std::endl;
        }  

        // prompt to chose a card
        unsigned int cIndex = 0;
        std::cout << "Please eneter a card number " << (hand.size() - 1) << std::endl;
        std::cin >> cIndex;

      // remove the card from the hand and return that card    
        while (cIndex > (hand.size() - 1)) {
            std::cout << "Invalid card, try again!" << std::endl;
            std::cin >> cIndex;
        }

        Card chosenCard = hand[cIndex];
        hand.erase(hand.begin() + cIndex);
        return chosenCard;

    }



