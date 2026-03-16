/*
Class: CSE 1321L
Section: E01
Term: Summer 2022
Instructor: Mamo, Ermias
Name: Noah Marchman
Lab#: 5B
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
	int number;

	cout << "Enter an integer: ";
	cin >> number;

	if (number % 2 == 0) {
		cout << "This number is divisible by 2";
	}
	else if (number % 5 == 0) {
		cout << "This number is divisible by 5";
	}
	else cout << "This number is undetermined";
}