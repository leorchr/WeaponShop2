#pragma once
#include "Creature.h"

class Monster:public Creature {
private:
	int mMoneyLoot;
public:
	Monster(string firstName, string lastName, string description, int pv, vector<Attack> attacks,int money, vector<Weapon> weapon);
	Monster();
	~Monster();

	void Introduction();
	int GetMoney();
};