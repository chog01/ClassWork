/*
Class: CSE 1321L
Section: E01
Term: Summer 2022
Instructor: Mamo, Ermias
Name: Noah Marchman
Lab#: 8C
*/
#include <iostream>
using namespace std;

int main() {
	int row = 0, column = 0, c = 0;

	cout << "Please enter the number of rows: ";
	cin >> row;
	cout << "Please enter the number of columns: ";
	cin >> column;

	int* arr = new int[row * column];

	cout << "I have " << row << " rows and " << column << " columns. I need to fill-up "
		<< row * column << " spaces. " << endl;
	cout << "The " << row << "x" << column << " array: ";

	for (int count = 0; count < row; count++) {
		for (int count1 = 0; count1 < column; count1++) {
			*(arr + count * column + count1) = ++c;
		}
	}

	for (int count = 0; count < row; count++) {
		for (int count1 = 0; count1 < column; count1++) {
			cout << *(arr + count * column + count1)
				<< "|";
		}
		cout << endl;
	}

	int arrSize = *(&arr + 1) - arr;
	int* arr2 = new int[arrSize];

	cout << "The " << row << " x " << column << " 2-D array flattened into a "
		<< arrSize << " cell 1-D array:";

	for (int count = 0; count < arrSize; count++) {
		arr2[count] = count + 1;
	}

	for (int count = 0; count < arrSize; count++) {
		cout << arr2[count] << "|";
	}
}