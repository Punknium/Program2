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
	static void startGame();
	static void startRound();
	static void askForCard(Player &p, Trick &t);
	static void showHand(Player &p);
	static void showTrick(Trick &t);
private:
	static Player players[4];
	static int leadPlayer;
	static Interface interfase;
};

#endif