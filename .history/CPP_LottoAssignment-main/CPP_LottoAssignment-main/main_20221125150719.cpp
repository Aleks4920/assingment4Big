#include <iostream>
#include <fstream>
#include<iostream>
#include <string>
#include <time.h>
#include <vector>
#include <iomanip>
#include "main.h"

using namespace std;
// 1

int main() {
	header h;

	h.gameRules();

	// get users name
	string playerName;
	cout << "Enter your name: ";
	cin >> playerName;

	int money = 20;
	bool useSameNumbers = false;
	vector<int> playerNum;

	// ask user how many times they want to play
	int plays;
	cout << "you have 20 dollars to play with" << endl;
	cout << "How many times would you like to play? (each play is 5 dollars): ";
	cin >> plays;

	// loop how many times the user wants to play
	for (int playNumber = 0; playNumber < plays; playNumber++) {

		playerNum = { -1,-1,-1,-1,-1,-1,-1 };

		if (!useSameNumbers) {
			// ask user fo 7 numbers between 1 and 50

			cout << "Enter 7 numbers: " << endl;
			for (int i = 0; i < 7; i++)
			{
				cout << "Enter number " << i + 1 << ": ";
				cin >> playerNum[i];
				if (!cin) {
					cout << "Number must be a number" << endl;
					i--;
					cin.clear();
					cin.ignore();
					continue;
				}
				if (isdigit(playerNum[i])) {
					cout << "Number must be a number" << endl;
					i--;
					continue;
				}
				else if (playerNum[i] > 50 || playerNum[i] < 0) {
					cout << "Number must be between 1 and 50" << endl;
					i--;
					continue;
				}
				else {
					for (size_t j = 0; j < 7; j++)
					{
						if (playerNum[i] == playerNum[j] && i != j) {
							i--;
							cout << "Number already entered" << endl;
							continue;
						}
					}
				}
			}
			cout << "Your numbers are: ";
			for (int i = 0; i < 7; i++)
			{
				cout << playerNum[i] << " ";
			}
			if (playNumber < plays - 1) {
				cout << "\nWould you like to use the same numbers for the next play? (y/n): ";
				char useSameNumbersChar;
				cin >> useSameNumbersChar;
				if (useSameNumbersChar == 'y' || useSameNumbersChar == 'Y') {
					useSameNumbers = true;
				}
			}

		}

		// generate 7 random numbers between 1 and 50
		vector<int> winningNum = h.GenerateLotteryNumbers();
		// print winning numbers into a file 
		ofstream file;
		file.open(playerName + "Group4" + "LotteryFile.txt", ios::trunc);
		file << "Winning Numbers: ";
		for (int i = 0; i < 7; i++)
		{
			file << winningNum[i] << " ";
		}
		file.close();


		// compare users numbers to winning numbers
		int matches = h.CheckMatches(winningNum, playerNum);;


		money = h.Matches(matches, money);


	}

	// tell user how much money they have
	cout << "\nYou have " << money << " dollars" << endl;

	// ask user if they want to play again
	cout << "Would you like to play again? (y/n): ";
	char playAgain;
	cin >> playAgain;
	if (playAgain == 'y' || playAgain == 'Y') {
		main();
	}
	return 0;


}



