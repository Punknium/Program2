/*
  File:			Interface.cpp
  Author:		Ryder Smith
  Course:		COMP 220, Computer Programming II
  Date:			20 September 2014
  Description:  This class interfaces with the players
*/

#include "stdafx.h"
#include "Interface.h"
#include <iostream>
#include <Windows.h>
using std::cout;
using std::endl;

//Extended Ascii codes
const char drt = 185;
const char dvl = 186;
const char dur = 187;
const char dlr = 188;
const char dll = 200;
const char dul = 201;
const char dlc = 202;
const char dut = 203;
const char dlt = 204;
const char dhl = 205;
const char dxx = 206;

const char shl = 196;
const char svl = 179;
const char sur = 191;
const char sul = 218;
const char sll = 192;
const char slr = 217;

//Window Sizes
const int width = 80;
const int height = 29;
const int centerW = width/2;
const int centerH = height/2;

Interface::Interface(){
	//Sets the window size
	system("mode con: cols=80 lines=32");
	//Clears the screen
	system("cls");
	//Sets the title
	system("title Hearts");
	//Sets the background and text color
	system("color 2f");
}

void Interface::drawScore(Player& p, int& totScore){
	switch(p.getPlayerNumber()){
	case 0:
		setCursorPos(16, height-7);
		cout << "Player 0: " << totScore << " + " << p.getPlayerScore();
		break;
	case 1:
		setCursorPos(10, 16);
		cout << "Player 1: " << totScore << " + " << p.getPlayerScore();
		break;
	case 2:
		setCursorPos(16, 6);
		cout << "Player 2: " << totScore << " + " << p.getPlayerScore();
		break;
	case 3:
		setCursorPos(width-27, 16);
		cout << "Player 3: " << totScore << " + " << p.getPlayerScore();
		break;
	}
}

void Interface::printError(const char *text){
	clearError();
	//Sets the text color to light red and the background to black
	setColor(12,0);
	setCursorPos(0, height+1);
	cout << text;
	//Resets the colors
	setColor(15,2);
}

void Interface::printText(const char *text){
	clearText();
	setCursorPos(0, height);
	cout << text;
}

void Interface::clearText(){
	setCursorPos(0, height);
	for(int i=0;i<width-1;i++)cout<<" ";
}

void Interface::clearError(){
	setCursorPos(0, height+1);
	for(int i=0;i<width-1;i++)cout<<" ";
}

//Default windows size is 80 x 25
void Interface::drawBoard(){
	//Clears the screen
	system("cls");
	//Prints the top of the board
	cout << dul;
	for(int i=2;i<width;i++) cout << dhl;
	cout << dur;
	//Prints the sides of the board
	for(int j=1;j<height-1;j++){
		cout << dvl;
		for(int i=2;i<width;i++) cout << " ";
		cout << dvl;
	}
	//Prints the sides of the board
	cout << dll;
	for(int i=2;i<width;i++) cout << dhl;
	cout << dlr;
}

//Wrote by Ian
//Used to show all of the rules before the game starts
void Interface::drawRules(){
	//Resizes the windows so all lines are shown
	system("mode con: cols=80 lines=33");
	//Couts all the rules
	cout << "This is the game: HEARTS" << endl
		<< "The object of the game is to be the player" << endl
		<< "with the lowest score." << endl << endl;

	cout << "The object of the game:" << endl
		<< "Players do not want to end up with tricks containing hearts" << endl
		<< "or the queen of spades." << endl << endl;

	cout << "The number of players for the game is 4." << endl << endl;

	cout << "The players are dealt thirteen cards and" << endl
		<< "the player with the two of clubs goes first." << endl << endl;

	cout << "The rules of the game:" << endl << endl;

	cout << "The player with the two of clubs goes first." << endl
		<< "Everyone must follow suit. If they don't have a card" << endl
		<< "in the same suit as the lead card, then the player can" << endl
		<< "play any card that they want." << endl << endl;

	cout << "Scoring:" << endl
		<< "At the end of each hand, the players count the number of hearts" << endl
		<< "that they have, and taking the queen of spades costs that player" << endl
		<< "to gain 13 points. The game ends when one player reaches or exceeds 100 points." << endl
		<< "The winner of the game is the player with the fewest points." << endl << endl;

	cout << "Shooting the moon:" << endl
		<< "If one player manages to get all 26 points for that deal then that player" << endl
		<< "gets zero points for that deal and all other players get 26 points instead." << endl << endl;

	cout << "T suit is equal to Ten of suit." << endl << endl;
	//Waits for user
	system("pause");
	//Resets windows size
	system("mode con: cols=80 lines=32");
}

