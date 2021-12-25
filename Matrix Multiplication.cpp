//==========================================================
//
// Title:      Lab 13 Matrix Multiplication
// Course:     CSC 1500
// Author:     Patrick Ducusin
// Date:       11/18/2021
// Description:
// We will be making a program that will allow the user to 
// perform matrix multiplication with either a scalar or 
// another matrix. The functions will have to perform some
// checks to make sure that the two matrices can be multiplied
// together.
//==========================================================
#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
#include <cmath> // For math functions
#include <vector>
using namespace std; // To avoid writing std::

// printMatrix that prints the matrix
void printMatrix(vector<vector<int>> matrix) { // input is a 2-dimensional vector (vector that contains vectors of integers)
	// Find the number of rows by using the size method on the main matrix
	int rows = matrix.size();

	// Find the number of columns by using the size method on one of the vector ELEMENTS inside the main vector
	int columns = matrix[0].size();

	// For loop will go through each row's column and print out the result
	for (int m = 0; m < rows; m++) {
		for (int n = 0; n < columns; n++) {
			cout << setw(4) << left << matrix[m][n];

		}
		
		// Separate each row for clarity and readability
		cout << endl << endl;
	}
}

// scalarMultiplication will calculate a matrix with scalar multiplication
// and will display the final result after
void scalarMultiplication(int c, vector<vector<int>> matrix) {
	// // Find the number of rows by using the size method on the main matrix
	int rows = matrix.size();

	// Find the number of columns by using the size method on one of the vector ELEMENTS inside the main vector
	int columns = matrix[0].size();
	cout << "\nHello, and Welcome to Scalar Matrix Multiplication!" << endl;
	cout << "Performing Scalar Multiplication on Matrix with c = " << c << endl << endl;


	// For loop will go through each row's column and access the element at [m][n]
	for (int m = 0; m < rows; m++)
		for (int n = 0; n < columns; n++) 
			// Multiply the matrix element at [m][n] with the scalar c
			matrix[m][n] = c * (matrix[m][n]); 

	// Display the product matrix
	printMatrix(matrix);
	
	cout << "All Done!" << endl;
	cout << "=========================" << endl;
}


void matrixMultiplication(vector<vector<int>> matrix_1, vector<vector<int>> matrix_2) {
	// Find the rows of each matrix by doing the size method on the vector
	// Find the columns of each matrix by doing the size method on one of the elements
	int rowMatrix_1 = matrix_1.size();
	int columnMatrix_1 = matrix_1[0].size();
	int rowMatrix_2 = matrix_2.size();
	int columnMatrix_2 = matrix_2[0].size();
	
	// If column size of first matrix does not match the row size of the second matrix
	// send error message and terminate the program
	if (columnMatrix_1 != rowMatrix_2) {
		cout << "ERROR: Invalid dimensions of matrix 1 and matrix 2" << endl;
		return;
	}


	else {
		cout << "\nHello, and Welcome to Matrix Multiplication!" << endl;
		cout << "Performing Matrix Multiplication..." << endl << endl;

		// Create a 2-dimensional vector with rows = rows of matrix 1
		// and columns = columns of matrix 2
		vector<int> productColumn(columnMatrix_2);
		vector<vector<int>> productMatrix(rowMatrix_1, productColumn);

		// These series of for loops will access the elements of matrix_1 at [i][n]
		// and the elements of matrix_2 at [n][j]
		for (int i = 0; i < rowMatrix_1; i++)
		{
			for (int j = 0; j < columnMatrix_2; j++)
			{
				// declare a sum variable for the element of product matrix
				// at [i][j]
				int sum = 0;

				// Add the product of matrix_1[i][n] * matrix_2[n][j] to the sum
				for (int n = 0; n < columnMatrix_1; n++)
				{
					sum = sum + (matrix_1[i][n] * matrix_2[n][j]);
				}
				// Initialize element of product matrix at [i][j] with sum
				productMatrix[i][j] = sum;
			}
		}

		// Display results
		printMatrix(productMatrix);
		
		cout << "All Done!" << endl;
		cout << "=========================" << endl;
	}
}

int main()
{
	vector<vector<int>> matrix_A = { 
									{2,0}, 
									{4,2}
										};
	vector<vector<int>> matrix_B = {
									{1,3},
									{2,0}
										};
	vector<vector<int>> matrix_C = {
									{1,0},
									{0,1}
										};
	

	matrixMultiplication(matrix_A, matrix_B);
	matrixMultiplication(matrix_B, matrix_A);
	matrixMultiplication(matrix_C, matrix_B);
	scalarMultiplication(2, matrix_A);
	scalarMultiplication(-4, matrix_B);

	
}
