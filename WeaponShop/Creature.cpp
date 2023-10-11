#include "Creature.h"
#include <iostream>
#include <cstdlib>

Creature::Creature(string firstName, string lastName, string description, int pv, vector<Attack> attacks) {
	mFirstName = firstName;
	mLastName = lastName;
	mDescription = description;
	mPV = pv;
	srand(time(NULL));
	mDefense = rand() % 20 + 1;
	mAttacks = attacks;
}


Creature::Creature() {
	mFirstName = "Default";
	mLastName = "Default";
	mDescription = "No description";
	mPV = 100;
	srand(time(NULL));
	mDefense = rand() % 20 + 1;
	mAttacks = vector<Attack>{ Attack() };
}


Creature::~Creature() {}

void Creature::AttackCreature(Creature creature) {}

void Creature::Heal(int pv){}

string Creature::GetFirstName() { return mFirstName; }

string Creature::GetLastName() { return mLastName; }

string Creature::GetFullName() { return GetFirstName() + " " + GetLastName(); }

string Creature::GetDescription() { return mDescription; }

int Creature::GetPV() { return mPV; }

void Creature::SetPV(int pv) {	mPV = pv; }

int Creature::GetDefense() { return mDefense; }

vector<Attack> Creature::GetAttacks() { return mAttacks; }

