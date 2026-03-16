/*
Class: CSE 1321L
Section: E01
Term: Summer 2022
Instructor: Mamo, Ermias
Name: Noah Marchman
Lab#: 3B
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
	float C1, C2, C3, C4, G1, G2, G3, G4, QP, GPA;
	
	cout << "Course 1 hours: ";
	cin >> C1;
	cout << "Grade for course 1: ";
	cin >> G1;

	cout << "Course 2 hours: ";
	cin >> C2;
	cout << "Grade for course 2: ";
	cin >> G2;

	cout << "Course 3 hours: ";
	cin >> C3;
	cout << "Grade for course 3: ";
	cin >> G3;

	cout << "Course 4 hours: ";
	cin >> C4;
	cout << "Grade for course 4: ";
	cin >> G4;

	QP = (C1 * G1) + (C2 * G2) + (C3 * G3) + (C4 * G4);
	GPA = QP / (C1 + C2 + C3 + C4);

	cout << "Total hours is: " << C1 + C2 + C3 + C4 << endl;
	cout << "Total quality points is: " << QP << endl;
	cout << "Your GPA for this semester is " << GPA << endl;
}