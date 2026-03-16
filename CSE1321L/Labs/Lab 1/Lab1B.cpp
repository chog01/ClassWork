/*
Class: CSE 1321L
Section: E01
Term: Summer 2022
Instructor: Mamo, Ermias
Name: Noah Marchman
Lab#: 1A
*/
#include <string>
#include <iostream>
using namespace std;

int main()
{
	string message;
	cout << "Enter a line of text: ";
	getline(cin, message);
	cout << "You wrote'" << message << "'" << endl;
}
