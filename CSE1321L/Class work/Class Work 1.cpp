#include <iostream>
#include <string>
using namespace std;

int main() {
	float fahrenheit, celsius;

	cout << "Please enter tempature in celsius: ";
	cin >> celsius;

	fahrenheit = (float) 9 / 5 * celsius + 32;
	if (fahrenheit >= 90) {
		cout << "Heat warning tempature is  " << fahrenheit << " fahrenheit";
	}
	else cout << "Tempature is " << fahrenheit << " fahrenheit";
}