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

int main() 
{
	string name1, name2, adverb, verb;

	cout << "Enter a name: ";
	cin >> name1;

	cout << "Enter another name: ";
	cin >> name2;

	cout << "Enter a verb: ";
	cin >> verb;

	cout << "Enter an adverb: ";
	cin >> adverb;

	cout << "Once upon a time, there was a person named " << name1
		<< " who had a child named " << name2
		<< ". This child would " << verb << " " << adverb
		<< " while singing to strangers. ";
}
