/**
 * @file ComputerPlayer.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */


 #include <limits>
 #include <iostream>
 #include <vector>

 #include "ComputerPlayer.h"

 Card ComputerPlayer::playCard(const Card &opponentCard) {
     unsigned index = rand() % hand.size();
     Card chosenCard = hand[index];
     hand.erase(hand.begin() + index);
     return chosenCard;
    
 }
