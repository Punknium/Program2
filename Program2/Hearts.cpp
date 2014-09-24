// Program2.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "Game.h"
#include "Interface.h"

int main(){	
	//Game::startGame();
	Interface i;
	i.drawBoard();
	i.drawHands();
	system("pause");
	return 0;
}

