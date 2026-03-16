#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;


class NPC 
{
public:
	string name;
	string type;
	float HP;
	float Attack;
	float Defense;

	NPC(string name, int ClassID) {
		this->name = name;

		switch (ClassID) {
		case 1: 
		{
			type = "Sword Fighter";
			HP = 120;
			Attack = 40;
			Defense = .2;
			break;
		}
		case 2:
		{
			type = "Unicorn Sorcerer";
			HP = 80;
			Attack = 35;
			Defense = .6;
			break;
		}
		case 3:
		{
			type = "Dance Battler";
			HP = 100;
			Attack = 20;
			Defense = .42;
			break;
		}
		}
	}

	string getType()
	{
		return type;
	}
	int getHP()
	{
		return HP;
	}
	int getAttack()
	{
		return Attack;
	}
	int getDefense()
	{
		return Defense;
	}
	string getName()
	{
		return name;
	}

	int setHP(int l)
	{
		this->HP -= l;
		if (HP < 0) {
			this->HP = 0;
		}
		return HP;
	}

	float calculateAttack(int Def)
	{
		return (float)Attack* (1 - Def);
	}
	void calculateDeffense(int Att)
	{
		float Def = (float)(Att * (1 - Defense)) - 6;
		HP -= Def;
		if (HP < 0) {
			HP = 0;
		}
	}
	bool isStillAlive()
	{
		if (HP > 0) {
			return true;
		}
		else return false;
	}

	string getNameType()
	{
		return name + " the " + type;
	}
};


class Assignment8B 
{
public:
	void main();
};

void Assignment8B::main() {
	srand(time(0));

	string name, type;

	cout << "[Generic RPG Battle System]" << endl;
	cout << "Enter your name: ";
	cin >> name;
	cout << "Enter your battle class: ";
	
	cin.ignore(256, '\n');
	getline(cin, type, '\n');

	int ClassID = 0;

	if (type == "Sword Fighter")
	{
		ClassID = 1;
	}
	else if (type == "Unicorn Sorcerer")
	{
		ClassID = 2;
	}
	else if (type == "Dance Battler")
	{
		ClassID = 3;
	}
	else cout << "Wrong Type" << endl;

	NPC Npc1(name, ClassID);
	NPC Npc2("Brad", rand() % 3 + 1);

	int Round = 1;

	cout << Npc1.getNameType() << ", your opponent is " << Npc2.getNameType() << "!" << endl;

	while (true) {
		char movement;

		if (!Npc1.isStillAlive()) {
			cout << Npc1.getNameType() << " was defeated....." << endl;
			cout << Npc2.getNameType() << " wins!" << endl;
			break;
		}
		if (!Npc2.isStillAlive()){
			cout << Npc2.getNameType() << " was defeated....." << endl;
			cout << Npc1.getNameType() << " wins!" << endl;
			break;
		}

		cout << "-Round " << Round << "-" << endl;
		cout << "Do you (a)ttack or (d)efend?";
		cin >> movement;
		string oppMovement = rand() % 2 == 1 ? "a" : "d";
		
		if (movement == 'a' && oppMovement == "a")
		{
			cout << Npc1.getNameType() << " attacked " << Npc2.getNameType() << "!" << endl;
			Npc2.setHP(Npc1.calculateAttack(Npc2.getDefense()));
			cout << Npc2.getNameType() << " now has " << Npc2.getHP() << " HP. " << endl;

			cout << Npc2.getNameType() << " attacked " << Npc1.getNameType() << "!" << endl;
			Npc1.setHP(Npc2.calculateAttack(Npc1.getDefense()));
			cout << Npc1.getNameType() << " now has " << Npc1.getHP() << " HP. " << endl;
		}
		else if (movement == 'd' && oppMovement == "d")
		{
			cout << Npc1.getNameType() << " is on guard." << endl;
			cout << Npc2.getNameType() << " is on guard." << endl;
		}
		else if (movement == 'a')
		{
			cout << Npc2.getNameType() << " is on guard." << endl;
			cout << Npc1.getNameType() << " attacked " << Npc2.getNameType() << "!" << endl;
			Npc2.calculateDeffense(Npc1.getAttack());
			cout << Npc2.getNameType() << " now has " << Npc2.getHP() << " HP." << endl;
		}
		else
		{
			cout << Npc1.getNameType() << " is on guard." << endl;
			cout << Npc2.getNameType() << " attacked " << Npc1.getNameType() << "!" << endl;
			Npc1.calculateDeffense(Npc2.getAttack());
			cout << Npc1.getNameType() << " now has " << Npc1.getHP() << " HP." << endl;
		}
		Round++;
	}
}

int main() {
	Assignment8B Run;
	Run.main();
}