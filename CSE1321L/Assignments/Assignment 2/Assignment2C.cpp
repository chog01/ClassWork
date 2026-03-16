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
	float miles;
	const double fridgeL = .00105745, candyL = .0000848327;
	long fridges, candy;

	cout << "Enter a number of miles: ";
	cin >> miles;
	 
	cout << "You: I walked " << miles << " miles today #fitnessgoals" << endl;
	
	fridges = miles / fridgeL;
	candy = miles / candyL;

	cout << "Useless Conversion Bot: Wow, " << miles << " miles is " << fridges <<
		" refrigerators long!" << endl;
	cout << "Useless Conversion Bot: " << miles << " miles is also " << candy <<
		" candy bars long!" << endl;
	cout << "Useless Conversion Bot: Thats a lot.";
}