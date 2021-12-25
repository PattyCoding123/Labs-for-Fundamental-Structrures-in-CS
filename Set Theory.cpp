//==========================================================
//
// Title:      Lab 09 Set Theory
// Course:     CSC 1500
// Author:     Patrick Ducusin
// Date:       10/27/2021
// Description:
// We will be making a program that can display the correct 
// set outputs when given a set of numbers and the operation
// (such as finding the union or intersection between the two
// sets). For the inverse of a set, we will represent it with
// the ! symbol.
//==========================================================
#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
using namespace std; // To avoid writing std::

// placeHolderMaker will create a standardized dynamic array with size
// N(A). We want to standardized the sets that are passed as inputs via the method below...
int* placeHolderMaker(int originalArr[]) {
	/* Declare placeHolder array which will contain either a nonzero value or 0
	We want the placeHolder array to model the Universal Set array at each position, 
	but we will replace values at placeHolder[i] with 0 if the universalSet value
	at position i is not apart of the original array
	*/
	int universalSet[] = { 1,2,3,4,5,6,7,8,9,10 };
	int* placeHolder = new int[10];
	int j = 0;

	/* For loop that will fill each position of place holder. j controls the position we are checking in input array

	1. First, deal with a trivial case: if originalArr[j] = 0, set placeHolder[i] = 0 and increment j to move on to next value.
	2. If set1[j] != 0, check if originalArr[j] == universalSet[i]. If so, set placeHolder[i] = univeralSet[i] and increment j by 1.
	3. Else, set placeHolder[i] = 0 without incrementing j.
		Since arrays are sorted, we will eventually reach originalArr[j] = universalSet[i]

	*/
	for (int i = 0; i < 10; i++) {
		if (originalArr[j] == 0) {
			placeHolder[i] = 0;
			j++;
		}

		else if (originalArr[j] == universalSet[i]) {
			placeHolder[i] = universalSet[i];
			j++;
		}

		else
			placeHolder[i] = 0;
	}

	return placeHolder;
}

// inverse function will return a pointer to an array
// that represents the inverse of the input array
int* inverseOfSet(int set1[]) {
	int universalSet[] = { 1,2,3,4,5,6,7,8,9,10 };

	// standardize the input array using the placeHolderMaker function
	int* placeHolder = placeHolderMaker(set1);

	// Declare the inverseSet pointer that points to a dynamic array of size 10 
	int* inverseSet = new int[10];

	/* The for loop will check if placeHolder[i] != universalSet[i]. If they are not equal,
	then store universalSet[i] in the inverse set at position k.

	Otherwise, set inverseSet[i] = 0 as a place holder value. We will also do this for
	union sets and intersection sets where a value at position i will either be equal to
	0 or a nonzero value
	*/
	for (int i = 0; i < 10; i++) {
		if (placeHolder[i] != universalSet[i])
			inverseSet[i] = universalSet[i];
		else
			inverseSet[i] = 0;
	}

	// return the array
	return inverseSet;
}

// The unionOfTwoSets will return a pointer that points to a dynamic array that
// represents the union of the two sets
int* unionOfTwoSets(int set1[], int set2[]) {
	int universalSet[] = {1,2,3,4,5,6,7,8,9,10};

	// Declare two place holder sets (standardize the two input sets)
	// and the union set (as a pointer to a dynamic array)
	int* placeHolder1 = placeHolderMaker(set1);
	int* placeHolder2 = placeHolderMaker(set2);
	int* unionSet = new int[10];
	int j = 0, k = 0;


	/* This for loop will check to see if either placeHolder1[i] or placeHolder2[i] have 
	a nonzero value. If so, check which set has the nonzero value at position i and add
	that value to the union set. 

	Remember, because the sets are standardized so that they model the universal set A,
	we do can check if either array has a value at position i = universalSet[i] (nonzero)
	
	If both arrays are 0 at position i, then set unionSet[i] = 0
	
	*/
	for (int i = 0; i < 10; i++) {

		if (placeHolder1[i] || placeHolder2[i]) {

			if (placeHolder1[i] != 0)
				unionSet[i] = placeHolder1[i];

			else
				unionSet[i] = placeHolder2[i];
		}

		else
			unionSet[i] = 0;
	}

	// Return the array pointer 
	return unionSet;
}

