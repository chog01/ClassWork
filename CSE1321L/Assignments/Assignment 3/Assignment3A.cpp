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
using namespace std;

int main() {
	int events, percent;
	string graduation;

	cout << "[Scrappy\'s Bucket List Rewards]" << endl
		<< "How many events have you attended? ";
	cin >> events;

	percent = ((float)events / 63) * 100;

	if (percent < 10) {
		if (events == 0) {
			cout << "Check out events at https://studentaffairs.kennesaw.edu/scrappysbucketlist/!";
		}
		else cout << "You\'ve been to " << percent << "% of all SBL events!";
	}
	else if (percent < 25) {
		cout << "You\'ve been to " << percent << "% of all SBL events!" << endl;
		cout << "You\'ve earned a Drawstring Bag!" << endl;
	}
	else if (percent < 50) {
		cout << "You\'ve been to " << percent << "% of all SBL events!" << endl;
		cout << "You\'ve earned a Drawstring Bag!" << endl;
		cout << "You\'ve earned a Hat!" << endl;
	}
	else if (percent < 75) {
		cout << "You\'ve been to " << percent << "% of all SBL events!" << endl;
		cout << "You\'ve earned a Drawstring Bag!" << endl;
		cout << "You\'ve earned a Hat!" << endl;
		cout << "You\'ve earned a T-Shirt!" << endl;
	}
	else if (percent < 100) {
		cout << "You\'ve been to " << percent << "% of all SBL events!" << endl;
		cout << "You\'ve earned a Drawstring Bag!" << endl;
		cout << "You\'ve earned a Hat!" << endl;
		cout << "You\'ve earned a T-Shirt!" << endl;
		cout << "You\'ve earned a Glass Water Bottle!" << endl;
	}
	else if (percent == 100) {
		cout << "You\'ve been to " << percent << "% of all SBL events!" << endl;
		cout << "You\'ve earned a Drawstring Bag!" << endl;
		cout << "You\'ve earned a Hat!" << endl;
		cout << "You\'ve earned a T-Shirt!" << endl;
		cout << "You\'ve earned a Glass Water Bottle!" << endl;
		cout << "You\'ve earned a Hoodie!" << endl;
		cout << "Are you graduating? ";
		cin >> graduation;
		if (graduation == "Yes" ||graduation ==  "yes") {
			cout << "You’ve also earned a Challenge Coin and special Graduation Cords.";
		}
		else cout << "There’s a special reward when you graduate!";
	}
}