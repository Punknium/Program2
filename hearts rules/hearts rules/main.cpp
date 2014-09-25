#include <iostream>
using namespace std;

int main()
{
	cout << "This is the game: HEARTS" << endl
		<< "The object of the game is to be the player" << endl
		<< "with the lowest score." << endl << endl;

	cout << "The object of the game :" << endl
		<< "Players do not want to end up with tricks containing hearts" << endl
		<< "or the queen of spades." << endl << endl;

	cout << "The number of players for the game is 4." << endl;

	cout << "The players are dealt thirteen cards and" << endl
		<< "the player with the two of clubs goes first." << endl << endl;

	cout << "The rules of the game:" << endl
		<< "Passing the cards:" << endl
		<< "Before the hand is played, each player chooses three cards" << endl
		<< "and passes them to another player." << endl
		<< "Players first pass to the player to their right." << endl
		<< "Then the player passes the cards to the player to their left." << endl
		<< "Lastly, the player passes the cards to the player across from them." << endl
		<< "For the four round, the players don't pass at all and play with the" << endl
		<< "cards dealt to them." << endl << endl;

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

	cout << "T suit is equal to Tan of suit." << endl << endl;
	return 0;
}