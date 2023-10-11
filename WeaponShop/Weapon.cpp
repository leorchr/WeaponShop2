#include "Weapon.h"

Weapon::Weapon(string name, string description, WeaponType type, int weight, int damages, int cost, float durability) {
	mName = name;
	mDescription = description;
	mType = type;
	mWeight = weight;
	mDamages = damages;
	mCost = cost;
	mDurability = durability;
}

Weapon::Weapon() {
	mName = "Undefined";
	mDescription = "None";
	mType = WeaponType::Default;
	mWeight = 1;
	mDamages = 0;
	mCost = 10000;
	mDurability = 1;
}

Weapon::~Weapon() {}

string Weapon::GetName() { return mName; }

int Weapon::GetCost() { return round(mCost * mDurability); }

int Weapon::GetDamages() { return mDamages; }

float Weapon::GetDurability() { return mDurability; }

void Weapon::SetDurability(float durability) { mDurability = durability; }