void Interface::drawHands(){
	
	//draws the top set of cards(player 2)
	setCursorPos(centerW-26, 1);
	cout << sul;
	for(int i=0;i<12;i++){
		cout << shl << shl << shl << (char)210;
	}
	cout << shl << shl << shl << sur;

	setCursorPos(centerW-26, 2);
	cout << svl;
	for(int i=0;i<12;i++){
		cout << ' ' << '1' << ' ' << dvl;
	}
	cout << ' ' << '1' << ' ' << svl;
	
	setCursorPos(centerW-26, 3);
	cout << svl;
	for(int i=0;i<12;i++){
		cout << ' ' << (char)3 << ' ' << dvl;
	}
	cout << ' ' << (char)3 << ' ' << svl;

	setCursorPos(centerW-26, 4);
	cout << sll;
	for(int i=0;i<12;i++){
		cout << shl << shl << shl << (char)208;
	}
	cout << shl << shl << shl << slr;
	
	setCursorPos(centerW-26, 5);
	for(int i=1; i<=13;i++){
		cout << "  " << i;
		if(i<10) cout << " ";
	}

	//Draws the bottom set of cards(player 0)
	setCursorPos(centerW-26, height-6);
	for(int i=1; i<=13;i++){
		cout << "  " << i;
		if(i<10) cout << " ";
	}

	setCursorPos(centerW-26, height-5);
	cout << sul;
	for(int i=0;i<12;i++){
		cout << shl << shl << shl << (char)210;
	}
	cout << shl << shl << shl << sur;

	setCursorPos(centerW-26, height-4);
	cout << svl;
	for(int i=0;i<12;i++){
		cout << ' ' << '1' << ' ' << dvl;
	}
	cout << ' ' << '1' << ' ' << svl;
	
	setCursorPos(centerW-26, height-3);
	cout << svl;
	for(int i=0;i<12;i++){
		cout << ' ' << (char)5 << ' ' << dvl;
	}
	cout << ' ' << (char)5 << ' ' << svl;

	setCursorPos(centerW-26, height-2);
	cout << sll;
	for(int i=0;i<12;i++){
		cout << shl << shl << shl << (char)208;
	}
	cout << shl << shl << shl << slr;

	//Draws the left set of cards(player 1)
	setCursorPos(1,1);
	cout << sul << shl << shl << shl << shl << sur;
	for(int i=0;i<12;i++){
		setCursorPos(1,2+i*2);
		cout << svl << ' ' << '1' << (char)4 << ' ' << svl;
		setCursorPos(1,3+i*2);
		cout << (char)198 << dhl << dhl << dhl << dhl << (char)181;
	}		
	setCursorPos(1,26);
	cout << svl << ' ' << '1' << (char)4 << ' ' << svl;
	setCursorPos(1,27);
	cout << sll << shl << shl << shl << shl << slr;

	for(int i=1; i<=13;i++){
		setCursorPos(8, i*2);
		cout << i;
	}

	//Draws the right set of cards(player 3)
	setCursorPos(width-7,1);
	cout << sul << shl << shl << shl << shl << sur;
	for(int i=0;i<12;i++){
		setCursorPos(width-7,2+i*2);
		cout << svl << ' ' << '1' << (char)6 << ' ' << svl;
		setCursorPos(width-7,3+i*2);
		cout << (char)198 << dhl << dhl << dhl << dhl << (char)181;
	}		
	setCursorPos(width-7,26);
	cout << svl << ' ' << '1' << (char)6 << ' ' << svl;
	setCursorPos(width-7,27);
	cout << sll << shl << shl << shl << shl << slr;
	
	for(int i=1; i<=13;i++){
		setCursorPos(width-9, i*2);
		cout << i;
	}


	//Draws the center cards(The trick)
	setCursorPos(centerW, centerH-4);
	cout << sul << shl << shl << shl << sur;
	setCursorPos(centerW, centerH-3);
	cout << svl << ' ' << 'A' << ' ' << svl;
	setCursorPos(centerW, centerH-2);
	cout << svl << ' ' << (char)3 << ' ' << svl;
	setCursorPos(centerW, centerH-1);
	cout << sll << shl << shl << shl << slr;

	setCursorPos(centerW-5, centerH+1);
	cout << sul << shl << shl << shl << sur;
	setCursorPos(centerW-5, centerH+2);
	cout << svl << ' ' << 'A' << ' ' << svl;
	setCursorPos(centerW-5, centerH+3);
	cout << svl << ' ' << (char)5 << ' ' << svl;
	setCursorPos(centerW-5, centerH+4);
	cout << sll << shl << shl << shl << slr;

	setCursorPos(centerW+1, centerH+1);
	cout << sul << shl << shl << shl << shl << sur;
	setCursorPos(centerW+1, centerH+2);
	cout << svl << ' ' << 'A' << (char)6 << ' ' << svl;
	setCursorPos(centerW+1, centerH+3);
	cout << sll << shl << shl << shl << shl << slr;

	setCursorPos(centerW-7, centerH-3);
	cout << sul << shl << shl << shl << shl << sur;
	setCursorPos(centerW-7, centerH-2);
	cout << svl << ' ' << 'A' << (char)4 << ' ' << svl;
	setCursorPos(centerW-7, centerH-1);
	cout << sll << shl << shl << shl << shl << slr;
	
	//Resets text position
	setCursorPos(0, height);
}

