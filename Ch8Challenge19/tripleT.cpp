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
	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 3; c++)
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

bool tripleT::positionFull(int user_row, int user_col) // This function checks the array value at position of user input to determine whether element is "empty" (an asterisk)
{
	if (board[user_row - 1][user_col - 1] == 'X' || board[user_row - 1][user_col - 1] == 'O')
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool tripleT::checkWinner()
{
	for (int i = 0; i < 3; i++)
	{
		if ((board[0][i] == board[1][i]) && (board[1][i] == board[2][i]))
		{
			if (board[0][i] != '*')
			{
				cout << board[0][i] << "'s have won!\n";
				return true;
			}
		}
	}

	for (int i = 0; i < 3; i++)
	{
		if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]))
		{
			if (board[i][0] != '*')
			{
				cout << board[i][0] << "'s have won!\n";
				return true;
			}
		}
	}

	if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]))
	{
		if (board[0][0] != '*')
		{
			cout << board[0][0] << "'s have won!\n";
			return true;
		}
	}

	if ((board[2][0] == board[1][1]) && (board[1][1] == board[0][2]))
	{
		if (board[2][0] != '*')
		{
			cout << board[2][0] << "'s have won!\n";
			return true;
		}
	}

	return false;
}
