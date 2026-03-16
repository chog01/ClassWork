/*
Class: CSE 1321L
Section: E01
Term: Summer 2022
Instructor: Mamo, Ermias
Name: Noah Marchman
Lab#: 4A
*/
#include <string>
#include <iostream>
using namespace std;

int main() {
	float grade;

	cout << "Enter the score of your exam: ";
	cin >> grade;

	if (grade > 97.4 && grade < 100) {
		cout << "Letter grade is: A+";
	}
	else if (grade > 93.4 && grade < 97.5) {
		cout << "Letter grade is: A";
	}
	else if (grade > 91.4 && grade < 93.5) {
		cout << "Letter grade is: A-";
	}
	else if (grade > 88.5 && grade < 91.5) {
		cout << "Letter grade is: B+";
	}
	else if (grade > 85.4 && grade < 88.5) {
		cout << "Letter grade is: B";
	}
	else if (grade > 81.4 && grade < 85.5) {
		cout << "Letter grade is: B-";
	}
	else if (grade > 79.4 && grade < 81.5) {
		cout << "Letter grade is: C+";
	}
	else if (grade > 76.4 && grade < 79.5) {
		cout << "Letter grade is: C";
	}
	else if (grade > 73.4 && grade < 76.5) {
		cout << "Letter grade is: C-";
	}
	else if (grade > 70.4 && grade < 73.5) {
		cout << "Letter grade is: D+";
	}
	else if (grade > 67.4 && grade < 70.5) {
		cout << "Letter grade is: D";
	}
	else if (grade > 64.4 && grade < 67.5) {
		cout << "Letter grade is: D-";
	}
	else cout << "Letter grade is: F";
}