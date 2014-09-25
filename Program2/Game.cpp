/*
  File:			Game.cpp
  Author:		Ryder Smith
  Course:		COMP 220, Computer Programming II
  Date:			20 September 2014
  Description:  This class handles the game.
*/

#include "stdafx.h"
#include "Game.h"
#include "Interface.h"
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::to_string;

Player Game::players[4];
int Game::leadPlayer;
Interface Game::interfase;

void Game::startGame(){
	interfase.drawBoard();
	interfase.drawHands();
	//Sets up the players
	for(int i = 0; i<4; i++){
		players[i] = Player(i);
		interfase.drawScore(players[i]);
	}
	//Readys the deck and shuffles it
	Deck d;
	d.shuffleDeck();
	//Deals the cards to the players
	for(int i = 0; i<13; i++){
		for(int j = 0; j<4; j++){
			d.drawCard(players[j]);
		}
	}
	//Finds lead player
	for(int i = 0; i<4; i++){
		if(players[i].hasCard(Card())){
			leadPlayer = i;
		}
	}
	//Runs through all of the rounds
	for(int i = 0; i < 13; i++){

		startRound();
	}
}

void Game::startRound(){
	interfase.hideHands();
	interfase.hideTrick();
	//Sets up the trick for the round
	Trick t(leadPlayer);

	//Prompts each user for a card to be played.
	int i = leadPlayer;
	do{
		showHand(players[i]);
		askForCard(players[i], t);
		interfase.drawScore(players[i]);
		i++;
		if(i==4)i=0;
		interfase.hideHands();
	}while(i != leadPlayer && i < 5);
	
	leadPlayer = t.getCollector();
	players[leadPlayer].collectTrick(t);

	interfase.clearError();
	string output = "Player " + to_string(leadPlayer) + " has collected the trick with a score of " + to_string(t.calculatePoints()) + ".\n";
	interfase.printText(output.c_str());
	system("pause");
	interfase.clearError();
}

void Game::showHand(Player &p){
	for(int i = 0;i < p.getHand().size();i++){
		interfase.drawCard(p.getHand()[i], p.getPlayerNumber(), i);
	}
}

void Game::askForCard(Player &p, Trick &t){
	//Prompt for card
	//system("pause");   
	//TODO: list cards
	int selection = 0;

	interfase.printText("Please select a card (1-13): ");
	cin.clear();
	cin >> selection;
	selection--;

	Card toBeUsed;
	if(selection>=0 && selection<=p.getHand().size()-1) toBeUsed = p.getHand().at(selection);

	string output = "Selected card: " + toBeUsed.name();
	interfase.printError(output.c_str());
	
	if(p.canPlayCard(toBeUsed, t) && (selection>=0 && selection<=p.getHand().size()-1)){
		p.playCard(toBeUsed);
		t.addCard(p.getPlayerNumber(), toBeUsed);
		interfase.drawCard(toBeUsed, 4, p.getPlayerNumber());
	}else{
		interfase.printError("Choose a different card!");
		askForCard(p, t);
		interfase.clearError();
	}
}