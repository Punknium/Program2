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
		if (cards[i].getSuit() == Suit::hearts)//if the card is heart add one point to points
		{
			heartsLead = true;
			points = points + 1;
		}
		if (cards[i].getSuit() == Suit::spades && cards[i].getValue() == Value::queen) // This calculates the points for the queen of spades.
		{
			points = points + 13;
		}
	}
	return points;
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

bool Trick::canHeartsLead()
{
	return heartsLead;
}

Card Trick::leadCard()
{
	return cards[leadPlayer];
}

int Trick::getLeadPlayer()
{
	return leadPlayer;
}
