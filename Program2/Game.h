/*
  File:			Game.h
  Author:		Ryder Smith
  Course:		COMP 220, Computer Programming II
  Date:			20 September 2014
  Description:  This class handles the game.
*/

#ifndef ___GAME_H
#define ___GAME_H

#include "Trick.h"
#include "Player.h"
#include "Deck.h"
#include "Interface.h"

class Game {
public:
	//This function is used by the main class to start the game.
	static void startGame();
	//Used in startGame to start a new round.
	static void startRound();
	//Prompts the user for a card.
	static void askForCard(Player &p, Trick &t);
	//Shows a players hand.
	static void showHand(Player &p);
	//Shows the trick in the center
	static void showTrick(Trick &t);
private:
	//This array hold the 4 people that are playing
	static Player players[4];
	//This is the player that is to play first
	static int leadPlayer;
	//Object that manages the console window
	static Interface interfase;
	//Each player's total score that is preserved between games.
	static int totalScore[4];
};

#endif