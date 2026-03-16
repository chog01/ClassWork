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

int main()
{
	float x, y, z, w, final;
	cout << "[Math Mad Libs]" << endl;
	cout << "x + (y / z) * w = ?" << endl;
	cout << "Enter the first term: ";
	cin >> x;
	cout << endl;

	cout << x << " + (y / z) * w = ?" << endl;
	cout << "Enter the second term: ";
	cin >> y;
	cout << endl;

	cout << x << " + (" << y << " / z) * w = ? " << endl;
	cout << "Enter the third term: ";
	cin >> z;
	cout << endl;

	cout << x << " + (" << y << " / " << z << ") * w = ?" << endl;
	cout << "Enter the fourth term: ";
	cin >> w;
	cout << endl;

	final = x + (y / z) * w;

	cout << x << " + (" << y << " / " << z << ") * " << w << " = " << final;
}
