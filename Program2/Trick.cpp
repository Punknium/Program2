/*
  File:			Trick.cpp
  Author:		Ian Finlay
  Course:		COMP 220, Computer Programming II
  Date:			9/20/2014
  Description:  This file provides the functions for the trick and scoring 
				parts of the hearts game.
*/
#include "stdafx.h"
#include "Trick.h"
#include "Card.h"

Trick::Trick()
{
}

Trick::Trick(int leadPlayer)
{
	this->leadPlayer = leadPlayer;
}

int Trick::calculatePoints()
{
	// this calculates how many points the player has
	int points = 0;
	int i = 0; // card in the list
	for (int i = 0; i < 4; i++)//while card trick list is not emepty
	{
		if (cards[i].getSuit() == 2)//if the card is heart add one point to points
		{
			points = points + 1;
		}
		if (cards[i].getSuit() == 3 && cards[i].getValue() == 11) // This calculates the points for the queen of spades.
		{
			points = points + 13;
		}
	}
	return 0;
}

void Trick::addCard(int playerNumber, const Card& c)
{
	cards[playerNumber] = c;
}

int Trick::getCollector()
{
	int i = leadPlayer;
	Suit leadCardSuit = cards[i].getSuit();
	int leadCardValue = cards[i].getValue();
	int highestCardValue = leadCardValue;
	int playerHighestCard = leadPlayer;
	for (int i = 0; i < 4; i++)
	{
		if(cards[i].getSuit() == leadCardSuit)
		{
			if(highestCardValue < cards[i].getValue())
			{
				highestCardValue = cards[i].getValue();
				playerHighestCard = i;
			}
		}
	}
	return playerHighestCard;
}

bool Trick::isTheMoonShot()
{
	// if player has collected all 26 points then that player gets 0 points
	// and the others players get 26 points.
	return false;
}

bool Trick::canHeartsLead()
{
	return false;
}

Card Trick::leadCard()
{
	return Card();
}

int Trick::getLeadPlayer()
{
	return 0;
}
