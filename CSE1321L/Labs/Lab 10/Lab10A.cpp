/*
Class: CSE 1321L
Section: E01
Term: Summer 2022
Instructor: Mamo, Ermias
Name: Noah Marchman
Lab#: 10A
*/
#include <iostream>

using namespace std;

int x, y;

void Max(int x, int y) {
	if (x > y) {
		cout << "Max is " << x << endl;
	}
	else cout << "Max is " << y << endl;
	return;
}
void Min(int x, int y) {
	if (x > y) {
		cout << "Min is " << y << endl;
	}
	else cout << "Min is " << x << endl;
	return;
}
int Avg(int x, int y) {
	float avg = 0;
	avg = (float)(x + y) / 2;
	cout << "Average is " << avg << endl;
	return avg;
}
int main() {
	cout << "Enter number 1: ";
	cin >> x;

	cout << "Enter number 2: ";
	cin >> y;
	
	Min(x, y);
	Max(x, y);
	Avg(x, y);
}