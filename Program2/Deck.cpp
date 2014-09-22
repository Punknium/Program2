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

void Deck::shuffleDeck(){}

void Deck::drawCard(Player& p){}

/*
Functions starts here!!
*/

void Deck::shuffleDeck() //Shuffles the deck
{
	srand(time(0));
	const int CARDS_IN_A_DECK = 52;
	for (int i = 1; i < CARDS_IN_A_DECK; i++)
	{
		int randNum = rand() % 51 + 1;
		swap(deck[i], deck[randNum]);
	}
}

/*
Deals the cards out to the players.
*/
void Deck::drawCard(Player& p)
{
	int i = 0;
	p.receiveCard() = deck[i];
}