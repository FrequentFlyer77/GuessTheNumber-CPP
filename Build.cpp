#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <time.h>

using namespace std;

int main()
{
	int numberInput, numberExpected, num;
	string gameMode, inputLicense, readycheck, ao;
	bool am;
	cout << "Please take a look at the readme file included in the package! It has the instructions and terms. \nType the following phrase strawberries when your ready!\n";
	cin >> inputLicense;
	cout << endl;
	for_each(inputLicense.begin(), inputLicense.end(), [](char& c) {
		c = ::tolower(c);
	});
	do {
		srand(time(NULL));
		if (inputLicense == "strawberries") {
			cout << "Pick a mode. (Easy, Normal, Hard, Insane): ";
			cin >> gameMode;
			for_each(gameMode.begin(), gameMode.end(), [](char& c) {
				c = ::tolower(c);
			});
			if (gameMode == "easy") {
				cout << "Type ready when your ready!\n";
				do {
					cin >> readycheck;
					cout << endl;
				} while (readycheck != "ready");
				num = 10;
			}
			else if (gameMode == "normal") {
				cout << "Type ready when your ready!\n";
				do {
					cin >> readycheck;
					cout << endl;
				} while (readycheck != "ready");
				num = 100;
			}
			else if (gameMode == "hard") {
				cout << "Type ready when your ready!\n";
				do {
					cin >> readycheck;
					cout << endl;
				} while (readycheck != "ready");
				num = 1000;
			}
			else if (gameMode == "insane") {
				cout << "Type ready when your ready!\n";
				do {
					cin >> readycheck;
					cout << endl;
				} while (readycheck != "ready");
				num = 1000000;
			}
			else {
				cout << "You didn't specify a mode!\nCancelled game";
				return 0;
			}
		}
		else {
			cout << "You didn't type the verification code!\nCancelled game!";
			return 0;
		}
		numberExpected = rand() % num + 1;
		do {
			cout << "Guess the number 1 to " << num << ": ";
			cin >> numberInput;
			if (numberInput < 0) {
				cout << "Your number is way too high, or you might have typed a word.";
			}
			else {
				if (numberInput < numberExpected) {
					cout << "The number is higher!\n";
				}
				else if (numberInput > numberExpected && numberInput < num + 1) {
					cout << "The number is lower!\n";
				}
				else if (numberInput > num) {
					cout << "Way too high!\n";
				}
				else {
					cout << "An error has encountered.\nClosing game!";
					return 0;
				}
			}

		} while (numberInput != numberExpected);
		cout << "You won! Do you want to play again?\n";
		do {
			cin >> ao;
			cout << endl;

			if (ao == "yes") {
				am = true;
			}
			else if (ao == "no") {
				return 0;
			}
			else {
				am = false;
				cout << "Please pick Yes or No.\n";
			}
		} while (!am);
	} while (am);
}