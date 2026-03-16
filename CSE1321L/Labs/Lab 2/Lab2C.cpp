/*
Class: CSE 1321L
Section: E01
Term: Summer 2022
Instructor: Mamo, Ermias
Name: Noah Marchman
Lab#: 2C
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
	int height, width, area ,perm;
	cout << "Enter a width: ";
	cin >> width;

	cout << "Enter a height: ";
	cin >> height;

	area = height * width;
	perm = 2 * (height + width);

	cout << "The area is " << area << endl;
	cout << "The perimeter is " << perm << endl;
	
}