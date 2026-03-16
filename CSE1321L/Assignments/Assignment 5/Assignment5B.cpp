/*
Class: CSE 1321L
Section: E01
Term: Summer 2022
Instructor: Mamo, Ermias
Name: Noah Marchman
Lab#: 4B
*/
#include <iostream>

using namespace std;

int main() {

    char arr[5][5] = {
        {'o','_','_','_','x'},
        {'x','x','_','x','w'},
        {'_','_','_','x','_'},
        {'_','x','x','x','_'},
        {'_','_','_','_','_'}
    };
    int row = 0, column = 0, a = 1;
    string answer;

    cout << "[Maze Game]" << endl;

    while (1) {
        if (a == 0) {
            break;
        }

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cout << arr[i][j] << ".";
            }
            cout << endl;
        }

    here:
        cout << "Which direction do you want to move? " << endl;
        cin >> answer;

        if (answer == "Up") {
            if (row == 0) {
                cout << "You cant move there – its out of bounds!" << endl;
                goto here;
            }
            if (arr[row - 1][column] == 'x') {
                a = 0;
                cout << "You hit a wall – Game Over!" << endl;
                break;
            }
            if (arr[row - 1][column] == 'w') {
                a = 0;
                cout << "You Win!" << endl;
                break;
            }
            else {
                arr[row][column] = '_';
                arr[--row][column] = 'o';
            }
        }
        else if (answer == "Down") {
            if (row == 4) {
                cout << "You cant move there – its out of bounds!" << endl;
                goto here;
            }
            if (arr[row + 1][column] == 'x') {
                a = 0;
                cout << "You hit a wall – Game Over!" << endl;
                break;
            }
            if (arr[row + 1][column] == 'w') {
                a = 0;
                cout << "You Win!" << endl;
                break;
            }
            else {
                arr[row][column] = '_';
                arr[++row][column] = 'o';
            }
        }
        else if (answer == "Left") {
            if (column == 0) {
                cout << "You cant move there – its out of bounds!" << endl; 
                goto here;
            }
            if (arr[row][column - 1] == 'x') {
                a = 0;
                cout << "You hit a wall – Game Over!" << endl; 
                break;
            }
            if (arr[row][column - 1] == 'w') {
                a = 0;
                cout << "You Win!" << endl; 
                break;
            }
            else {
                arr[row][column] = '_';
                arr[row][--column] = 'o';
            }
        }
        else if (answer == "Right") {
            if (column == 4) {
                cout << "You cant move there – its out of bounds!" << endl; 
                goto here;
            }
            if (arr[row][column + 1] == 'x') {
                a = 0;
                cout << "You hit a wall – Game Over!" << endl; 
                break;
            }
            if (arr[row][column + 1] == 'w') {
                a = 0;
                cout << "You Win!" << endl; 
                break;
            }
            else {
                arr[row][column] = '_';
                arr[row][++column] = 'o';
            }
        }
        else {
            cout << "That's not a valid Direction!" << endl; 
            goto here;
        }

    }
