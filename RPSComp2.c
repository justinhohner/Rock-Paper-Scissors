#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
using namespace std;
// RockPaperScissors.c: my first i/o C++ program, with do/while loop and switches; saving results to file.


int RecentThrows [2];
vector<int> Results;

int PastThrows(int);
int Comparison(int);
int ComparisonThrow(int, int);
int RandomThrow(int);


//Initiates game and plays first round and any round where a prediction is not available.
int main() 
{
short ArrayPrint, RoundCount = 0;
char UserInput1, UserInput4; //User responses for initiating and replaying games
	cout << "Would you like to play Rock, Paper, Scissors? y/n ";
	cin >> UserInput1;
	if (UserInput1 =='y')
	{
		do
		{ 	
			if (RoundCount <5)
			{
				UserInput4 = RandomThrow(RoundCount);
			}			
			if (RoundCount >= 5 && UserInput4 == 'y')
			{
				UserInput4 = Comparison(RoundCount);
			}
		} while (UserInput4 == 'y');	
	}
	cout << "Good Choice. \n";
	cout << RecentThrows[0] << ", ";
	cout << RecentThrows[1] << ", ";
	cout << RecentThrows[2] << endl;
	cout << " \n";
	for (ArrayPrint=0; ArrayPrint<=RoundCount; ArrayPrint++)
	{		
		cout << Results[ArrayPrint] << endl;
	}
return 0;
}

//Random Throw function determines any throw that where a match is not found in the STL array for the last 3 player moves.

void RandomThrow(int &RoundCount)
{
int CompThrow;
	srand(time(0));
	CompThrow = rand() % (3); //Using random number to simulate a "throw," or play
	switch(CompThrow)
	{
		case 0: cout << "Rock"  << endl;
			break;
		case 1: cout << "Paper" << endl;
			break;
		case 2: cout << "Scissors" << endl;
			break;
	}
	PastThrows(CompThrow);
	RoundCount++;
	cout << "Would you like to play again? y/n ";
 	cin >> UserInput4;
	Return UserInput4;
}


//PastThrows function determines the User throw and stores it to STLArray.

int PastThrows(int CompThrow)
{
char UserInput2, UserInput3;
	cout << "Did I win? y/n ";
	cin >> UserInput2;
		if (UserInput2 == 'y')
		{
			switch (CompThrow)
			{
				case 0: cout << "You threw Scissors." << endl;
					Results.push_back(2);
					break;
				case 1: cout << "You threw Rock." << endl;
					Results.push_back(0);
					break;
				case 2: cout << "You threw Paper." << endl;
					Results.push_back(1);
					break;
			}
		}
		if (UserInput2 == 'n')
		{
			cout << "Did we tie? y/n ";
			cin >> UserInput3;
			if (UserInput3 == 'y')
			{
				switch(CompThrow)
				{
					case 0: cout << "You threw Rock." << endl;
						Results.push_back(0);
						break;
					case 1: cout << "You threw Paper." << endl;
						Results.push_back(1);
						break;
					case 3: cout << "You threw Scissors." << endl;
						Results.push_back(2);
						break;
				}
			}
		}
			if (UserInput3 == 'n')
			{
				switch(CompThrow)
				{
					case 0: cout << "You threw Paper." << endl;
						Results.push_back(1);
						break;
					case 1: cout << "You threw Scissors." << endl;
						Results.push_back(2);
						break;
					case 2: cout << "You threw Rock." << endl;
						Results.push_back(0);
						break;
				}
			}
}

//Runs the comparison.
int Comparison(int RoundCount)
{
int Loop = 5;
char UserInput4;
	if (RoundCount == 5)	
		{
			RecentThrows[0] = Results[3];
			RecentThrows[1] = Results[4];
			RecentThrows[2] = Results[5];
		}
	if (RoundCount >= 6)			
		{
			RecentThrows[0] = RecentThrows[1];
			RecentThrows[1] = RecentThrows[2];
			RecentThrows[2] = CompThrow;
		}
        for (uint val = 0; val != Results.size(); val++)
	{
		if (RecentThrows[0] == Results[Loop])
		{
			if (RecentThrows[1] == Results[Loop + 1])
			{
				if (RecentThrows[2] == Results[Loop + 2])
				{
					UserInput4 = ComparisonThrow(Loop, RoundCount);
					return UserInput4;	
				}
			}
		}
		Loop++;
	}
	UserInput4 = RandomThrow(RoundCount);
	Return UserInput4;
}

//Checks to make sure the match isn't just the last three throws repeated and determines next throw when a true matching pattern has been found.

int ComparisonThrow(int Loop, int RoundCount)
{
short DetThrow;
char UserInput4;
	if (Loop != RoundCount)
	{
		DetThrow = Results[Loop + 3];		
		switch(DetThrow)
		{
			case 0: cout << "Paper \n";
				CompThrow = 1;
				break;
			case 1: cout << "Scissors \n";
				CompThrow = 2;
				break;
			case 2: cout << "Rock \n";
				CompThrow = 3;
				break;
		}
		PastThrows(CompThrow);
		cout << "Would you like to play again? y/n ";
 	 	cin >> UserInput4;
	}
	else
	{
		UserInput4 = RandomThrow(RoundCount);
	}
	Return UserInput4;
}
	
