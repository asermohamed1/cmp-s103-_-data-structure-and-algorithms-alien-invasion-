#pragma once

#include "cmath"
#include "LinkedQueue.h"
enum Type { soldier,tank,gunnery,alien_solider,monster,drone,Healing };

class Game;

#ifndef _Unit_
#define _Unit_


class unit
{
private:
	int id;
	int destruction_time;
	int first_attacked_time;
	int join_time;
	int initial_health;
	int health;
	int power;
	int attack_capacity;
	Type type; // the type of the Unit
	Game* pGame; // Pointer to the Game // could be static sence its the same game pointer for all the Units
public:
	unit(int id,int join_time,int health,int power,int attack_capacity, Game* game,Type type);
	virtual void attack() = 0; // pure virtual attack function


	//Getters
	Type UnitType();
	int GetTa();
	int GetTj();
	int GetTd();
	int GetId();
	int getHealth();
	int Capacity();
	int IntialHealth();
	int Power();
	
	//Seters
	void SetTd(int val);


	 
	void damage(unit* ptr); //Decrement the Health with the Maintioned Formula
	bool dead(); //Checks if the Unit is dead


	void IncrementHealth(int val); //Increments the Health by the passed Value
	
	Game* gamePtr(); // returns the Game pointer

	~unit();
};
#endif // !_Unit_

ostream& operator<<(ostream& out, unit*& Unit); //OverRiding the << operator