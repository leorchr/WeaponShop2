#include "Creature.h"

Creature::Creature(string name, string description, int hp, int defense) {
	mName = name;
	mDescription = description;
	mHP = hp;
	mDefense = defense;
}


Creature::Creature() {
	mName = "Default";
	mDescription = "No description";
	mHP = 100;
	mDefense = 0;
}


Creature::~Creature() {}

void Creature::Attack(Creature creature) {}

void Creature::Heal(int hp){}

int Creature::GetHP() { return mHP; }

