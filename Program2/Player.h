/*
  File:			Player.h
  Author:		Ryder Smith
  Course:		COMP 220, Computer Programming II
  Date:			20 September 2014
  Description:  This class is used to each of the players.
*/

#ifndef ___PLAYER_H
#define ___PLAYER_H

#include "Card.h"
#include "Trick.h"
#include <Vector>
using std::vector;

class Player {
public:
	//Default Constructor
	Player();
	//Each player must have a unique playerNumber.
	Player(int playerNumber);
	//Removes card from the player's hand
	void playCard(const Card& c);
	//Is used when a card is needed to be added to the hand.
	void receiveCard(const Card& c);
	//Is used at the end of each round to add to the player's score.
	void collectTrick(const Trick& t);
	//Used to check if a player has a certain card in his/her hand.
	bool hasCard(const Card& c);
	//Used to check if the player is allowed to play the selected card.
	bool canPlayCard(const Card& c);
	//Getter for the player's number
	int getPlayerNumber();
	//Getter for the player's score.
	int getPlayerScore();
	//adds to the players score.
	void addToPlayerScore(int i);
	//Getter for the player's hand
	vector<Card> getHand();
private:
	vector<Card> hand;
	int score;
	int playerNumber;
};


#endif
