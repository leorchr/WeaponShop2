#pragma once
#include <string>
#include <vector>
#include "Weapon.h"
#include "Job.h"
#include "Race.h"
#include "Creature.h"

using namespace std;

class Character:public Creature
{
private:
	int mMoney;
	vector<Weapon> mWeapon;
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
	void EnemyIntroduction();
	int GetMoney();
	void SetMoney(int money);
	vector<Weapon> GetWeapon();
	void AddWeapon(Weapon weapon);
	void RemoveWeapon(int position);
	void Use(Character& enemy, int weaponIndex, int attackIndex);
	void Loot(Character& enemy);
};

