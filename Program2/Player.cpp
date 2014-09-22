#include "stdafx.h"
#include "Player.h"


Player::Player(){}
Player::Player(int playerNumber){}
void Player::playCard(const Card& c){}
void Player::receiveCard(const Card& c){}
void Player::collectTrick(const Trick& t){}
bool Player::hasCard(const Card& c){return true;}
bool Player::canPlayCard(const Card &c, const Trick& t){return true;}
int Player::getPlayerNumber(){return 0;}
int Player::getPlayerScore(){return 0;}
void Player::addToPlayerScore(int i){}
vector<Card> Player::getHand(){return Player::hand;}
