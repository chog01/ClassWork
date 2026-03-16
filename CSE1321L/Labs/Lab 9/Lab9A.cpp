/*
Class: CSE 1321L
Section: E01
Term: Summer 2022
Instructor: Mamo, Ermias
Name: Noah Marchman
Lab#: 9A
*/

#include <iostream>

using namespace std;

int main() {
	int arr[10];
	int cell, choice;
	int size = sizeof(arr) / sizeof(arr[0]);
	bool isFound = false;

	cout << "Please enter 10 numbers: " << endl;
	
	for (int count = 0; count < 10; count++) {
		cell = count;
		cout << "Integer " << cell + 1 << ": ";
		cin >> arr[cell];
	}

	cout << "What is the target number: ";
	cin >> choice;

	for (int i = 0; i < size; i++)
		if (arr[i] == choice)
			isFound = true;

	if (isFound == true) {
		cout << "The target is in the set.";
	}
	else cout << "The target is not in the set. ";
}