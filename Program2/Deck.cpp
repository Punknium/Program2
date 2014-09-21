/*
  File:			Deck.cpp
  Author:		Ian Finlay
  Course:		COMP 220, Computer Programming II
  Date:			9/20/2014
  Description:  This file provides the functions for the hearts game.
*/
#include "stdafx.h"
#include "Deck.h"
#include <cstdlib>
using std::rand;


Deck::Deck(){}

void Deck::shuffleDeck(){}

void Deck::drawCard(Player& p){}

/*
Functions starts here!!
*/

void Deck::shuffleDeck()
{
	const int randMax = 52;
	for (int i = 1; i < 52; i++)
	{
		int x = rand() % 51 + 1;
		int temp = 0;
		temp = Deck[i];
		Deck[i] = Deck[x];
		Deck[x] = temp;
	}
}