void Interface::hideHands(){
	//Hashed block used to overwrite the face values
	char block = 176;

	//Hides the top cards
	for(int i=0;i<13;i++){
		setCursorPos(centerW-24+i*4, 2);
		cout << block;
		setCursorPos(centerW-24+i*4, 3);
		cout << block;
	}

	//Hides the bottom cards
	for(int i=0;i<13;i++){
		setCursorPos(centerW-24+i*4, height-4);
		cout << block;
		setCursorPos(centerW-24+i*4, height-3);
		cout << block;
	}

	//Hides the left cards
	for(int i=0;i<13;i++){
		setCursorPos(3, 2+i*2);
		cout << block << block;
	}

	//Hides the right cards
	for(int i=0;i<13;i++){
		setCursorPos(width-5, 2+i*2);
		cout << block << block;
	}

	//Resets text position
	setCursorPos(0, height);
}

void Interface::hideTrick(){
	//Hides the value of the cards in the center
	setCursorPos(centerW+3, centerH+2);
	cout << "  ";
	setCursorPos(centerW-5, centerH-2);
	cout << "  ";
	setCursorPos(centerW-3, centerH+3);
	cout << ' ';
	setCursorPos(centerW-3, centerH+2);
	cout << ' ';
	setCursorPos(centerW+2, centerH-3);
	cout << ' ';
	setCursorPos(centerW+2, centerH-2);
	cout << ' ';
	
	//Resets text position
	setCursorPos(0, height);
}

void Interface::drawCard(Card& c, int hand, int slot){
	//Hands
	//0 - bottom
	//1 - left
	//2 - top
	//3 - right
	//4 - center

	//Colors the values to match the suits
	switch(c.getSuit()){
	case hearts:
	case diamonds:
		//Light Red on Green
		setColor(12,2);
		break;
	case clubs:
	case spades:
		//Black on Green
		setColor(0,2);
		break;
	}

	//Draws the card on the screen based on the position above.
	switch(hand){
	case 0:
		setCursorPos(centerW-24+slot*4, height-4);
		cout << valueToChar(c.getValue());
		setCursorPos(centerW-24+slot*4, height-3);
		cout << suitToChar(c.getSuit());
		break;
	case 1:
		setCursorPos(3, 2+slot*2);
		cout << valueToChar(c.getValue()) << suitToChar(c.getSuit());
		break;
	case 2:
		setCursorPos(centerW-24+slot*4, 2);
		cout << valueToChar(c.getValue());
		setCursorPos(centerW-24+slot*4, 3);
		cout << suitToChar(c.getSuit());
		break;
	case 3:
		setCursorPos(width-5, 2+slot*2);
		cout << valueToChar(c.getValue()) << suitToChar(c.getSuit());
		break;
	case 4:
		switch(slot){
		case 0:
			setCursorPos(centerW-3, centerH+3);
			cout << valueToChar(c.getValue());
			setCursorPos(centerW-3, centerH+2);
			cout << suitToChar(c.getSuit());
			break;
		case 1:
			setCursorPos(centerW-5, centerH-2);
			cout << valueToChar(c.getValue()) << suitToChar(c.getSuit());
			break;
		case 2:
			setCursorPos(centerW+2, centerH-3);
			cout << valueToChar(c.getValue());
			setCursorPos(centerW+2, centerH-2);
			cout << suitToChar(c.getSuit());
			break;
		case 3:
			setCursorPos(centerW+3, centerH+2);
			cout << valueToChar(c.getValue()) << suitToChar(c.getSuit());
			break;
		}
	}

	//Resets curson poistion and text color.
	setCursorPos(0, height);
	setColor(15,2);
}

char Interface::suitToChar(Suit s){
	switch(s){
	case Suit::clubs:		return (char)5;
	case Suit::spades:		return (char)6;
	case Suit::hearts:		return (char)3;
	case Suit::diamonds:	return (char)4;
	default:				return (char)176;
	}
}
char Interface::valueToChar(Value v){
	switch(v){
	case ace:	return 'A';
	case deuce: return '2';
	case trey:	return '3';
	case four:	return '4';
	case five:	return '5';
	case six:	return '6';
	case seven: return '7';
	case eight: return '8';
	case nine:	return '9';
	case ten:	return 'T';
	case jack:	return 'J';
	case queen: return 'Q';
	case king:	return 'K';
	default:	return (char)176;
	}
}

void Interface::setCursorPos(int x, int y){
	//Initialize the coordinates
	COORD coord = {x, y};
	//Set the position
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


/*	0 = Black       8		= Gray
    1 = Blue        9		= Light Blue
    2 = Green       A(10)	= Light Green
    3 = Aqua        B(11)	= Light Aqua
    4 = Red         C(12)	= Light Red
    5 = Purple      D(13)	= Light Purple
    6 = Yellow      E(14)	= Light Yellow
    7 = White       F(15)	= Bright White */
void Interface::setColor(int f, int b){
	int k = f + b*16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), k);
}