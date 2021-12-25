//==========================================================
//
// Title:      Lab 14 The Heap Sorter
// Course:     CSC 1500
// Author:     Patrick Ducusin
// Date:       11/29/2021
// Description:
// We will be making a program that will allow the user to 
// enter in values that will be placed into an arry in
// max heap style. Then, we will implement Heap Sort in order
// to sort the array.
// 
//==========================================================
#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
using namespace std; // To avoid writing std::

// Function to print array
void printArray(int arr[], int size) {
	cout << "[ ";
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << "]\n";
}


// This function will take take an array of values and put it into
// max-heap form with the use of recursion. The inputs are the array and the index. Since reducing the index going up the tree, we can recursively
// call this function to keep doing a max-heap on the array until it reaches the root by "Up-Heaping"
void maxHeap(int arr[], int i) {
	// Declare max variable to be parent index
	int parent = (i - 1) / 2;

	// If value of i is larger than parent, then do a swap
	if (parent >= 0 && arr[i] > arr[parent])
	{
		swap(arr[i], arr[parent]);

		// Recursively call function to continue Up-Heaping using the parent variable
		// As this will check if the new parent is greater than its parent (Up-Heaping)
		maxHeap(arr, parent);
	}
	
}

// This function will do a Heap Sort using the Max-Heap Array
void HeapSort(int arr[], int size) {
	
	// begin by doing creating a max-heap array with the function maxHeap
	for (int i = 0; i < size; i++)
	{
		maxHeap(arr, i);
	}

	cout << "\nMax-Heap Array:\n";
	printArray(arr, size);

	// Then, begin swapping each index at the end of the array to the top
	// And cut the swapped index from being altered
	for (int i = size - 1; i >= 0; i--)
	{
		int parent = 0;
		swap(arr[i], arr[parent]);

		// Begin downsifting by comparing the root to its children.
		// Swap children and parent if children have a greater value
		// We will make sure to avoid the index that was already swapped.
		while (parent < i)
		{
			// Declare children indices and maxChild variable
			int child_1 = (2 * parent) + 1;
			int child_2 = (2 * parent) + 2;
			int maxChild;

			// If we hit the index that we swapped, do some checks
			if (child_1 >= i || child_2 >= i)
			{
				// set maxChild to whichever index that isn't the swapped index, break if we cannot do so
				if (child_1 < i)
					maxChild = child_1;
				else if (child_2 < i)
					maxChild = child_2;
				else
					break;
			}

			// Else, compare the value of the two children, and set the higher one
			// as the maxChild
			else if (arr[child_1] >= arr[child_2])
				maxChild = child_1;
			else
				maxChild = child_2;


			// swap values of maxChild and parent if maxChild is greater
			// and set new parent index to be the maxChild
			if (arr[maxChild] > arr[parent])
			{
				swap(arr[maxChild], arr[parent]);
				parent = maxChild;
			}
			
			// If parent is greater than maxChild, break the while loop
			else
				break;
		
		}

	
	}

	cout << "\nSorted Array using Heap Sort:\n";
	printArray(arr, size);

}

int main()
{
	int size = 7;
	int problem[7];

	cout << "Enter Seven Values\n";
	cout << "========================\n";
	for (int i = 0; i < size; i++) {
		cout << "Enter value: ";
		cin >> problem[i];
	}

	HeapSort(problem, size);

}