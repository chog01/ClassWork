/*
Class: CSE 1321L
Section: E01
Term: Summer 2022
Instructor: Mamo, Ermias
Name: Noah Marchman
Lab#: 4B
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
	string day;
	 
	cout << "Enter the day: ";
	cin >> day;

	if (day == "monday" || day == "Monday" || day == "Wednesday" || day == "wednesday") {
		cout << "I have class today!";
	}
	else if (day == "friday" || day == "Friday") {
		cout << "It\'s Friday! Friday! Gotta get down on Friday!";
	}
	else cout << "I should use this time to do my homework. ";
}