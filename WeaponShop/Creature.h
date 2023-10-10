#pragma once
#include <string>
#include <vector>
#include "Attack.h"
using namespace std;


class Creature
{
private:
	string mFirstName;
	string mLastName;
	string mDescription;
	int mPV;
	int mDefense;
	vector<Attack> mAttacks;

public:
	Creature(string firstName, string lastName, string description, int pv, vector<Attack> attacks);
	Creature();
	~Creature();

	void AttackCreature(Creature creature);
	void Heal(int pv);

	string GetFirstName();
	string GetLastName();
	string GetFullName();
	string GetDescription();
	int GetPV();
	void SetPV(int pv);
	int GetDefense();

};

