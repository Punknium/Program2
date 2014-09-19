/*
  File: Deck.h
  Author:  Ryder Smith
  Course:  COMP 220, Computer Programming II
  Date:    20 September 2014
  Description:  This class is used to manage the deck of cards.
*/

#ifndef ___DECK_H
#define ___DECK_H

#include Card.h

class Deck {
public:
	//Function is used to shuffle the deck
	void shuffleDeck();
	//Function picks a random card from the deck and gives it to a player
	void drawCard(Player& p);
private:
	static const int CARDS_IN_A_DECK = 52;
	Card[] deck = new Card[CARDS_IN_A_DECK];
};


#endif
