/*
Class: CSE 1321L
Section: E01
Term: Summer 2022
Instructor: Mamo, Ermias
Name: Noah Marchman
Lab#: 3C
*/
#include <iostream>

using namespace std;

int main() {
	// for do-while loop
	bool rerun = false;
	int choice;
	string run;
	do {
		rerun = false;
	// Prints menu
		cout << "Menu\n0) Hello World\n1) Goodbye Moon\n2) Walking on Sunshine\n\n What would you like to do: ";
		cin >> choice;
		switch (choice) {
		case 0: {
			cout << "Hello!" << endl;
			break;
		}
		case 1: {
			cout << "Ok, bye." << endl;
			break;
		}
		case 2: {
			cout << "WHOA!" << endl;
			break;
		}
		}
		cout << "Type YES to rerun. ";
		cin >> run;
		for (int i = 0; i < run.length(); i++) {
			run[i] = tolower(run[i]);
		}

		if (run == "yes") {
			rerun = true;
		}

	} while (rerun);
	cout << "Program Ends";
}