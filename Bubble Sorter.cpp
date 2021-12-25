//==========================================================
//
// Title:      CSC 1500 Lab 07 Bubble Sort
// Course:     CSC 1500
// Author:     Patrick Ducusin
// Date:       10/11/2021
// Description:
//  We will be making a program that will sort an array
// of objects using Bubble Sort. Additionally, our program
// will keep track of the operations needed to completely sort
// the array.
//==========================================================
#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
using namespace std; // To avoid writing std::

void printList(int arr[], int listSize) {
	for (int i = 0; i < listSize; i++) {
		cout << arr[i];
		if (i != listSize - 1)
			cout << ", ";
	}
	cout << "]" << endl;

}

void bubbleSort(int arr[], int n) {
	// declare swap and totalOperations counter 
	int swaps = 1;
	int totalOperations = 0;

	// print out unorganized list 
	cout << "The unorganized list: [";
	printList(arr, n);

	// In order for the list to be done sorting, the algorithm
	// must go through one loop with 0 swaps
	while (swaps != 0)
	{
		swaps = 0;
		for (int i = 0; i < n - 1; i++) {
			int j = i + 1; // next position in array

			// count one operation for checking list[i] and list[j]
			totalOperations++;
			if (arr[i] > arr[j]) {
				swaps++; // increase swap counter
				totalOperations += 3;
				int temp = arr[j]; // we will first assign a temporary variable to be equal the value of list[j]
				arr[j] = arr[i]; // next, we will assign list[j] = list[i] (swapping values)
				arr[i] = temp; // finally, set list[i] = temp value that held the initial value of list[j]

			}
		}
	}

	// print out organized list 
	cout << "The organized list: [";
	printList(arr, n);
	
	// print out total number of operations
	cout << "Total operations = " << totalOperations << endl;
}

int main()
{
	// declare size variable
	int size;

	cout << "List 1" << endl;
	cout << "--------------------------" << endl;
	int list1[] = {1, 3, 7, 5, 2, 4, 6, 8, 9, 10};
	size = sizeof(list1) / sizeof(list1[0]);
	bubbleSort(list1, size);

	cout << "\nList 2" << endl;
	cout << "--------------------------" << endl;
	int list2[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	size = sizeof(list2) / sizeof(list2[0]);
	bubbleSort(list2, size);

	cout << "\nList 3" << endl;
	cout << "--------------------------" << endl;
	int list3[] = {1, 10, 2, 9, 3, 8, 4, 7, 5, 6};
	size = sizeof(list3) / sizeof(list3[0]);
	bubbleSort(list3, size);

}
