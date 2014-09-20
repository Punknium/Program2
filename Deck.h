/*
  File:			Deck.h
  Author:		Ryder Smith
  Course:		COMP 220, Computer Programming II
  Date:			20 September 2014
  Description:  This class is used to manage the deck of cards.
*/

#ifndef ___DECK_H
#define ___DECK_H

#include "Card.h"
#include "Player.h"
#include <vector>
using std::vector;

class Deck {
public:
	//Puts all of the needed cards into the deck
	Deck();
	//Shuffles the deck.
	void shuffleDeck();
	//Picks a card from the deck, gives it to a player, and removes it from the deck.
	void drawCard(Player& p);
private:
	static const int CARDS_IN_A_DECK = 52;
	vector<Card> deck;
};

#endif
