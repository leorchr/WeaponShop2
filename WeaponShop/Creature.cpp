#include "Creature.h"
#include <iostream>
#include <cstdlib>

Creature::Creature(string firstName, string lastName, string description, int pv, vector<Attack> attacks, vector<Weapon> weapon) {
	mFirstName = firstName;
	mLastName = lastName;
	mDescription = description;
	mPV = pv;
	srand(time(NULL));
	mDefense = rand() % 20 + 1;
	mAttacks = attacks;
	mWeapon = weapon;
}


Creature::Creature() {
	mFirstName = "Default";
	mLastName = "Default";
	mDescription = "No description";
	mPV = 100;
	srand(time(NULL));
	mDefense = rand() % 20 + 1;
	mAttacks = vector<Attack>{ Attack() };
	mWeapon = vector<Weapon>{ Weapon() };
}


Creature::~Creature() {}

string Creature::GetFirstName() { return mFirstName; }

string Creature::GetLastName() { return mLastName; }

string Creature::GetFullName() { return GetFirstName() + " " + GetLastName(); }

string Creature::GetDescription() { return mDescription; }

int Creature::GetPV() { return mPV; }

void Creature::SetPV(int pv) {	mPV = pv; }

int Creature::GetDefense() { return mDefense; }

vector<Attack> Creature::GetAttacks() { return mAttacks; }


void Creature::Use(Creature& enemy, int weaponIndex, int attackIndex) {

	Weapon& weaponUsed = mWeapon[weaponIndex];
	Attack attackUsed = GetAttacks()[attackIndex];

	cout << "\n" << GetFullName() << " utilise l'attaque " << attackUsed.GetName() << " avec l'arme " << weaponUsed.GetName() << endl;

	if (attackUsed.Resolve(enemy)) {
		attackUsed.RandomizeDamages();
		enemy.SetPV(enemy.GetPV() - attackUsed.GetDamages());

		srand(time(NULL));
		weaponUsed.SetDurability(weaponUsed.GetDurability() - (rand() % 15 + 1) * 0.01f);
		if (weaponUsed.GetDurability() > 0) {
			cout << "Il reste " << weaponUsed.GetDurability() << " de durabilite a l'arme " << weaponUsed.GetName() << " de " << GetFullName() << endl;
		}
		else {
			mWeapon.erase(mWeapon.begin() + weaponIndex);
			cout << "L'arme " << weaponUsed.GetName() << " s'est detruite !";
		}
	}
	else {
		cout << "L'attaque n'a pas fonctionne\n";
	}
}

vector<Weapon> Creature::GetWeapon() { return mWeapon; }

void Creature::AddWeapon(Weapon weapon) {
	mWeapon.push_back(weapon);
}

void Creature::RemoveWeapon(int position) {
	mWeapon.erase(mWeapon.begin() + position);
};
