/*
  File:			Interface.h
  Author:		Ryder Smith
  Course:		COMP 220, Computer Programming II
  Date:			20 September 2014
  Description:  This class interfaces with the players
*/

#ifndef ___INTERFACE_H
#define ___INTERFACE_H

#include "Card.h"
#include "Player.h"

class Interface {
public:
	Interface();
	void drawBoard();
	void setCursorPos(int x, int y);
	void setColor(int f, int b);
	void drawHands();
	void hideHands();
	void hideTrick();
	void drawCard(Card& c, int hand, int slot);
	char suitToChar(Suit s);
	char valueToChar(Value s);
	void printText(const char *text);
	void printError(const char *text);
	void clearText();
	void clearError();
	void drawScore(Player& p, int& totScore);
	void drawRules();
private:

};

#endif
