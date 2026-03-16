/*
Class: CSE 1321L
Section: E01
Term: Summer 2022
Instructor: Mamo, Ermias
Name: Noah Marchman
Lab#: 3B
*/
#include <iostream>

using namespace std;

int main() {
	char dayOfWeek, timeOfDay;

	cout << "[Instructor Sceduler]" << endl
		<< "What day of the week is it? ";
	cin >> dayOfWeek;
	cout << "What time of day? ";
	cin >> timeOfDay;

	switch (dayOfWeek) {
	case 'M': {
		if (timeOfDay == 'a') {
			cout << "On Monday Morning, you\'ll be teaching C++, section E04!" << endl;
		}
		else cout << "On Monday Afternoon, you\'ll be teaching Java, section J02!" << endl;
		break;
	}
	case 'T': {
		if (timeOfDay == 'a') {
			cout << "On Tuesday Morning, you\'ll be holding office hours!" << endl;
		}
		else cout << "On Tuesday Afternoon, you\'ll be teaching C#, section W#1!" << endl;
		break;
	}
	case 'W': {
		if (timeOfDay == 'a') {
			cout << "On Wednesday Morning, you\'ll be teaching C#, section #02!" << endl;
		}
		else cout << "On Tuesday Afternoon, you\'ll have some free time!" << endl;
		break;
	}
	case 'R': {
		if (timeOfDay == 'a') {
			cout << "On Thursday Morning, you\'ll be holding office hours!" << endl;
		}
		else cout << "On Thursday Aftrnoon, you\'ll be teaching C++, section WE3!" << endl;
		break;
	}
	case 'F': {
		if (timeOfDay == 'a') {
			cout << "On Friday Morning, you\'ll be teaching C++, section WE3" << endl;
		}
		else cout << "On Tuesday Afternoon, you\'ll have some free time!" << endl;
		break;
	}
	default: cout << "That\'s not a valid day or time!!";
	}
}