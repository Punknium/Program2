/*
  File:			Deck.cpp
  Author:		Ian Finlay
  Course:		COMP 220, Computer Programming II
  Date:			9/20/2014
  Description:  This file provides the functions for the Deck class in
				hearts game.
*/
#include "stdafx.h"
#include "Deck.h"
#include <cstdlib>
#include <ctime>
using std::rand;
using std::time;
using std::swap;


Deck::Deck(){}

/*
Functions starts here!!
*/

void Deck::shuffleDeck() //Shuffles the deck
{
	srand(time(0));
	for (int i = 0; i < CARDS_IN_A_DECK; i++)//ARRAYS START AT 0 - fixed
	{
		int randNum = rand() % CARDS_IN_A_DECK;//USE YOUR CONSTANTS - fixed
		swap(deck[i], deck[randNum]);
	}
}

/*
Deals the cards out to the players.
*/
void Deck::drawCard(Player& p)
{
	p.getHand();
}