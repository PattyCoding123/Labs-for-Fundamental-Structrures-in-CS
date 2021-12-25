//==========================================================
//
// Title:      Lab 08 Brute Force Code Cracker
// Course:     CSC 1500
// Author:     Patrick Ducusin
// Date:       10/26/2021
// Description: 
// We will be making a Brute Force Code Cracker. Essentially,
// we will have a function whose input is an encryped text.
// Then, the function will check all 26 possible shift keys
// and display them to the user.
//==========================================================
#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
using namespace std; // To avoid writing std::

void codeCracker(string cipher) {
	/* declare the following variables: 
	- a string variable to hold the decrypted message
	- a variable to hold the ASCII value of the current character
	Also, declare constant values for the highest and lowest values
	of the lower case and upper case letters in the ASCII table
	*/
	string decryptedMsg;
	int letterASCII = 0;
	const int lowerCaseMin = 97;
	const int lowerCaseMax = 122;
	const int upperCaseMin = 65;
	const int upperCaseMax = 90;
	
	// Display the current cipher we are trying to decrypt
	cout << "Cipher: " << cipher << endl << endl;

	// this for loop will control the shift-key value that we will use to decrypt
	for (int i = 1; i <= 26; i++) {
		
		// initialize the decryptMsg variable as an empty string
		decryptedMsg = "";

		// this for loop will control the character we are currently at in the cipher
		for (int j = 0; j < cipher.length(); j++) {
			
			// we will decrypt the character IF it is not a space
			if (cipher[j] != ' ') {
				
				// store the ASCII value of the current character
				letterASCII = (int) cipher[j];

				/* FIRST, check if the character is an UPPER case letters since 
				they have lower ASCII values than lower case letter */ 
				if (letterASCII <= upperCaseMax) { 

					/* Add the shift - key to the letterASCII value. If letterASCII value exceeds range of
					upper case letters, reset to the minimum upper case ASCII value - 1 and add the modulo
					between the letterASCII value and the upperCaseMax */
					letterASCII += i;

					if (letterASCII > upperCaseMax)
						letterASCII = (upperCaseMin - 1) + (letterASCII % upperCaseMax);

				}

				/* If character isn't upper case, continue the same procedures stated above for decrypting
				the lower case letters */ 
				else { 
					letterASCII += i;

					if (letterASCII > lowerCaseMax)
						letterASCII = (lowerCaseMin - 1) + (letterASCII % lowerCaseMax);
				}

				// add decrypted character to decrypted message
				decryptedMsg = decryptedMsg + (char)letterASCII;
			}

			// if we were dealing with a space, skip character decryption and just add space to decrypted message
			else { 
				decryptedMsg = decryptedMsg + cipher[j];
			}
		}

		// at the end of the J for loop, print out the decrypteed message associated with the shift-key that the loop used
		cout << "Shift-Key[" << i << "]" << " = " << decryptedMsg << endl;
	}
}

int main() {
	// call the codeCracker function to decrypt cipher
	codeCracker("Whvwlqj wkh Vbvwhp");
}