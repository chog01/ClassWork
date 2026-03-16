/*
Class: CSE 1321L
Section: E01
Term: Summer 2022
Instructor: Mamo, Ermias
Name: Noah Marchman
Lab#: 13A
*/

#include <iostream>
#include <string>
using namespace std;

class BuildingBlueprint
{
private:
	int stories;
	int apartments;
	float rate;
	bool full;
public:
	float getOccupancy() {
		rate = rate * 100;
		return rate;
	}

	int getStories() {
		return stories;
	}

	int getApartments() {
		return apartments;
	}

	string getFull() {
		string b;
		if (full == 1) {
			b = "true";
		}
		else b = "false";
		return b;
	}

	void setOccupancy(float Rate) {
		rate = Rate;
		if (rate == 1.0) {
			full = true;
		}
		else full = false;
	}
	
	BuildingBlueprint() 
	{
		stories = 10;
		apartments = 20;
		rate = 1.0;
		full = true;
	}

	BuildingBlueprint(int Stories,int Apartments,float Rate)
	{
		stories = Stories;
		apartments = Apartments;
		rate = Rate;
		if (rate == 1.0) {
			full = true;
		}
		else full = false;
	}
};

class Lab13A
{
public: void main();
};

void Lab13A::main() {
	BuildingBlueprint buildingOne = BuildingBlueprint();
	BuildingBlueprint buildingTwo(30, 30, .75);

	cout << "Year 2020:\n";
	cout << "Building 1 has " << buildingOne.getStories() << " floors, " << buildingOne.getApartments()
		<< " apartments, and is " << buildingOne.getOccupancy() << "% occupied. Full? " << buildingOne.getFull() << endl;
	cout << "Building 2 has " << buildingTwo.getStories() << " floors, " << buildingTwo.getApartments()
		<< " apartments, and is " << buildingTwo.getOccupancy() << "% occupied. Full? " << buildingTwo.getFull() << endl;

	cout << "Many years pass." << endl;

	buildingOne.setOccupancy(0.0);
	buildingTwo.setOccupancy(1.0);

	cout << "Year 2043:\n";
	cout << "Building 1 has " << buildingOne.getStories() << " floors, " << buildingOne.getApartments()
		<< " apartments, and is " << buildingOne.getOccupancy() << "% occupied. Full? " << buildingOne.getFull() << endl;
	cout << "Building 2 has " << buildingTwo.getStories() << " floors, " << buildingTwo.getApartments()
		<< " apartments, and is " << buildingTwo.getOccupancy() << "% occupied. Full? " << buildingTwo.getFull() << endl;

	cout << "Looks like people prefer taller buildings.";
}

int main() {
	Lab13A r;
	r.main();

}