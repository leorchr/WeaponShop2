#include "Merchant.h"
#include <string>
#include <iostream>

Merchant::Merchant(string name, string shopName, string description, string catchphrase, int money, vector<Weapon> weapon) {
	mName = name;
	mShopName = shopName;
	mDescription = description;
	mCatchphrase = catchphrase;
	mMoney = money;
	mWeapon = weapon;
}

Merchant::Merchant() {
	mName = "No name";
	mShopName = "No shopname";
	mDescription = "No description";
	mCatchphrase = "No catchphrase";
	mMoney = 0;
	mWeapon = vector<Weapon>{ Weapon(), Weapon(), Weapon(), Weapon() };
}

Merchant::~Merchant() {}

int Merchant::GetMoney() { return mMoney; }

void Merchant::SetMoney(int money) {
	mMoney = money;
}


void Merchant::Buy(Character& character, int choice) {
	Weapon weaponWanted = character.GetWeapon()[choice - 1];
	if (mMoney >= weaponWanted.GetCost()) {
		cout << "Je peux te l'acheter !\n";

		// ajouter l'arme à l'inventaire du marchand
		mWeapon.push_back(weaponWanted);
		
		// donne de l'argent au joueur
		character.SetMoney(character.GetMoney() + weaponWanted.GetCost());

		// enlève de l'argent au marchand
		mMoney -= weaponWanted.GetCost();

		// retire l'arme de l'inventaire du joueur
		character.RemoveWeapon(choice - 1);
	}
	else cout << "Je n'ai pas assez d'argent pour te l'acheter !\n";
}

void Merchant::Sell(Character& character, int choice) {

	Weapon weaponWanted = mWeapon[choice - 1];

	// vérifie que le character qui achète a l'argent
	if (character.GetMoney() >= weaponWanted.GetCost()) {
		cout << "Tu peux te l'acheter !\n";

		// enlève de l'argent au joueur
		character.SetMoney(character.GetMoney() - weaponWanted.GetCost());

		// donne de l'argent au marchand
		mMoney += weaponWanted.GetCost();

		// ajouter l'arme à l'inventaire du joueur
		character.AddWeapon(weaponWanted);

		// retire l'arme de l'inventaire du marchand
		mWeapon.erase(mWeapon.begin() + choice - 1);

	}
	else cout << "Tu n'as pas assez d'argent !\n";
	
}

vector<Weapon> Merchant::GetWeapon() {
	return mWeapon;
}