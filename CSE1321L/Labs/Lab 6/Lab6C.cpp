/*
Class: CSE 1321L
Section: E01
Term: Summer 2022
Instructor: Mamo, Ermias
Name: Noah Marchman
Lab#: 6C
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
	bool end = false;
	float money = 1000.0, withdraw, deposit;
	int choice;
	char choice2;

	cout << "Welcome!\nYou have " << money << " in your account. " << endl;

	do {
		cout << "Menu\n0 \- Make a deposit\n1 \- Make a withdrawal\n2 \- Display account value" << endl;
		cout << "Please make a selection :";
		cin >> choice;

		switch (choice) {
		case(0): {
			cout << "How much would you like to deposit? :";
			cin >> deposit;
			money += deposit;
			cout << "Your current balance is $" << money << endl;
			cout << "Would you like to return to the main menu(Y / N) ? :";
			cin >> choice2;
			if (choice2 == 'n' || choice2 == 'N') {
				end = true;
			}
			break;
		}

		case(1): {
			cout << "How much would you like to withdraw? : ";
			cin >> withdraw;
			money -= withdraw;
			cout << "Your current balance is $" << money << endl;
			cout << "Would you like to return to the main menu(Y / N) ? :";
			cin >> choice2;
			if (choice2 == 'n' || choice == 'N') {
				end = true;
			}
			break;
		}

		case(2): {
			cout << "Your current balance is $" << money << endl;
			cout << "Would you like to return to the main menu(Y / N) ? :";
			cin >> choice2;
			if (choice2 == 'n' || choice == 'N') {
				end = true;
			}
			break;
		}
		}
	} while (end == false);
	cout << "Thank you for banking with us!";
}