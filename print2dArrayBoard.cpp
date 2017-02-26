#include<iostream>
#include<fstream>

using namespace std;

int input(istream& in=cin)
{
	int x;
	in >> x;
	return x;
}

int main()
{
	int board[9][9]; //creates a 9*9 matrix or a 2d array.

	for(int i=0; i<9; i++)    //This loops on the rows.
	{
		for(int j=0; j<9; j++) //This loops on the columns
		{
			board[i][j] = input(); //you can also connect to the file
			//and place the name of your ifstream in the input after opening the file will
			//let you read from the file.
		}
	}

	for(int i=0; i<9; i++)    //This loops on the rows.
	{
		for(int j=0; j<9; j++) //This loops on the columns
		{
			cout << board[i][j]  << "  ";
		}
		cout << endl;
	}
}
