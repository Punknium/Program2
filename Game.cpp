/*
  File:			Game.cpp
  Author:		Ryder Smith
  Course:		COMP 220, Computer Programming II
  Date:			20 September 2014
  Description:  This class handles the game.
*/

#include "stdafx.h"
#include "Game.h"
#include "Deck.h"
#include "Player.h"

void Game::startGame(){
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

}