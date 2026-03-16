/*
Class: CSE 1321L
Section: E01
Term: Summer 2022
Instructor: Mamo, Ermias
Name: Noah Marchman
Lab#: 3C
*/
#include <iostream>
#include <string>
#include <math.h>
#include <stdio.h>
using namespace std;

class Dog
{
public:
	int age;
	double weight;
	string name;
	string furColor;
	string breed;

	string bark();
	string rename(string newName);
	void eat(double food);
	string printDog();
};

string Dog::bark()
{
	return "Woof! Woof!\n";
}

string Dog::rename(string newName)
{
	name = newName;
	return name;
}

void Dog::eat(double food)
{
	weight += food;
}

string Dog::printDog()
{
	return name + " is a " + to_string(age) + " year old " + furColor + " " + breed +
		" that weighs " + to_string(ceil(weight * 100) / 100) + " lbs.\n";
}



class Lab12B
{
public:
	void main();
};

void Lab12B::main()
{
	Dog dog;
	int age;
	double weight, eat;
	string name, newName;
	string color;
	string breed;

	cout << "You are about to create a dog" << endl;
	cout << "How old is the dog: ";
	cin >> age;
	dog.age = age;
	cout << "How much does the dog weigh: ";
	cin >> weight;
	dog.weight = weight;
	cout << "What is the dog\'s name: ";
	cin >> name;
	dog.name = name;
	cout << "What color is the dog: ";
	cin >> color;
	dog.furColor = color;
	cout << "What breed is the dog: ";
	cin >> breed;
	dog.breed = breed;
	cout << dog.printDog();

	cout << dog.bark();
	cout << name << " is hungry, how much should he eat: ";
	cin >> eat;
	dog.eat(eat);
	cout << name << " isn\'t a very good name. What should they be renamed to: ";
	cin >> newName;
	dog.rename(newName);

	cout << dog.printDog();
};

int main() {
	Lab12B r;
	r.main();
}