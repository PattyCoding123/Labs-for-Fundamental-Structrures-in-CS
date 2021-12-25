//==========================================================
//
// Title:      Lab 11 Hamming Transmitter
// Course:     CSC 1500
// Author:     Patrick Ducusin
// Date:       11/03/2021
// Description:
// We will be making a program that can take a decimal number
// and construct the correct 7-digit binary hamming code. We 
// will then display the original decimal number along with the
// correct number
//==========================================================
#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
using namespace std; // To avoid writing std::

void displayHammingCode(int bits[]) {
	for (int i = 0; i < 7; i++)
		cout << bits[i];
	cout << endl;
}

void hammingTransmitter(int dec) {
	int hammingCode[7]; // Store bits for 3,5,6,7
	int temp = dec; // temp is the number we will keep dividing by the base
	int remainder;
	int i = 6; // controls the index we are at for while loop

	
	remainder = temp % 2;
	hammingCode[6] = remainder;
	temp /= 2;

	remainder = temp % 2;
	hammingCode[5] = remainder;
	temp /= 2;

	remainder = temp % 2;
	hammingCode[4] = remainder;
	temp /= 2;

	remainder = temp % 2;
	hammingCode[2] = remainder;
	
	// declare string variables for the security bits
	int s1, s2, s4;
	s1 = (hammingCode[2] + hammingCode[4] + hammingCode[6]) % 2;
	s2 = (hammingCode[2] + hammingCode[5] + hammingCode[6]) % 2;
	s4 = (hammingCode[4] + hammingCode[5] + hammingCode[6]) % 2;

	// Store values into binNum array
	hammingCode[0] = s1;
	hammingCode[1] = s2;
	hammingCode[3] = s4;

	displayHammingCode(hammingCode);
}

int main()
{
	cout << "Problem 1\n";
	cout << "---------------------\n";
	cout << "Original Decimal: 15\n";
	cout << "Hamming Code: ";
	hammingTransmitter(15);
	
	cout << "\nProblem 2\n";
	cout << "---------------------\n";
	cout << "Original Decimal: 7\n";
	cout << "Hamming Code: ";
	hammingTransmitter(7);

	cout << "\nProblem 3\n";
	cout << "---------------------\n";
	cout << "Original Decimal: 12\n";
	cout << "Hamming Code: ";
	hammingTransmitter(12);

	cout << "\nProblem 4\n";
	cout << "---------------------\n";
	cout << "Original Decimal: 2\n";
	cout << "Hamming Code: ";
	hammingTransmitter(2);

	cout << "\nProblem 5\n";
	cout << "---------------------\n";
	cout << "Original Decimal: 6\n";
	cout << "Hamming Code: ";
	hammingTransmitter(6);

	return 0;
}

