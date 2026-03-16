/*
Class: CSE 1321L
Section: E01
Term: Summer 2022
Instructor: Mamo, Ermias
Name: Noah Marchman
Lab#: 3C
*/

#include <iostream>
#include <string>
using namespace std;

class Chair
{
public:
	int numOfLegs;
	bool Rolling;
	string Material;

	Chair(int legs, bool rolling, string material) {
		numOfLegs = legs;
		Rolling = rolling;
		Material = material;
	}

	void changeChair(int legs, bool rolling, string material) {
		numOfLegs = legs;
		Rolling = rolling;
		Material = material;
	}

	string printChair() {
		string roll, print, leg;
		if (Rolling) {
			roll = " is rolling,";
		}
		else roll = " is not rolling,";
		leg = to_string(numOfLegs);

		return "Your chair has " + leg + " legs," + roll + " and is made of " + Material + ".\n";

	}
};

class Lab12A
{
public:
	void main();
};

void Lab12A::main() {
	int legs;
	bool rolling;
	string material, check;

	cout << "You are about to create a chair." << endl;
	cout << "How many legs does your chair have: ";
	cin >> legs;

	cout << "Is your chair rolling (true/false) : ";
	cin >> check;
	if (check == "true") {
		rolling = true;
	}
	else rolling = false;
	cout << "What is your chair made of: ";
	cin >> material;

	Chair chair(legs, rolling, material);

	cout << chair.printChair();

	cout << "This program is going to change that." << endl;

	chair.changeChair(4, false, "wood");

	cout << chair.printChair();
}

int main() {
	Lab12A r;
	r.main();
}