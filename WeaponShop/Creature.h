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
	vector<Weapon> mWeapon;

public:
	Creature(string firstName, string lastName, string description, int pv, vector<Attack> attacks, vector<Weapon> weapon);
	Creature();
	~Creature();

	string GetFirstName();
	string GetLastName();
	string GetFullName();
	string GetDescription();
	int GetPV();
	void SetPV(int pv);
	int GetDefense();
	vector<Attack> GetAttacks();

	void Use(Creature& enemy, int weaponIndex, int attackIndex);
	vector<Weapon> GetWeapon();
	void AddWeapon(Weapon weapon);
	void RemoveWeapon(int position);

};

