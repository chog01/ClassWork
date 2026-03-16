/*
Class: CSE 1321L
Section: E01
Term: Summer 2022
Instructor: Mamo, Ermias
Name: Noah Marchman
Lab#: 7A
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
	int size;
	cout << "Please enter a value for the size: ";
	cin >> size;
	cout << "This is the requested " << size << " x " << size << " box: " << endl;
	for (int count1 = size; count1 > 0; count1--) {
		for (int count2 = size; count2 > 0; count2--) {
			cout << "*";
		}
		cout << endl;
	}

}