/*
Class: CSE 1321L
Section: E01
Term: Summer 2022
Instructor: Mamo, Ermias
Name: Noah Marchman
Lab#: 3C
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
	int q, d, n, p, dollars;
	float qp = .25, dp = .1, np = .05, pp = .01, total, cents;

	cout << "Enter the number of quarters: ";
	cin >> q;
	
	cout << "Enter the number of dimes: ";
	cin >> d;

	cout << "Enter the number of nickels: ";
	cin >> n;

	cout << "Enter the number of pennies: ";
	cin >> p;

	cout << "You entered " << q << " quarters." << endl;
	cout << "You entered " << d << " dimes." << endl;
	cout << "You entered " << n << " nickels." << endl;
	cout << "You entered " << p << " pennies." << endl;
	
	total = (float) q * qp + d * dp + n * np + p * pp;
	dollars = total / 1;
	cents = (total - dollars) * 100;

	cout << "Your total is " << dollars << " dollars and " << cents << " cents.";
}