#include "Monster.h"
#include "string"
#include <iostream>

using namespace std;

Monster::Monster(string firstName, string lastName, string description, int pv, vector<Attack> attacks, int money, vector<Weapon> weapon)
	:Creature(firstName, lastName, description, pv, attacks, weapon) {
	mMoneyLoot = money;
}

Monster::Monster():Creature() {
	mMoneyLoot = 0;
}

Monster::~Monster(){}


void Monster::Introduction() {
	cout << "\nVoici " << GetFirstName() << " " << GetLastName() << ".\n";
	cout << GetDescription() << endl;
	cout << "Il a " << GetPV() << " pv.\n";
}

int Monster::GetMoney() { return mMoneyLoot; }
