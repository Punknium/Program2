/*
  File:			Trick.h
  Author:		Ryder Smith
  Course:		COMP 220, Computer Programming II
  Date:			20 September 2014
  Description:  This class collects the cards during the round.
*/

#ifndef ___TRICK_H
#define ___TRICK_H

#include "Card.h"

class Trick {
public:
	Trick();
	Trick(int leadPlayer);
	//Used to calculate the number of points to give to the player.
	int calculatePoints();
	//Used when a player lays down a card.
	void addCard(int playerNumber, const Card& c);
	//Returns who should pick up the trick
	int getCollector();
	//Returns if hearts can be lead or not.
	bool canHeartsLead();
	//Returns the card that was lead with.
	Card leadCard();
	//Returns the lead player's number
	int getLeadPlayer();
private:
	Card cards[4];
	int leadPlayer;
	static bool heartsLead;
};


#endif
