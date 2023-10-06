#include "Character.h"
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

Character::Character(string firstName, string lastName, string catchphrase, int money, int pV, vector<Weapon> weapon, Race race, Job job) {
	mFirstName = firstName;
	mLastName = lastName;
	mCatchphrase = catchphrase;
	mMoney = money;
	mPV = pV;
	mWeapon = weapon;
	mRace = race;
	mJob = job;
}

Character::Character() {
	mFirstName = "Default";
	mLastName = "Default";
	mCatchphrase = "Vide";
	mMoney = 0;
	mPV = 100;
	mWeapon = vector<Weapon>{ Weapon()};
	mRace = Race::Default;
	mJob = Job::Default;
}

Character::~Character() {}

void Character::Introduction() {
	cout << "\nBonjour, je m'appelle " << mFirstName << " " << mLastName << ".\n";
	cout << mCatchphrase << endl;
	cout << "Tu as " << mMoney << " pieces d'or.\n";
	cout << "Tu as " << mPV << " pv.\n\n";
	for (int i = 0; i < mWeapon.size(); i++)
	{
		cout << "Ton arme est : " << mWeapon[i].GetName() 
			<< " - Degats : " << mWeapon[i].GetDamages()
			<< " Prix : " << mWeapon[i].GetCost() << " pieces d'or" << endl;
	}
}

void Character::EnemyIntroduction() {
	cout << "\nVoici " << mFirstName << " " << mLastName << ".\n";
	cout << mCatchphrase << endl;
	cout << "Il a " << mPV << " pv.\n";
}

string Character::GetName() {return mFirstName + " " + mLastName; }

int Character::GetMoney() { return mMoney; }

void Character::SetMoney(int money) { mMoney = money; }

int Character::GetPV() { return mPV; }

void Character::SetPV(int pv) {
	mPV = pv;
}

vector<Weapon> Character::GetWeapon() { return mWeapon; }

void Character::AddWeapon(Weapon weapon) {
	mWeapon.push_back(weapon);
}

void Character::RemoveWeapon(int position) {
	mWeapon.erase(mWeapon.begin() + position);
};

void Character::Use(Character& enemy, int weaponIndex) {
	Weapon weaponUsed = mWeapon[weaponIndex];
	enemy.SetPV(enemy.GetPV() - weaponUsed.GetDamages());
	srand((unsigned)time(NULL));
	weaponUsed.SetDurability(weaponUsed.GetDurability() - (rand() % 5 + 1) * 0.01f);
}

void Character::Loot(Character& enemy) {
	for (int i = 0; i < enemy.GetWeapon().size(); i++)
	{
		mWeapon.push_back(enemy.GetWeapon()[i]);
		cout << "Tu as obtenu : " << enemy.GetWeapon()[i].GetName() << endl;
	}

	for (int i = 0; i < enemy.GetWeapon().size(); i++)
	{
		enemy.RemoveWeapon(i);
	}
}