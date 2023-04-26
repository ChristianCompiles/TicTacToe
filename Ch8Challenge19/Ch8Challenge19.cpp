/*
Programmer: Christian Penick
Purpose: This program simulates a game of tic-tac-toe. 
Compiler: MS VC++ 2022
Date Modified: 01/19/2023, 04/25/2023
*/

#include <iostream>
#include "tripleT.h"
using namespace std;


// Function prototypes
int get_Xrow();
int get_Xcol();
int get_Orow();
int get_Ocol();
int check_input(int choice);

int main()
{
	tripleT game1; // This creates an instance of the class tripleT called game1

	game1.displayArray();
	cout << endl;

	// Declare variables to store user input which will then be passed to validation functions
	int row_choice, col_choice, x_row, x_col, o_row, o_col;
	char player1 = 'X';
	char player2 = 'O';
	
	for (int i = 0; i < 5; i++) // loop runs 5 times; game necessarily finishes halfway through 5th iteration
	{
		x_row = get_Xrow();
		x_col = get_Xcol();

		while (game1.positionFull(x_row, x_col)) // while position is full, ask for new position
		{
			cout << "Please choose an empty row location: ";
			cin >> row_choice;
			x_row = check_input(row_choice);

			cout << "Please enter an empty column location: ";
			cin >> col_choice;
			x_col = check_input(col_choice);
		}

		game1.updateArrayX(x_row - 1, x_col - 1);
		system("CLS");
		game1.displayArray();

		if (game1.checkWinner())
			break;


		if (i == 4) // this will only run if X's had to make the 9th move and tied
		{
			if (game1.checkWinner() == false)
				cout << "A tie occured.\n";
			break;
		}

		o_row = get_Orow();
		o_col = get_Ocol();

		while (game1.positionFull(o_row, o_col))
		{
			cout << "Please choose an empty row location: ";
			cin >> row_choice;
			o_row = check_input(row_choice);

			cout << "Please enter an empty column location: ";
			cin >> col_choice;
			o_col = check_input(col_choice);
		}

		game1.updateArrayO(o_row - 1, o_col - 1);
		system("CLS");
		game1.displayArray();

		if (game1.checkWinner())
		{
			cout << "\nO's have won!\n";
			cout << "Would you like to play a game of Global Thermonuclear War?\n";
			break;
		}

		cout << endl;
	}

	return 0;
}

// Function definitions
int check_input(int choice) // This function makes sure the row value used is between 1-3
{
	int foo = choice;
	while (foo < 1 || foo > 3)
	{
		cout << "Must must be between 1 and 3: ";
		cin >> choice;
		foo = choice;
		cin.clear();
		cin.ignore(100, '\n');
	}

	cout << "Choice: " << foo << endl;

	return foo;
}

int get_Xrow() // Ask user 1 for row
{
	int choice;
	cout << "User 1 (X's), what row will you fill? ";
	cin >> choice;
	cin.clear();
	cin.ignore(100, '\n');
	return check_input(choice);
}

int get_Xcol() // Ask user 1 for col
{
	int choice;
	cout << "User 1 (X's), what col will you fill? ";
	cin >> choice;
	cin.clear();
	cin.ignore(100, '\n');
	return check_input(choice);
}

int get_Orow() // Ask user 1 for row
{
	int choice;
	cout << "User 2 (O's), what row will you fill? ";
	cin >> choice;
	cin.clear();
	cin.ignore(100, '\n');
	return check_input(choice);
}

int get_Ocol() // Ask user 1 for row
{
	int choice;
	cout << "User 2 (O's), what col will you fill? ";
	cin >> choice;
	cin.clear();
	cin.ignore(100, '\n');
	return check_input(choice);
}
