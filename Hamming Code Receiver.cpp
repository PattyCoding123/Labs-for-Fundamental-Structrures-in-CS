//==========================================================
//
// Title:      Lab 10 Hamming Receiver
// Course:     CSC 1500
// Author:     Patrick Ducusin
// Date:       11/03/2021
// Description:
// We will be making a program that can take a 7 digit binary
// input and determine if there is an error bit and locate 
// where the error bit is. Additionally, it should be able
// to diaplay the correct code and the decimal message that the
// correct binary code translates to.
//==========================================================
#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
#include <cmath> // For math functions
using namespace std; // To avoid writing std::

// define hamming receiver 
void hammingCode(int num[]) {

	// Display original binary message
	cout << "Original message: ";
	for (int i = 0; i < 7; i++)
		cout << num[i];

	/* Declare security bit check:
	s1 checks itself, bit 3, bit 5, and bit 7
	s2 checks itself, bit 3, bit 6, and bit 7
	s4 checks itself, bit 5, bit 6, and bit 7
	*/ 
	int s1, s2, s4, errorBit;
	s1 = (num[0] + num[2] + num[4] + num[6]) % 2;
	s2 = (num[1] + num[2] + num[5] + num[6]) % 2;
	s4 = (num[3] + num[4] + num[5] + num[6]) % 2; 
	errorBit = s1 + 2 * s2 + 4 * s4;

	// If there is an error bit, display which bit was incorrect and change the bit in the array;
	if (errorBit != 0) {
		cout << "\nError bit = " << errorBit << endl;
		if (num[errorBit - 1])
			num[errorBit - 1] = 0;

		else
			num[errorBit - 1] = 1;

		// Display correct message in binary
		cout << "Correct Message: ";
		for (int i = 0; i < 7; i++)
			cout << num[i];
		cout << endl;
	}

	else
		cout << "\nNo error bit detected!" << endl;
	 
	// Calculate the decimal message of the array by utilizing the bits in slots 3,5,6, and 7
	// and the math.pow function
	int decimalMsg = num[2] * pow(2, 3) + num[4] * pow(2, 2) + num[5] * pow(2, 1) + num[6] * pow(2, 0);

	// Displary correct message in decimal
	cout << "Decimal Message = " << decimalMsg << endl << endl;
}

int main() {

	// Each of these arrays represents the input binary message. Each positition in the array represents a bit slot.
	int problem1[] = {1,1,1,1,1,1,1};
	int problem2[] = {0,0,0,1,1,1,1};
	int problem3[] = {0,1,1,1,1,0,0};
	int problem4[] = {0,1,0,1,0,1,0};
	int problem5[] = {1,1,0,0,1,1,0};
	
	cout << "Problem 1" << endl;
	cout << "-------------" << endl;
	hammingCode(problem1);

	cout << "Problem 2" << endl;
	cout << "-------------" << endl;
	hammingCode(problem2);

	cout << "Problem 3" << endl;
	cout << "-------------" << endl;
	hammingCode(problem3);

	cout << "Problem 4" << endl;
	cout << "-------------" << endl;
	hammingCode(problem4);

	cout << "Problem 5" << endl;
	cout << "-------------" << endl;
	hammingCode(problem5);
}