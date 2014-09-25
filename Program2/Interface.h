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
	//Perpares the console windows
	Interface();
	//Draws the outline of the board
	void drawBoard();
	//Draws the outlines for all of the cards
	void drawHands();
	//Draws the card (c) in hand (hand) in slot (slot)
	//Valid hands are
	//0 - bottom
	//1 - left
	//2 - top
	//3 - right
	//4 - center
	void drawCard(Card& c, int hand, int slot);
	//Draws player (p)'s score for the game and overall
	void drawScore(Player& p, int& totScore);
	//Displays the rules and waits for the user to continue
	void drawRules();
	//Hides the value of the cards in the players' hands
	void hideHands();
	//Hides the value of the trick cards in the center
	void hideTrick();
	//Returns a char to represent each suit.
	char suitToChar(Suit s);
	//Returns a char to represent each value.
	char valueToChar(Value s);
	//Prints text at the bottom of sthe board
	void printText(const char *text);
	//Prints an error in red at the bottom of the board
	void printError(const char *text);
	//Clear the output text line
	void clearText();
	//Clears the error line
	void clearError();
	//Moves where text will be output
	void setCursorPos(int x, int y);
	//Changes the text and background color
	//Valid options are
	/*	0 = Black       8		= Gray
		1 = Blue        9		= Light Blue
		2 = Green       A(10)	= Light Green
		3 = Aqua        B(11)	= Light Aqua
		4 = Red         C(12)	= Light Red
		5 = Purple      D(13)	= Light Purple
		6 = Yellow      E(14)	= Light Yellow
		7 = White       F(15)	= Bright White */
	void setColor(int f, int b);
private:

};

#endif
