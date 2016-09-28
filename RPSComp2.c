#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
using namespace std;
// RockPaperScissors.c: my first i/o C++ program, with do/while loop and switches; saving results to file.

vector<int> Results;
short Loop, Check, RoundCount = 0;
int RecentThrows [2], CompThrow;
char UserInput4;

void PastThrows();
void Comparison();
void ComparisonThrow();
void RandomThrow();


//Initiates game and plays first round and any round where a prediction is not available.
int main() 
{
	short ArrayPrint;
	char UserInput1; //User responses for initiating and replaying games
	cout << "Would you like to play Rock, Paper, Scissors? y/n ";
	cin >> UserInput1;
	if (UserInput1 =='y')
	{
		do
		{ 	
			if (RoundCount <5)
			{
				RandomThrow();
			}			
			if (RoundCount >= 5 && UserInput4 == 'y')
			{
				Comparison();
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

void RandomThrow()
{
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
	PastThrows();
	RoundCount++;
	cout << "Would you like to play again? y/n ";
 	cin >> UserInput4;
}


//PastThrows function determines the User throw and stores it to STLArray.

void PastThrows()
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
void Comparison()
{
	Loop = 5;
	Check = 5;
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
	for (int val : Results)  //Beginning of Range-based loop
	{
		if (RecentThrows[0] == Results[Loop])
		{
			if (RecentThrows[1] == Results[Loop + 1])
			{
				if (RecentThrows[2] == Results[Loop + 2])
				{
					ComparisonThrow();
					return;	
				}
			}
		}
		Loop++;
		Check++;
	}
	RandomThrow();
}

//Checks to make sure the match isn't just the last three throws repeated and determines next throw when a true matching pattern has been found.

void ComparisonThrow()
{
	short DetThrow;
	if (Check != RoundCount)
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
		PastThrows();
		cout << "Would you like to play again? y/n ";
 	 	cin >> UserInput4;
	}
	else
	{
		RandomThrow();
	}
}
	
