//==========================================================
//
// Title:      Base Converter
// Course:     CSC 1500
// Lab Number: 07
// Author:     Patrick Ducusin
// Date:       09/29/2021
// Description:
//   This program will take numbers in base 10 and convert
// them to other numbers of different bases
//
//==========================================================
#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
using namespace std; // So "std::cout" may be abbreviated to "cout"

// the function will convert a decimal number to binary
void convertToBinary(int dec) {
	string reverseBinNum = "";
	int temp = dec; // temp is the number we will keep dividing by the base
	int remainder;

	while (temp > 0) { // the while loop will add the remainders to the string until temp reaches 0 
		remainder = temp % 2; // modulo number by 2
		reverseBinNum = reverseBinNum + to_string(remainder); // add remainder to string
		temp /= 2; // divide by 2
	}

	// display number conversion
	cout << setw(10) << left << "Decimal" << setw(5) << left << "->" << left << "Binary" << endl;
	cout << setw(10) << left << dec << setw(5) << left << "->";

	// this for loop will print the conversion backwards since the the Least Significant Remainder was gathered first
	for (int i = reverseBinNum.length(); i >= 0; i--) { 
		cout << reverseBinNum[i];
	}

	cout << endl << endl;
}

void convertToBase3(int dec) {
	string reverseNum = "";
	int temp = dec;
	int remainder;

	while (temp > 0) {
		remainder = temp % 3;
		reverseNum = reverseNum + to_string(remainder);
		temp /= 3;
	}

	cout << setw(10) << left << "Decimal" << setw(5) << left << "->" << left << "Base 3" << endl;
	cout << setw(10) << left << dec << setw(5) << left << "->";
	for (int i = reverseNum.length(); i >= 0; i--) {
		cout << reverseNum[i];
	}

	cout << endl << endl;
}

void convertToBase6(int dec) {
	string reverseNum = "";
	int temp = dec;
	int remainder;

	while (temp > 0) {
		remainder = temp % 6;
		reverseNum = reverseNum + to_string(remainder);
		temp /= 6;
	}

	cout << setw(10) << left << "Decimal" << setw(5) << left << "->" << left << "Base 6" << endl;
	cout << setw(10) << left << dec << setw(5) << left << "->";
	for (int i = reverseNum.length(); i >= 0; i--) {
		cout << reverseNum[i];
	}

	cout << endl << endl;
}

void convertToBase8(int dec) {
	string reverseNum = "";
	int temp = dec;
	int remainder;

	while (temp > 0) {
		remainder = temp % 8;
		reverseNum = reverseNum + to_string(remainder);
		temp /= 8;
	}

	cout << setw(10) << left << "Decimal" << setw(5) << left << "->" << left << "Base 8" << endl;
	cout << setw(10) << left << dec << setw(5) << left << "->";
	for (int i = reverseNum.length(); i >= 0; i--) {
		cout << reverseNum[i];
	}

	cout << endl << endl;
}

void convertToHexa(int dec) {
	string reverseNum = "";
	int temp = dec;
	int remainder;

	
	while (temp > 0) {
		remainder = temp % 16;
		// the switch case will catch numbers greater than 9 and convert them to the correct 
		// representation in Hexadecimal
		switch (remainder) {
		case 10:
			reverseNum += 'A';

		case 11:
			reverseNum += 'B';

		case 12:
			reverseNum += 'C';

		case 13:
			reverseNum += 'D';

		case 14:
			reverseNum += 'E';

		case 15:
			reverseNum += 'F';

		default:
			reverseNum = reverseNum + to_string(remainder);
		}
		
		temp /= 16;
	}

	cout << setw(10) << left << "Decimal" << setw(5) << left << "->" << left << "Hexadecimal" << endl;
	cout << setw(10) << left << dec << setw(5) << left << "->";
	for (int i = reverseNum.length(); i >= 0; i--) {
		cout << reverseNum[i];
	}
	cout << endl << endl;;
}


int main()
{
	convertToBinary(15);
	convertToHexa(38);
	convertToBase6(54);
	convertToBase8(19);
	convertToBase3(27);
}