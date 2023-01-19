/*
Programmer: Christian Penick
Purpose: This program simulates a game of tic-tac-toe. 
Compiler: MS VC++ 2022
Date Modified: 04/03/2022
*/

#include <iostream>
using namespace std;

class tripleT
{
private: char board[3][3] = { };
	   	    
public:
	tripleT(); // Default constructor
	void displayArray();
	void updateArrayX(int user_row, int user_col);
	void updateArrayO(int user_row, int user_col);
	bool checkEmpty(int user_row, int user_col);
	bool checkWinnerX();
	bool checkWinnerO();
};

tripleT::tripleT() // Default constructor initializes the char board array to have asterisks in all the positions
{
	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 3; c++)
		{
			board[r][c] = { '*' };
		}
	}
}

void tripleT::displayArray() // This will display the array in a 3 x 3 grid 
{
	for (int r = 0; r <= 2; r++)
	{
		for (int c = 0; c <= 2; c++)
		{
			cout << board[r][c] << " ";
		}
		cout << endl;
	}
}

void tripleT::updateArrayX(int user_row, int user_col) // This function will update the array at position of user input with char 'X'
{
	board[user_row][user_col] = 'X';
}

void tripleT::updateArrayO(int user_row, int user_col) // This function will update the array at position of user input with char 'O'
{
	board[user_row][user_col] = 'O';
}

bool tripleT::checkEmpty(int user_row, int user_col) // This function checks the array value at position of user input to determine whether element is "empty" (an asterisk)
{
	if (board[user_row - 1][user_col - 1] == 'X' || board[user_row - 1][user_col - 1] == 'O')
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool tripleT::checkWinnerX()
{
	// check win by rows
	if (board[0][0] ==  'X' && board[0][1] == 'X' && board[0][2] == 'X')
	{
		return true;
	}

	else if (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X')
	{
		return true;
	}

	else if (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X')
	{
		return true;
	}
	
	// check win by columns
	else if (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X')
	{
		return true;
	}

	else if (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X')
	{
		return true;
	}

	else if (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X')
	{
		return true;
	}

	// check win by diagonal
	else if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')
	{
		return true;
	}

	else if (board[2][0] == 'X' && board[1][1] == 'X' && board[0][2] == 'X')
	{
		return true;
	}
	
	else
	{
		return false;
	}
}

bool tripleT::checkWinnerO()
{
	// check win by rows
	if (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O')
	{
		return true;
	}

	else if (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O')
	{
		return true;
	}

	else if (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O')
	{
		return true;
	}

	// check win by columns
	else if (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O')
	{
		return true;
	}

	else if (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O')
	{
		return true;
	}

	else if (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O')
	{
		return true;
	}

	// check win by diagonal
	else if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')
	{
		return true;
	}

	else if (board[2][0] == 'O' && board[1][1] == 'O' && board[0][2] == 'O')
	{
		return true;
	}

	else
	{
		return false;
	}
}

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