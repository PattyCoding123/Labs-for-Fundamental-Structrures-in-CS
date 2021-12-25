//==========================================================
// Title:      Lab 12 Black Jack
// Course:     CSC 1500
// Author:     Patrick Ducusin
// Date:       11/17/2021
// Description:
// We will be making a program that allows the user to play a
// game of Black Jack (21). The program will deal 2 random cards
// from one suit. Then, the program must calculate the probability
// that the third card will give a score under 21. It will then ask 
// the user if they want to pick the extra card, and if the user
// picks yes, it will display the result.
//==========================================================
#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
using namespace std; // To avoid writing std::

// Function to determine values of a card based
int determineCardVal(string card) {
	// If the input card is J, Q, or K, return as 10 points
	if (card == "J" || card == "Q" || card == "K")
		return 10;

	// If input
	else if (card == "A") 
		return 11;

	else
		return stoi(card);
}

// Function to determine final sum based off three card value
int determineScore(int card_1, int card_2, int card_3) {
	int sum = card_1 + card_2 + card_3;

	// if the sum is greater than 21, AND one of the cards was an Ace = 11,
	// subtract 10 from the final sum to indicate the Ace switched to 1 point
	if ((sum > 21) && (card_1 == 11 || card_2 == 11 || card_3 == 11))
		return sum - 10;

	else
		return sum;
}

// Function to play Black Jack
void blackJack() {
	// Welcome Message
	cout << "Welcome to Black Jack!!" << endl;
	cout << "================================" << endl;

	// Declare a suit of cards array and sum variable
	string suit[13] = { "2", "3", "4", "5","6", "7", "8", "9", "10", "J", "Q", "K", "A" };
	int sum = 0;

	// We want to randomize the first card (the index of the array)
	srand((unsigned)time(NULL));
	int firstCard = rand() % 13;
	int secondCard = firstCard;

	// Randomize second card until it doesn't match the first card
	while (secondCard == firstCard) {
		srand((unsigned)time(NULL));
		secondCard = rand() % 13;
	}

	// Display first two cards
	cout << "Your first card: " << suit[firstCard] << endl;
	cout << "Your second card: " << suit[secondCard] << endl;

	// Begin finding values using user-defined function
	int firstCardVal = determineCardVal(suit[firstCard]);
	int secondCardVal = determineCardVal(suit[secondCard]);
	
	// Declare success counter
	int success = 0;

	// Finding the probability:
	cout << "\nPossible Scores with the Remaining Cards" << endl;
	cout << "---------------------------------------------------" << endl;
	for (int i = 0; i < 13; i++) {
		int cardVal;
		int possibleSum;
		if (i != firstCard && i != secondCard) {
			cardVal = determineCardVal(suit[i]);

			possibleSum = determineScore(firstCardVal, secondCardVal, cardVal);
			cout << "Possible score with " << suit[i] << ": " << possibleSum << endl;;

			if (possibleSum <= 21)
				success++;
		}
	}

	// Calculate probability of cards that keep our score under or at 21 (there are only 11 we can choose from)
	double probOfSuccess = (double) success / 11.0;
	cout << "\nOut of the 11 cards that remain, " << success << " will give you a winning score!" << endl;
	
	// Display whether the user has a good chance at winning (must have over 50% chance)
	if (probOfSuccess > 0.5)
		cout << "\nYou have a good chance of winning! (" << setprecision(4) << probOfSuccess * 100.0 << "% chance)" << endl;

	else
		cout << "\nYou do not have a good chance of winning! (" << setprecision(4) << probOfSuccess * 100.0 << "% chance)" << endl;

	// Get user input
	char choice;
	cout << "Do you want to draw another card? (type y for yes): ";
	cin >> choice;

	// Display results for a third car pool
	if (choice == 'y') {

		// Randomize third card until it doesn't match the first or third card
		int thirdCard;
		srand((unsigned)time(NULL));
		thirdCard = rand() % 13;

		while (thirdCard == firstCard || thirdCard == secondCard) {
			srand((unsigned)time(NULL));
			thirdCard = rand() % 13;
		}
		
		// Determine the value of the third card along with the sum
		// of all three cards added together
		int thirdCardVal = determineCardVal(suit[thirdCard]);
		sum = determineScore(firstCardVal, secondCardVal, thirdCardVal);

		// Display card and results of the game
		cout << "\nYour third card: " << suit[thirdCard] << endl;
		if (sum <= 21) {
			cout << "Congratulations, you won the game!" << endl;
			cout << "Final score: " << sum << endl;
		}

		else {
			cout << "Sorry, you lost the game!" << endl;
			cout << "Final score: " << sum << endl;
		}

	}

	// If user does not continue to play, display current score with two cards and end
	else {
		cout << "Final score: " << determineScore(firstCardVal, secondCardVal, 0) << endl;
		cout << "Ok, goodbye!" << endl;
	}
		
		
}

int main() 
{
	blackJack();
}
