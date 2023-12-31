#include "Attack.h"
#include "Creature.h"
#include <cstdlib>
#include <iostream>

Attack::Attack(string name, Weapon weapon, int damages, DamageType damageType) {
	mName = name;
	mWeapon = weapon;
	mDamages = damages;
	mDamageType = damageType;
	srand(time(NULL));
	mAttackBonus = rand() % 5 + 1;
}

Attack::Attack() {
	mName = "Default";
	mWeapon = Weapon();
	mDamages = 0;
	mDamageType = DamageType::Bludgeoning;
	mAttackBonus = 0;
}

Attack::~Attack(){}

bool Attack::Resolve(Creature creature) {
	return (rand() % 20 + 1) + mAttackBonus >= creature.GetDefense();
}

string Attack::GetName() { return mName; }

int Attack::GetDamages() { return mDamages; }

int Attack::GetAttackBonus() { return mAttackBonus; }

void Attack::RandomizeDamages() {
	srand(time(NULL));
	mDamages = (rand() % 6 + 1) + (rand() % 6 + 1) + (rand() % 6 + 1) + 3;
}