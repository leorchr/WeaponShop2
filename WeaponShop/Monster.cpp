#include "Monster.h"

Monster::Monster(string name, string description, int hp, int defense, vector<Attack> attacks, int money)
	:Creature(name, description, hp, defense, attacks) {
	mMoneyLoot = money;
}

Monster::Monster():Creature() {
	mMoneyLoot = 0;
}

Monster::~Monster(){}