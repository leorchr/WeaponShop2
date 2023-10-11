#include "Character.h"
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

Character::Character(string firstName, string lastName, string description, int pv, vector<Attack> attacks, int money, vector<Weapon> weapon, Race race, Job job)
	:Creature(firstName, lastName, description, pv, attacks, weapon) {
	mMoney = money;
	mRace = race;
	mJob = job;
}

Character::Character():Creature() {
	mMoney = 0;
	mRace = Race::Default;
	mJob = Job::Default;
}

Character::~Character() {}

void Character::Introduction() {
	cout << "\nBonjour, je m'appelle " << GetFirstName() << " " << GetLastName() << ".\n";
	cout << GetDescription() << endl;
	cout << "Tu as " << mMoney << " pieces d'or.\n";
	cout << "Tu as " << GetPV() << " pv.\n\n";
	for (int i = 0; i < GetWeapon().size(); i++)
	{
		cout << "Ton arme est : " << GetWeapon()[i].GetName()
			<< " - Durabilite : " << GetWeapon()[i].GetDurability()
			<< " - Prix : " << GetWeapon()[i].GetCost() << " pieces d'or" << endl;
	}

	for (int i = 0; i < GetAttacks().size(); i++)
	{
		cout << "Ton attaque est : " << GetAttacks()[i].GetName()
			<< " - Degats : " << GetAttacks()[i].GetDamages()
			<< " - Bonus Degats : " << GetAttacks()[i].GetAttackBonus() << endl;
	}
}

int Character::GetMoney() { return mMoney; }

void Character::SetMoney(int money) { mMoney = money; }

void Character::Loot(Monster& enemy) {
	for (int i = 0; i < enemy.GetWeapon().size(); i++)
	{
		AddWeapon(enemy.GetWeapon()[i]);
		cout << "Tu as obtenu : " << enemy.GetWeapon()[i].GetName() << endl;
	}

	for (int i = 0; i < enemy.GetWeapon().size(); i++)
	{
		enemy.RemoveWeapon(i);
	}

	mMoney += enemy.GetMoney();	
	cout << "Tu as obtenu : " << enemy.GetMoney() << endl;
	cout << "Tu as desormais " << mMoney << " pieces d'or." << endl;
}