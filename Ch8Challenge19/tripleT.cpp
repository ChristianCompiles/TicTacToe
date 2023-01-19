#include "tripleT.h"
#include <iostream>
using namespace std;

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
	if (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X')
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
