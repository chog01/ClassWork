/*
Class: CSE 1321L
Section: E01
Term: Summer 2022
Instructor: Mamo, Ermias
Name: Noah Marchman
Lab#: 1A
*/

#include <iostream>
#include <string>
using namespace std;
int main() 
{
	char firstletter;
	string lastname, netid;
	int whole = 1;

	cout << "[KSU NetID Generator]" << endl;
	cout << "Enter the first letter of your first name: ";
	cin >> firstletter;

	cout << "Enter your last name: ";
	cin >> lastname;

	cout << "Enter a valid whole number: ";
	cin >> whole;

	cout << "Your KSU NetID is " << firstletter << lastname << whole << ". You can log into KSU computers with this NetID as your username and your email password as the password"
		<< "Your email address is " << firstletter << lastname << whole << "@student.kennesaw.edu.";
}