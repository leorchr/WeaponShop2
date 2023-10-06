#pragma once
#include <string>
#include "WeaponType.h"

using namespace std;

class Weapon
{
private:
	string mName;
	string mDescription;
	WeaponType mType;
	int mWeight;
	int mDamages;
	int mCost;
	float mDurability;

public:
	Weapon(string name, string description, WeaponType type, int weight, int damages, int cost, float durability);
	Weapon();
	~Weapon();

	string GetName();
	int GetCost();
	int GetDamages();
	float GetDurability();
	void SetDurability(float durability);
};

