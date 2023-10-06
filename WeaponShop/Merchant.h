#pragma once
#include <string>
#include <vector>
#include "Weapon.h"
#include "Character.h"
using namespace std;

class Merchant
{
private :
	string mName;
	string mShopName;
	string mDescription;
	string mCatchphrase;
	int mMoney;
	vector<Weapon> mWeapon;

public:
	Merchant(
		string name,
		string shopName,
		string description,
		string catchphrase,
		int money,
		vector<Weapon> weapon);

	Merchant();
	~Merchant();

	int GetMoney();
	void SetMoney(int money);
	void Buy(Character& character, int choice);
	void Sell(Character& character, int choice);

	vector<Weapon> GetWeapon();
};

