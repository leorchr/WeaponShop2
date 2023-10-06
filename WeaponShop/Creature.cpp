#include "Creature.h"

Creature::Creature(string name, string description, int hp, int defense, vector<Attack> attacks) {
	mName = name;
	mDescription = description;
	mHP = hp;
	mDefense = defense;
	mAttacks = attacks;
}


Creature::Creature() {
	mName = "Default";
	mDescription = "No description";
	mHP = 100;
	mDefense = 0;
	mAttacks = vector<Attack>{ Attack() };
}


Creature::~Creature() {}

void Creature::AttackCreature(Creature creature) {}

void Creature::Heal(int hp){}

int Creature::GetHP() { return mHP; }

int Creature::GetDefense() { return mDefense; }

