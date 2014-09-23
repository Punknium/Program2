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

Player Game::players[4];
int Game::leadPlayer;
Interface Game::interfase;

void Game::startGame(){
	interfase.drawBoard();
	interfase.drawHands();
	interfase.hideHands();
	//Sets up the players
	for(int i = 0; i<4; i++){
		players[i] = Player(i);
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
	//Sets up the trick for the round
	Trick t(leadPlayer);

	//Prompts each user for a card to be played.
	int i = leadPlayer;
	do{
		showHand(players[i]);
		askForCard(players[i], t);
		i++;
		if(i==4)i=0;
		interfase.hideHands();
	}while(i != leadPlayer && i < 5);
	
	leadPlayer = t.getCollector();
	if(leadPlayer){
		if(leadPlayer != 0) players[0].addToPlayerScore(26);
		if(leadPlayer != 1) players[1].addToPlayerScore(26);
		if(leadPlayer != 2) players[2].addToPlayerScore(26);
		if(leadPlayer != 3) players[3].addToPlayerScore(26);
	}else{
		players[leadPlayer].collectTrick(t);
	}

}

void Game::showHand(Player &p){
	for(int i = 0;i < p.getHand().size();i++){
		interfase.drawCard(p.getHand()[i], p.getPlayerNumber(), i);
	}
}

void Game::askForCard(Player &p, Trick &t){
	//Prompt for card
	//TODO: list cards
	Card toBeUsed;
	if(p.canPlayCard(toBeUsed, t)){
		p.playCard(toBeUsed);
		t.addCard(p.getPlayerNumber(), toBeUsed);
		interfase.drawCard(toBeUsed, 4, p.getPlayerNumber());
	}else{
		//Print error
		askForCard(p, t);
	}
}