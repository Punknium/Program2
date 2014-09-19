/*
  File: Trick.h
  Author:  Ryder Smith
  Course:  COMP 220, Computer Programming II
  Date:    20 September 2014
  Description:  This class collects the cards during the round.
*/

#ifndef ___TRICK_H
#define ___TRICK_H

#include "Card.h"

class Trick {
public:
	
private:
	Card leadCard;
	Card card2;
	Card card3;
	Card card4;
	int leadPlayer;
};


#endif
