/*
Class: CSE 1321L
Section: E01
Term: Summer 2022
Instructor: Mamo, Ermias
Name: Noah Marchman
Lab#: 3C
*/
#include <iostream>

using namespace std;

int main() {
	string phone, NFC;
	double version;

	cout << "[App Checklist]\n" << "What mobile device do you have? ";
	cin >> phone;

	if (phone == "Apple" ||phone == "Android") {
		if (phone == "Apple") {
			cout << "What version do you have? ";
			cin >> version;
			if (version < 14) {
				cout << "does your device support NFC? ";
				cin >> NFC;
				if (NFC == "Yes" || NFC == "yes") {
					cout << "Congradulations, you can run the app!";
				}
				else cout << "I\'m sorry, our app does not support your device.";
			}else cout << "Congradulations, you can run the app!";
		}
		else {
			cout << "What version do you have? ";
			cin >> version;
			if (version < 10) {
				cout << "does your device support Bluetooth connections? ";
				cin >> NFC;
				if (NFC == "Yes" || NFC == "yes") {
					cout << "Congradulations, you can run the app!";
				}
				else cout << "I\'m sorry, our app does not support your device.";
			} else cout <<"Congradulations, you can run the app!";
		}
	}
	else cout << "I\'m sorry.";
}