/*
Class: CSE 1321L
Section: E01
Term: Summer 2022
Instructor: Mamo, Ermias
Name: Noah Marchman
Lab#: 4A
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
	int number, choice, inverse;
	float reciprical, sq, cr;

	cout << "Welcome!" << endl << "Please input a number: ";
	cin >> number;

	cout << "What would you like to do to this number:\n"
		<< "0 - Get the additive inverse of the number\n"
		<< "1 - Get the reciprocal of the number\n" 
		<< "2 - Square the number\n" 
		<< "3 - Cube the number\n"
		<< "4 - Exit the program\n";
	cin >> choice;

	switch (choice) {
		case(0): {
			inverse = - 1 * number;
			cout << "The additive inverse of " << number << " is " << inverse << endl;
			break;
		};
		case(1): {
			reciprical = (float) 1 / number;
			cout << "The reciprocal of " << number << " is " << reciprical;
			break;
		};
		case(2): {
			sq = number * number;
			cout << "The square of " << number << " is " << sq;
			break;
		};
		case(3): {
			cr = number * number * number;
			cout << "the cube of " << number << " is " << cr;
			break;
		};
		case(4): {
			cout << "Thank you, Goodbye!";
			break;
		};
		default: cout << "Invalid input, please try again!";
	}
}