#pragma once
#include <string>
using namespace std;


class Creature
{
private:
	string mName;
	string mDescription;
	int mHP;
	int mDefense;
	//vector<Attack> mAttacks;

public:
	Creature(string name, string description, int hp, int defense/*, vector<Attack> attacks*/);
	Creature();
	~Creature();

	void Attack(Creature creature);
	void Heal(int hp);
	int GetHP();

};

