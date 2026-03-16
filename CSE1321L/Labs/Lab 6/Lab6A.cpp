/*
Class: CSE 1321L
Section: E01
Term: Summer 2022
Instructor: Mamo, Ermias
Name: Noah Marchman
Lab#: 6A
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
	int choice, highest = 0;

	for (int count = 0; count <= 9; count++) {
		cout << "Please enter number " << count + 1 << ": ";
		cin >> choice;
		if (choice > highest) {
			highest = choice;
		}
	}

	cout << "The largest number was " << highest;
}