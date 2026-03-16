/*
Class: CSE 1321L
Section: E01
Term: Summer 2022
Instructor: Mamo, Ermias
Name: Noah Marchman
Lab#: 10B
*/
#include <iostream>

using namespace std;
double width, height, area, perimeter;
bool Valid = false, rerun = false;

bool valid(double width, double height) {
	double over = 0, area, perimeter;
	char run;
	over = width + height;

	if (over > 29) {
		Valid = true;
		cout << "This is a valid rectangle" << endl;
		return Valid;
	}
	else Valid = false; cout << "This is an invalid rectangle" << endl;

	if (Valid == false) {
		cout << "Do you want to enter another width and height (Y/N)? : ";
		cin >> run;
		if (run == 'n' || run == 'N') {
			return rerun;
		}
		else rerun = true;
	}
	return Valid, rerun;
}

double Area(double width,double height) {
	area = width * height;
	return area;
}

double perm(double width, double height) {
	perimeter = (width * 2) + (height * 2);
	return perimeter;
}

int main() {
	char run;
	do {
	here:
		cout << "Enter width: ";
		cin >> width;

		cout << "Enter heigth: ";
		cin >> height;

		valid(width, height);
		if (Valid == false && rerun == true) {
			goto here;
		}
		if (Valid == true) {
			Area(width, height);
			cout << "The area is: " << area << endl;

			perm(width, height);
			cout << "The perimeter is: " << perimeter << endl;

			cout << "Do you want to enter another width and height (Y/N)? : ";
			cin >> run;
			if (run == 'Y' || run == 'y') {
				goto here;
			}
			else rerun = false;
		}
	} while (rerun == true);

	cout << "Program Ends";
	
}