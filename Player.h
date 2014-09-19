/*
  File: Player.h
  Author:  Ryder Smith
  Course:  COMP 220, Computer Programming II
  Date:    20 September 2014
  Description:  This class is used to each of the players.
*/

#ifndef ___PLAYER_H
#define ___PLAYER_H

#include Card.h
#include Trick.h
#include <vector>
using std::vector;

class Player {
public:
	//Each player must have a unique playerNumber.
	Player(int playerNumber);
	//Is used when a card is needed to be added to the hand.
	void receiveCard(const Card& c);
	//Is used at the end of each round to add to the player's score.
	void collectTrick(const Trick& t);
	//Getter for the player's number
	int getPlayerNumber();
	//Getter for the player's score.
	int getPlayerScore();
private:
	Vector<Card> hand;
	int score = 0;
	int playerNumber;
};


#endif
