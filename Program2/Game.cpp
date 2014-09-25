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
int Game::totalScore[] = {0,0,0,0};

void Game::startGame(){
	interfase.drawRules();
	interfase.drawBoard();
	interfase.drawHands();
	//Sets up the players
	for(int i = 0; i<4; i++){
		players[i] = Player(i);
		interfase.drawScore(players[i], totalScore[i]);
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

	//Finds the player with the lowest score and says they are the winner
	int lowestScore = 26;
	vector<int> winners;
	for(int i=0;i<4;i++){
		if(players[i].getPlayerScore() == lowestScore) 
			winners.push_back(i);
		if(players[i].getPlayerScore() < lowestScore){
			winners.clear();
			winners.push_back(i);
			lowestScore = players[i].getPlayerScore();
		}
	}
	string output;
	if(winners.size() < 2){
		 output = "The winner is Player " + to_string(winners.at(0));
	}else{
		output = "The winners are Player " + to_string(winners.at(0));
		for(int i = 1;i < winners.size();i++){
			output += ", Player " + to_string(winners.at(i));
		}
	}
	interfase.printError(output.c_str());

	//Handles shoting the moon
	for(int i=0;i<4;i++){
		if(players[i].getPlayerScore() == 26){
			players[i].addToPlayerScore(-26);
			string output = "The moon was shot by Player " + to_string(i);
			interfase.printError(output.c_str());
			for(int j=0;j<4;j++){
				if(i != j){
				players[j].addToPlayerScore(26);
				}
			}
		}
	}

	//Adds each player's score to their total score.
	for(int i=0;i<4;i++){
		totalScore[i] += players[i].getPlayerScore();
	}

	//Redraws the scores
	for(int i = 0; i<4; i++){
		interfase.drawScore(players[i], totalScore[i]);
	}

	//Asks if they want to play again.
	interfase.printText("Play again?(y/n) ");
	char input;
	cin.clear();
	cin >> input;
	input = tolower(input);
	if(input == 'y') startGame();
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
		interfase.drawScore(players[i], totalScore[i]);
		askForCard(players[i], t);
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
	cin.sync();
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