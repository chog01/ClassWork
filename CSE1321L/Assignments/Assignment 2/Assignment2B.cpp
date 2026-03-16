/*
Class: CSE 1321L
Section: E01
Term: Summer 2022
Instructor: Mamo, Ermias
Name: Noah Marchman
Lab#: 2B
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
	int pentside, hexside, pentperm, hexperm;
	float pentarea, hexarea;

	cout << "[Pentagon Calculator]" << endl;
	cout << "Enter the length of one side: ";
	cin >> pentside;
	pentperm = pentside * 5;
	pentarea = (sqrt(5*(5 + 2 * (sqrt(5)))) * (pentside * pentside)) / 4;
	cout << "Pentagon Perimeter = " << pentperm << endl;
	cout << "Pentagon Area = " << pentarea << endl;
 	
	cout << "[Hexagon Calculator]" << endl;
	cout << "Enter the length of one side: ";
	cin >> hexside;
	hexperm = hexside * 6;
	hexarea = (3 * sqrt(3) / 2) * (hexside * hexside);
	cout << "Hexagon Perimeter = " << hexperm << endl;
	cout << "Hexagon Area = " << hexarea << endl;
}