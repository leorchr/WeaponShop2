#include "Monster.h"

Monster::Monster(string firstName, string lastName, string description, int pv, vector<Attack> attacks, int money)
	:Creature(firstName, lastName, description, pv, attacks) {
	mMoneyLoot = money;
}

Monster::Monster():Creature() {
	mMoneyLoot = 0;
}

Monster::~Monster(){}