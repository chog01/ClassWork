/*
Class: CSE 1321L
Section: E01
Term: Summer 2022
Instructor: Mamo, Ermias
Name: Noah Marchman
Lab#: 1A
*/

#include <string>
#include <iostream>
using namespace std;
int main() {
	float price, tax, fee, subtotal, pwt, pt, tentip, twentytip;

	cout << "[Tip Calculator]" << endl;
	cout << "Enter the total price of the meal: ";
	cin >> price;

	cout << "Enter the local tax rate :";
	cin >> tax;

	cout << "Enter the delivery fee: ";
	cin >> fee;
	cout << endl;

	subtotal = price + fee;
	pwt = price * tax;
	pt = pwt + subtotal;
	tentip = subtotal * .1f;
	twentytip = subtotal * .2f;

	cout << "A 10% tip would be $" << tentip << endl;
	cout << "The total would be $" << tentip + pt << endl;

	cout << "A 20% tip would be $" << twentytip << endl;
	cout << "The total would be $" << twentytip + pt << endl;
}