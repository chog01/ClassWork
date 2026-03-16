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

int main() {
	char a1, a2;

	cout << "Do you have a driving permit (Y/N)? ";
	cin >> a1;

	if (a1 == 'y' || a1 == 'Y') {
		cout << "Do you have a commercial driving license (Y/N)? ";
		cin >> a2;
		if (a2 == 'y' || a2 == 'Y') {
			cout << "Congratulations! You can purchase a vehicle, let\'s start talking options!";
		}
		else cout << "Commercial driving license is a prerequisite to purchase a vehicle!";
	}
	else cout << "Driving permit is a prerequisite to purchase a vehicle!";
}