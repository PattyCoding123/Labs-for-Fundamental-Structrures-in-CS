#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
using namespace std; // So "std::cout" may be abbreviated to "cout"


bool implies(bool var1, bool var2) { //function to do implies
	return !(var1 and !var2);
}



int main()
{
	//initialize the boolean arrays, answer variable, and constants
	string result;
	const int COL_WIDTH1 = 5;
	const int COL_WIDTH2 = 8;
	int invalidCounter = 0; // to check how many invalid statements there are
	bool X; // If someone has a rocket, implies they are an astronaut
	bool Y; // If someone is an astronaut, that implies they are highly trained
	bool Z; // If someone is highly trained, that implies that they are educated
	bool conclusion; // If a Person is Educated, that implies they have a rocket
	bool invalidInput[16][4]; // to store invalid inputs

	// The following are the boolean arrays for the 4 variables
	bool R[16] = {false, false, false, false, false, false, false, false, // Has a rocket variable
	true, true, true, true, true, true, true, true};

	bool A[16] = {false, false, false, false, true, true, true, true, // Is an astronaut variable
	false, false, false, false, true, true, true, true};

	bool HT[16] = {false, false, true, true, false, false, true, true, // Highly Trained variable
	false, false, true, true, false, false, true, true};

	bool E[16] = {false, true, false, true, false, true, false, true, // Educated Variable
	false, true, false, true, false, true, false, true};

	//headers
	cout << setw(COL_WIDTH1) << left << "R" << setw(COL_WIDTH1) << "A" << setw(COL_WIDTH1) << "HT" << setw(COL_WIDTH1) << "E"
		<< setw(COL_WIDTH2) << "R->A" << setw(COL_WIDTH2) << "A->HT" << setw(COL_WIDTH2) << "HT->E" << setw(COL_WIDTH2) << 
		"E->R" << "Valid?" << endl;

	cout << "-------------------------------------------------------------" << endl;

	for (int i = 0; i < 16; i++) {
		X = implies(R[i], A[i]);
		Y = implies(A[i], HT[i]);
		Z = implies(HT[i], E[i]);
		conclusion = implies(E[i], R[i]);
		if (implies((X && Y && Z), conclusion))
			result = "VALID";
		else { // we will add the invalid inputs into the array and then increase the counter
			result = "INVALID";
			invalidInput[invalidCounter][0] = R[i];
			invalidInput[invalidCounter][1] = A[i];
			invalidInput[invalidCounter][2] = HT[i];
			invalidInput[invalidCounter][3] = E[i];
			invalidCounter++;
		}
	
		cout << setw(COL_WIDTH1) << left << R[i] << setw(COL_WIDTH1) << A[i] << setw(COL_WIDTH1) << HT[i] << setw(6) << E[i]
			<< setw(COL_WIDTH2) << X << setw(COL_WIDTH2) << Y << setw(COL_WIDTH2) << Z << setw(7) <<
			conclusion << result << endl;
	}

	if (invalidCounter > 0) { // if there are invalid inputs, we will display them to the user
		cout << "\nThe statement is INVALID" << endl;
		cout << "Inputs that invalidate the statement:" << endl << endl;
		cout << setw(COL_WIDTH1) << left << "R" << setw(COL_WIDTH1) << "A" << setw(COL_WIDTH1) << "HT" << setw(COL_WIDTH1) << "E" << endl;
		cout << "--------------------" << endl;

		for (int i = 0; i < invalidCounter; i++) {
			cout << setw(COL_WIDTH1) << left << invalidInput[i][0] << setw(COL_WIDTH1) << invalidInput[i][1]
				<< setw(COL_WIDTH1) << invalidInput[i][2] << setw(6) << invalidInput[i][3] << endl;
		}
	}

	else
		cout << "\nThe statement is VALID" << endl;
}