// The intersectionOfTwoSets will return a pointer that points to a dynamic array that
// represents the intersection of the two sets
int* intersectionOfTwoSets(int set1[], int set2[]) {
	int universalSet[] = {1,2,3,4,5,6,7,8,9,10};

	// Declare two place holder sets (standardize the two input sets)
	// and the intersection set (pointer to a dynamic array)
	int* placeHolder1 = placeHolderMaker(set1);
	int* placeHolder2 = placeHolderMaker(set2);
	int* intersectionSet = new int[10];
	
	/* This for loop will check to see if placeHolder1[i] and placeHolder2[i] have
	the same value at position i. If so, set value of intersectionSet[i] = placeHolder1[i].
	
	If values do not match at position i, set intersectionSet[i] = 0 
	*/
	for (int i = 0; i < 10; i++) {
		if (placeHolder1[i] == placeHolder2[i]) {
			intersectionSet[i] = placeHolder1[i];
		}

		else
			intersectionSet[i] = 0;
	}

	// Return the pointer array
	return intersectionSet;
}

/* This function will check the input size of a set by taking the array
and finding how many nonzero values are in the array (it will ignore
the place holder value of 0)
*/
int findN(int inputSet[]) {
	// standardize input set
	int* set = placeHolderMaker(inputSet);

	int sizeCount = 0;
	for (int i = 0; i < 10; i++) {
		if (set[i] != 0) {
			sizeCount++;
		}
	}

	return sizeCount;
}

// Print function that displays the contents of a set
void printSet(int inputSet[]) {

	// standardize input set
	int* display = placeHolderMaker(inputSet);

	cout << "{ ";
	for (int i = 0; i < 10; i++) {
		if (display[i] != 0)
			cout << display[i] << " ";
	}

	cout << "}";
}

int main()
{
	/* Declare the 4 sets:
	A = the Universal Set
	B = the even numbers of the Universal Set
	C = the odd numbers of the Universal Set
	D = the prime numbers of the Universal Set
	*/
	int A[] = {1,2,3,4,5,6,7,8,9,10};
	int B[] = {2,4,6,8,10};
	int C[] = {1,3,5,7,9};
	int D[] = {1,2,3,5,7};

	/* We will use the printSet function to print out the sets of the problem and we will
	use the showN function to find the size of a set.

	Remember, when we make dynamic arrays, we can pass them like any other array
	into a function
	*/
	cout << "Problem 1.) A n D = ";
	printSet(intersectionOfTwoSets(A, D));

	cout << "\nProblem 2.) (B U C) n A = ";
	printSet(intersectionOfTwoSets(unionOfTwoSets(B,C), A));

	cout << "\nProblem 3.) (!C U C) n A = ";
	printSet(intersectionOfTwoSets(unionOfTwoSets(inverseOfSet(C),C), A));
	
	cout << "\nProblem 4.) A - D = ";
	printSet(inverseOfSet(D));

	cout << "\nProblem 5.) N(!A U (C U D)) = " << findN(unionOfTwoSets(inverseOfSet(A), unionOfTwoSets(C, D)));

	cout << "\nProblem 6.) D n C = ";
	printSet(intersectionOfTwoSets(D, C));

	cout << "\nProblem 7.) N(B n C) = " << findN(intersectionOfTwoSets(B, C));

	cout << "\nProblem 8.) A U B U C U D = ";
	printSet(unionOfTwoSets(unionOfTwoSets(A,B), unionOfTwoSets(C,D)));

	return 0;
}
