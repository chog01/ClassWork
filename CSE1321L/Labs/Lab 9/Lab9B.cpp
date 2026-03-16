/*
Class: CSE 1321L
Section: E01
Term: Summer 2022
Instructor: Mamo, Ermias
Name: Noah Marchman
Lab#: 9B
*/

#include <iostream>

using namespace std;

int main() {
	int arr[11], cell, choice, low = 0, mid = 0;
	int n = sizeof(arr) / sizeof(arr[0]);
	bool isFound = false;

	
	cout << "Please enter 11 numbers: " << endl;

	for (int count = 0; count < 11; count++) {
		cell = count;
		cout << "Integer " << cell + 1 << ": ";
		cin >> arr[cell];
	}

	cout << "What is the target number: ";
	cin >> choice;

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	cout << "The sorted set is: ";
	for (int count = 0; count < 11; count++) {
		cout << arr[count] << " ";
	}

	cout << endl;

	while (n >= low) {
		mid = (low + n) / 2;
		if (n == 11)
			n--;
		cout << "Low is " << low << endl
			<< "High is " << n << endl
			<< "Mid is " << mid << endl
			<< "Searching" << endl;

		if (choice < arr[mid]) {
			n = mid - 1;
		}
		else if (choice == arr[mid]) {
			isFound = true; break;
		}
		else low = mid + 1;
	}

	if (isFound == true)
		cout << "The target is in the set.";
	else cout << "The target is not in the set.";
	
}