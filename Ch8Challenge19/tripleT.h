#pragma once
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