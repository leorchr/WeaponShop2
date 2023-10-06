#pragma once
#include "Creature.h"

class Monster:public Creature {
private:
	int mMoneyLoot;
public:
	Monster(string name, string description, int hp, int defense, vector<Attack> attacks,int money);
	Monster();
	~Monster();
};

