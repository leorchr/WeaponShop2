#include <iostream>
#include "Attack.h"
#include "Character.h"
#include "Monster.h"
#include "Merchant.h"
#include <vector>
#include <string>

using namespace std;

Character mainCharacter;
Monster enemy;

Weapon sword = Weapon("Sword", "Je suis une epee", WeaponType::Sword, 20, 10, 1, 1);
Weapon weakBow = Weapon("Arc nul", "Je suis un arc", WeaponType::Bow, 20, 5, 1, 1);
Weapon weakGun= Weapon("Pistolet nul","Je suis un pistolet", WeaponType::Gun, 20, 5, 5, 1);

Weapon bow = Weapon("Bow", "Je suis un arc", WeaponType::Bow, 20, 10, 50, 1);
Weapon dagger = Weapon("Dagger", "Je suis une dague", WeaponType::Dagger, 20, 10, 120, 1);
Weapon gun = Weapon("Gun", "Je suis un pistolet", WeaponType::Gun, 20, 10, 12000, 1);
Merchant merchant = Merchant("Marchand", "Boutique", "Viens perdre ton argent !", "Welcome to my fiesta", 100000, vector<Weapon>{ bow, dagger, gun});

Attack brulure = Attack("Brulure", sword, 20, DamageType::Burning);
Attack percee = Attack("Percee", sword, 20, DamageType::Piercing);
Attack tir = Attack("Tir", weakBow, 20, DamageType::Piercing);


int inputHandler();
void PlayerConfiguration();
void MainLoop();
void SellChoice();
void BuyChoice();
void Fight();

int main()
{
	PlayerConfiguration();
	MainLoop();
}

int inputHandler() {
	int num;
	while (cout << "Ton choix : " && !(cin >> num))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Merci de rentrer un chiffre\n";
	}
	return num;
}

void MainLoop() {
	int answer;
	do {
		cout << "\nQue veux-tu faire ?\n";
		cout << "(1) Consulter ton profil\n";
		cout << "(2) Acheter une arme au marchand\n";
		cout << "(3) Vendre une arme au marchand\n";
		cout << "(4) Engager un combat\n";
		answer = inputHandler();
		if (answer == 1) {
			mainCharacter.Introduction();
		}
		else if (answer == 2) {
			SellChoice();
		}
		else if (answer == 3) {
			BuyChoice();
		}
		else if (answer == 4) {
			Fight();
		}
	} while (answer != 1 && answer != 2 && answer != 3 && answer != 4);
	MainLoop();
}

void SellChoice() {
	cout << "\nVoici mes armes : \n";
	for (int i = 0; i < merchant.GetWeapon().size(); i++)
	{
		Weapon tempWeapon = merchant.GetWeapon()[i];
		cout << "(" << i+1 << ")" << tempWeapon.GetName() << " - " << tempWeapon.GetCost() << " pieces d'or" << endl;
	}
	cout << "Quelle arme veux-tu acheter ?\n";
	int answer;
	answer = inputHandler();
	merchant.Sell(mainCharacter,answer);
}

void BuyChoice() {
	cout << "\nVoici tes armes : \n";
	for (int i = 0; i < mainCharacter.GetWeapon().size(); i++)
	{
		cout << "(" << i + 1 << ")" << mainCharacter.GetWeapon()[i].GetName() << endl;
	}
	cout << "Quelle arme veux-tu vendre< ?\n";
	int answer;
	answer = inputHandler();
	merchant.Buy(mainCharacter, answer);
}

void Fight() {
	cout << "\nC'est l'heure du dududud udududd dueeeel ! \n";


	weakBow = Weapon("Arc nul", "Je suis un arc", WeaponType::Bow, 20, 5, 1, 1);
	weakGun = Weapon("Pistolet nul", "Je suis un pistolet", WeaponType::Gun, 20, 5, 5, 1);
	enemy = Monster("Philipep", "Ito", "C'est le mechant", 100, vector<Attack> {tir}, 100, vector<Weapon> {weakBow, weakGun});
	enemy.Introduction();

	while (mainCharacter.GetPV() > 0 && enemy.GetPV() > 0) {

		cout << "\nVeux-tu attaquer ou te soigner ? \n";
		cout << "(1) Attaque\n(2) Soin\n";
		int answer;
		answer = inputHandler();
		if (answer == 1) {
			//Choix arme avec l'index

			cout << "\nVoici tes armes : \n";
			for (int i = 0; i < mainCharacter.GetWeapon().size(); i++)
			{
				cout << "(" << i + 1 << ")" << mainCharacter.GetWeapon()[i].GetName() << endl;
			}
			cout << "\nQuelle arme veux-tu utiliser ?\n";
			int answer1;
			answer1 = inputHandler();

			//Choix attaque avec iterator

			cout << "\nVoici tes attaques : \n";
			vector<Attack>::iterator itr;
			vector<Attack> usedAttack = mainCharacter.GetAttacks();
			int y = 1;
			for (itr = usedAttack.begin(); itr < usedAttack.end(); itr++)
			{
				cout << "(" << distance(usedAttack.begin(), itr) + 1 << ")" << itr->GetName() << endl;
			}
			cout << "\nQuelle attaque veux-tu utiliser ?\n";
			int answer2;
			answer2 = inputHandler();


			mainCharacter.Use(enemy, answer1-1, answer2-1);
			cout << "Il reste " << enemy.GetPV() << " PV a " << enemy.GetFullName() << endl;
		}
		else {
			mainCharacter.SetPV(mainCharacter.GetPV() + 20);
			cout << "Tu as desormais " << mainCharacter.GetPV() << " PV." << endl;
		}

		if (enemy.GetPV() > 0) {
			enemy.Use(mainCharacter, 0, 0);
			cout << "Il te reste " << mainCharacter.GetPV() << " PV." << endl;
		}
	}

	if (mainCharacter.GetPV() <= 0) {
		cout << "Le combat est termine !\n";
		cout << "Game Over !\n";
		return;
	}
	else if (enemy.GetPV() <= 0){
		cout << "Le combat est termine !\n";
		cout << "Tu as vaincu " << enemy.GetFullName() << endl;
		mainCharacter.Loot(enemy);
		return;
	}

}


void PlayerConfiguration() {
	cout << "-- Bienvenue dans ce simulateur DnD ! --\n";
	cout << "Tu dois d'abord te creer un personnage.\n";
	cout << "\nQuel est ton prenom ?\n";
	string firstName;
	getline(cin, firstName);
	cout << "\nQuel est ton nom de famille ?\n";
	string lastName;
	getline(cin, lastName);
	cout << "\nQuelle est ta phrase d'accroche ?\n";
	string description;
	getline(cin, description);
	cout << "\nCombien as-tu d'argent ?\n";
	long int money;
	money = inputHandler();

	mainCharacter = Character(firstName, lastName, description, 100, vector<Attack> {brulure, percee}, money, vector<Weapon> {sword, bow}, Race::Human, Job::Warrior);
	mainCharacter.Introduction();
}