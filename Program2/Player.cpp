/*
  File:			Player.cpp
  Author:		AlexanderHutchison
  Course:		COMP 220, Computer Programming II
  Date:			9/23/2014
  Description:  This file provides the code and functionality of the player.
*/

#include "stdafx.h"
#include "Player.h"


Player::Player(){
	playerNumber = 000; //Set default number to 000, assuming we wont have more then 999 players.
}
Player::Player(int pn){ //Changed the variable name, didnt like how it was exactly the same as an out of scope variable that was being referenced
	playerNumber = pn;
}
void Player::playCard(Card& c){ //Changed from const because getter has an issue with it.
	for(int i; i < hand.size; i ++)
	{
		if((hand[i].getValue() == c.getValue)&&(hand[i].getSuit() == c.getSuit()))
		{
			hand.erase(hand.begin() + i);
		}
	}
}
void Player::receiveCard(const Card& c){
	hand.push_back(c);
}
void Player::collectTrick(Trick& t)
{
	score += t.calculatePoints();
}
bool Player::hasCard(Card& c) // Removed const
{
	for(int i; i < hand.size; i ++)
	{
		if((hand[i].getValue() == c.getValue)&&(hand[i].getSuit() == c.getSuit()))
		{
			return true;
		}
	}	
	return false;
}
bool Player::canPlayCard(Card &c, Trick& t)
{
	if(t.leadCard().getSuit == c.getSuit())
		return true;
	else
		for(int i; i < hand.size(); i++)
		{
			if(t.leadCard().getSuit() == hand[i].getSuit)
				return false;
		}

		return true;
}
int Player::getPlayerNumber(){return playerNumber;}
int Player::getPlayerScore(){return score;}
void Player::addToPlayerScore(int i)
{
	score += i;
}
vector<Card> Player::getHand(){return Player::hand;}
