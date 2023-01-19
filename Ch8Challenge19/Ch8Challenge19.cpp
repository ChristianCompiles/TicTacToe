/*
Programmer: Christian Penick
Purpose: This program simulates a game of tic-tac-toe. 
Compiler: MS VC++ 2022
Date Modified: 01/19/2023
*/

#include <iostream>
#include "tripleT.h"
using namespace std;


// Function prototypes
int validate_row(int row);
int validate_col(int col);

int main()
{
	tripleT game1; // This creates an instance of the class tripleT called game1

	game1.displayArray();
	cout << endl;

	// Declare variables to store user input which will then be passed to validation functions
	int row_choice, col_choice;
	
	for (int i = 0; i <= 3; i++)
	{

		cout << "User 1 (X's), what position will you fill? (row, col): ";
		cin >> row_choice;
		cin >> col_choice;

		int x_bounded_row = validate_row(row_choice); // I chose the qualifier "bounded" to describe the fact that the value is within the "bounds" of the board... a more suitable qualifer might be possible
		int x_bounded_col = validate_col(col_choice);

		while (game1.checkEmpty(x_bounded_row, x_bounded_col) == false)
		{
			cout << "Please choose an empty row location: ";
			cin >> row_choice;
			x_bounded_row = validate_row(row_choice);

			cout << "Please enter an empty column location: ";
			cin >> col_choice;
			x_bounded_col = validate_col(col_choice);
		}

		game1.updateArrayX(x_bounded_row - 1, x_bounded_col - 1);

		cout << endl;
		game1.displayArray();

		if (game1.checkWinnerX())
		{
			cout << "\nX's have won!\n";
			cout << "Would you like to play a game of Global Thermonuclear War?\n";
			break;
		}

		cout << endl;

		cout << "User 2 (O's), what position will you fill? (row, col): ";
		cin >> row_choice;
		cin >> col_choice;

		int o_bounded_row = validate_row(row_choice);
		int o_bounded_col = validate_col(col_choice);

		while (game1.checkEmpty(o_bounded_row, o_bounded_col) == false)
		{
			cout << "Please choose an empty row location: ";
			cin >> row_choice;
			o_bounded_row = validate_row(row_choice);

			cout << "Please enter an empty column location: ";
			cin >> col_choice;
			o_bounded_col = validate_col(col_choice);
		}

		game1.updateArrayO(o_bounded_row - 1, o_bounded_col - 1);

		cout << endl;
		game1.displayArray();

		if (game1.checkWinnerO())
		{
			cout << "\nO's have won!\n";
			cout << "Would you like to play a game of Global Thermonuclear War?\n";
			break;
		}

		cout << endl;
	}

	if (game1.checkWinnerX() == false && game1.checkWinnerO() == false) // The body will run if the first 8 plays did not result in a win
	{
		cout << "User 1 (X's), what position will you fill? (row, col): ";
		cin >> row_choice;
		cin >> col_choice;

		int x_bounded_row = validate_row(row_choice); // I chose the qualifier "bounded" to describe the fact that the value is within the "bounds" of the board... a more suitable qualifer might be possible
		int x_bounded_col = validate_col(col_choice);

		while (game1.checkEmpty(x_bounded_row, x_bounded_col) == false)
		{
			cout << "Please choose an empty row location: ";
			cin >> row_choice;
			x_bounded_row = validate_row(row_choice);

			cout << "Please enter an empty column location: ";
			cin >> col_choice;
			x_bounded_col = validate_col(col_choice);
		}

		game1.updateArrayX(x_bounded_row - 1, x_bounded_col - 1);

		cout << endl;
		game1.displayArray();

		if (game1.checkWinnerX()) // Since this code will only run if O's did not win on their final turn, the only option left is for X to win or for a tie to occur
		{
			cout << "\nX's have won!\n";
			cout << "Would you like to play a game of Global Thermonuclear War?\n";
		}
		
		else
		{
			cout << "A tie has occured!\n";
			cout << "Would you like to play a game of Global Thermonuclear War?\n";
		}

		cout << endl;
	}

	return 0;
}

// Function definitions
int validate_row(int row_choice) // This function makes sure the row value used is between 1-3
{
	while (row_choice < 1 || row_choice > 3)
	{
		cout << "Row must be between 1 and 3: ";
		cin >> row_choice;
	}

	cout << "Row: " << row_choice << endl;
	
	return row_choice;
}

int validate_col(int col_choice) // This function makes sure the col value used is between 1-3
{
	while (col_choice < 1 || col_choice > 3)
	{
		cout << "Column must be between 1 and 3: ";
		cin >> col_choice;
	}

	cout << "Col:" << col_choice << endl;

	return col_choice;
}