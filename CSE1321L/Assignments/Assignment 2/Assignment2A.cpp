/*
Class: CSE 1321L
Section: E01
Term: Summer 2022
Instructor: Mamo, Ermias
Name: Noah Marchman
Lab#: 2A
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
	int numone, numtwo, remaining, answer;

	cout << "Enter a number you want to find a multiple of: ";
	cin >> numone;

	cout << "Enter a second number: ";
	cin >> numtwo;

	cout << "Calculating..." << endl;
	
	remaining = numtwo % numone;
	answer = numtwo - remaining;

	cout << "The nearest multiple of " << numone << " from " << numtwo << " is " << answer << "!";
}