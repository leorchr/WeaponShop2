#pragma once
#include <string>
#include <vector>
#include "Attack.h"
using namespace std;


class Creature
{
private:
	string mName;
	string mDescription;
	int mHP;
	int mDefense;
	vector<Attack> mAttacks;

public:
	Creature(string name, string description, int hp, int defense, vector<Attack> attacks);
	Creature();
	~Creature();

	void AttackCreature(Creature creature);
	void Heal(int hp);
	int GetHP();
	int GetDefense();

};

