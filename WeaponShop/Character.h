#pragma once
#include <string>
#include <vector>
#include "Weapon.h"
#include "Job.h"
#include "Race.h"
#include "Creature.h"
#include "Monster.h"

using namespace std;

class Character:public Creature
{
private:
	int mMoney;
	Race mRace;
	Job mJob;

public:

	Character(
		string firstName,
		string lastName,
		string description,
		int pv,
		vector<Attack> attacks, 
		int money, 
		vector<Weapon> weapon,
		Race race,
		Job job);


	Character();

	~Character();

	void Introduction();
	int GetMoney();
	void SetMoney(int money);
	void Loot(Monster& enemy);
};

