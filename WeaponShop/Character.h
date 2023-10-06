#pragma once
#include <string>
#include <vector>
#include "Weapon.h"
#include "Job.h"
#include "Race.h"

using namespace std;

class Character
{
private:
	string mFirstName;
	string mLastName;
	string mCatchphrase;
	int mMoney;
	int mPV;
	vector<Weapon> mWeapon;
	Race mRace;
	Job mJob;

public:
	Character(
		string firstName,
		string lastName,
		string catchphrase,
		int money,
		int pV,
		vector<Weapon> mWeapon,
		Race race,
		Job job
		);

	Character();

	~Character();

	void Introduction();
	void EnemyIntroduction();
	string GetName();
	int GetMoney();
	void SetMoney(int money);
	int GetPV();
	void SetPV(int pv);
	vector<Weapon> GetWeapon();
	void AddWeapon(Weapon weapon);
	void RemoveWeapon(int position);
	void Use(Character& enemy, int weaponIndex);
	void Loot(Character& enemy);
};

