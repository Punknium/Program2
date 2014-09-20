// Program2.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
//#include "Game.h"
#include "Card.h"

using std::cout;

int main(){
	//Game::startGame();
	Card c;
	cout << c.name();
	system("pause");
	return 0;
}

