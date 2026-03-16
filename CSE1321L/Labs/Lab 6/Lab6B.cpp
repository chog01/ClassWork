/*
Class: CSE 1321L
Section: E01
Term: Summer 2022
Instructor: Mamo, Ermias
Name: Noah Marchman
Lab#: 6A
*/
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
using namespace std;

int main() {
	int choice, count = 0 , test = 0;
	float random;
	cout << "Enter a number between 1 and 1000: ";
	cin >> choice;
	srand(time(NULL));

	while (test == 0) {
		random = rand() % 1000 + 1;
		if (choice == random) {
			test = 1;
		}
		cout << "My guess was " << random << endl;
		count++;
	}	
	cout << "I guessed the number was " << choice << " and it only took me " << count << " guesses";
}
