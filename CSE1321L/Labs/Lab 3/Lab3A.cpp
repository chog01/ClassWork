/*
Class: CSE 1321L
Section: E01
Term: Summer 2022
Instructor: Mamo, Ermias
Name: Noah Marchman
Lab#: 3A
*/
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	double owed, APR, APRPercent, MPR, payment;
	cout << "Amount owed: $";
	cin >> owed;

	cout << "APR: ";
	cin >> APR;
	APRPercent = APR / 100;
	payment = (owed * APRPercent) / 12;
	MPR = (APR / 12);

	cout << "Monthly percentage rate: " <<  ceil(MPR * 1000)/1000 << endl;
	cout << "Minimum payment: $" << setprecision(4) << payment << endl;
}