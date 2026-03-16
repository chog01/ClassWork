/*
Class: CSE 1321L
Section: E01
Term: Summer 2022
Instructor: Mamo, Ermias
Name: Noah Marchman
Lab#: 7A
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    int size, i, j;

    cout << "Please enter a value for the size: ";
    cin >> size;
    cout << "This is the requested " << size << "x" << size << " right triangle: " << endl;

    for (i = 1; i <= size; i++) {
        for (j = 1; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}