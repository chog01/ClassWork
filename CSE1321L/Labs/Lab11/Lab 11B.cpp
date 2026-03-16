/*
Class: CSE 1321L
Section: E01
Term: Summer 2022
Instructor: Mamo, Ermias
Name: Noah Marchman
Lab#: 11B
*/
#include <iostream>

using namespace std;

int main() {
	string password;
	bool uppercaseFlag, digitFlag;
	uppercaseFlag = false;
	digitFlag = false;

	cout << "Enter a password: ";
	cin >> password;
	for (int i = 0; i < password.length(); i++) {
		if (password[i] >= 'A' && password[i] <= 'Z') {
			uppercaseFlag = true;
		}
		if (password[i] >= '0' && password[i] <= '9') {
			digitFlag = true;
		}
	}
	if (password.length() >= 8 && uppercaseFlag && digitFlag) {
		cout << "Valid Password" << endl;
	}
	else cout << "Invalid Password" << endl;

	cout << "Program Ends";
}