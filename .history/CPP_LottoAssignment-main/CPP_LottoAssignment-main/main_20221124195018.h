// my_class.h
#ifndef MY_CLASS_H // include guard
#include <iostream>
#include <fstream>
#include<iostream>
#include <string>
#include <time.h>
#include <vector>
#include <iomanip>
namespace std
{
	class header
	{
	public:
		void gameRules() {
			cout << "--------------------------------------------------------------------------------" << endl;
			cout << "-				Welcome to the Lottery				-" << endl;
			cout << "-										-" << endl;
			cout << "-GameRules:									-" << endl;
			cout << "-1. The user will be asked to enter 7 numbers between 1 and 50. 		-" << endl;
			cout << "-2. The user will be asked to enter how many times they want to play.	 	-" << endl;
			cout << "-3. The user will be asked to enter how much money they want to play with.	-" << endl;
			cout << "-4. The user will be asked to enter their name.					-" << endl;
			cout << "-5. the users numbers will be compared to the winning numbers and the user will -" << endl;
			cout << "-be told how much money they won or lost.					-" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			cout << " ";
			cout << "Press Enter to Continue";
			cin.ignore();
			cout << "\033[2J\033[1;1H";
		}

		int Matches(int& matches, int& money)
		{
			// tell user how much money they won or lost in a switch statement
			switch (matches)
			{
			case 1:
				cout << "You lost 5 dollars but got one match, you should play again" << endl;
				money -= 5;
				break;
			case 2:
				cout << "You lost 5 dollars but got two matches, you should play again" << endl;
				money -= 5;
				break;
			case 3:
				cout << "You have not lost any money and got 3 matches, you should play again" << endl;
				money -= 5;
				break;
			case 4:
				cout << "\nYou won 20 dollars";
				money += 20;
				break;
			case 5:
				cout << "\nYou won 100 dollars";
				money += 100;
				break;
			case 6:
				cout << "\nYou won 100,000 dollars";
				money += 100000;
				break;
			case 7:
				cout << "\nYou won 70,000,00 dollars";
				money += 7000000;
				break;
			default:
				cout << "You lost 5 dollars and got zero matches, you should play again" << endl;
				money -= 5;
				break;
			}
			return money;
		}
		vector<int> GenerateLotteryNumbers()
		{
			vector<int> winningNum = { -1,-1,-1,-1,-1,-1,-1 };
			srand(time(NULL));
			for (int i = 0; i < 7; i++)
			{
				winningNum[i] = rand() % 50 + 1;
				for (size_t j = 0; j < 7; j++)
				{
					if (winningNum[i] == winningNum[j] && i != j) {
						i--;
						continue;
					}
				}
			}
			return winningNum;
		}
		int CheckMatches(std::vector<int>& winningNum, std::vector<int>& playerNum)
		{
			int matches = 0;
			for (int i = 0; i < 7; i++)
			{
				for (int j = 0; j < 7; j++)
				{
					if (winningNum[i] == playerNum[j]) {
						matches++;
					}
				}
			}
			return matches;
		}
		vector<int> GetPlayerNumbers()
		{

			vector<int> playerNum;
			
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
			return playerNum;
		}
		

	};
}

#endif /* MY_CLASS_H */