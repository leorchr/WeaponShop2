#pragma once
#include "Weapon.h"
#include "DamageType.h"
#include <string>

using namespace std;
class Creature;

class Attack
{
private:
	string mName;
	Weapon mWeapon;
	int mDamages;
	DamageType mDamageType;
	int mAttackBonus;

public:
	Attack(string name, Weapon weapon, int damages, DamageType damageType);
	Attack();
	~Attack();
	bool Resolve(Creature creature);
	string GetName();
	int GetDamages();
	int GetAttackBonus();
};

