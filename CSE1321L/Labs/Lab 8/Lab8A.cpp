/*
Class: CSE 1321L
Section: E01
Term: Summer 2022
Instructor: Mamo, Ermias
Name: Noah Marchman
Lab#: 8A
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
	int firstArray[5], secondArray[5];
	int integer;

	cout << "Please enter 5 integers for the first array: " << endl;
	for (int count = 0; count <= 4; count++) {
		integer = count;
		cout << "Integer " << ++integer << ": ";
		cin >> firstArray[count];
	}

	cout << "Please enter 5 integers for the second array: " << endl;
	
	for (int count1 = 0; count1 <= 4; count1++) {
		integer = count1;
		cout << "Integer " << ++integer << ": ";
		cin >> secondArray[count1];
	}

	cout << "The resulting sums are " << firstArray[0] + secondArray[0] <<
		"|" << firstArray[1] + secondArray[1] << "|" << firstArray[2] + secondArray[2] <<
		"|" << firstArray[3] + secondArray[3] << "|" << firstArray[4] + secondArray[4] << "|";
}