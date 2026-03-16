/*
Class: CSE 1321L
Section: E01
Term: Summer 2022
Instructor: Mamo, Ermias
Name: Noah Marchman
Lab#: 5C
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
	int x, y;
	
	cout << "Enter x: ";
	cin >> x;

	cout << "Enter y: ";
	cin >> y;

	if (x == 0 && y == 0) {
		cout << "This point is the origin.";
	}
	else if (x != 0 && y == 0) {
		cout << "This point is on the y axis.";
	}
	else if (x == 0 && y != 0) {
		cout << "This point is on the x axis. ";
	}
	else if (x > 0 && y > 0) {
		cout << "This point is in the first quadrant.";
	}
	else if (x < 0 && y > 0) {
		cout << "This point is in the second quadrant.";
	}
	else if (x < 0 && y < 0) {
		cout << "This point is in the third quadrant.";
	}
	else if (x > 0 && y < 0) {
		cout << "This point is in the forth quadrant.";
	}
}
