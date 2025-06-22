#pragma once


#include <iostream>
#include <fstream>
#include "unit.h"
#include "Monster.h"
#include "doubleEndedQueue.h"
#include "LinkedQueue.h"
#include "ArrayStack.h"
using namespace std;

#ifndef _Alien_Army_
#define _Alien_Army_



class alienArmy
{
	int top;
	enum {max_size = 1000};
private:
	//Units lists
	Monster* Monsters[max_size]; 
	LinkedQueue<unit*> alienSoldiers;
	doubleEndedQueue<unit*> Drones;
public:
	alienArmy();

	//Adders and Getters for the Units
	void AddMonster(unit* monster);
	bool GetMonster(unit*& monster);
	void AddSoldier(unit* soldier);
	bool GetSoldier(unit*& soldier);
	void AddDrone(unit* drone);
	bool GetFrontDrone(unit*& drone1);
	bool GetBackDrone(unit*& drone1);

	//All alien Units Attacking
	void Attack();

	//Print the Units IDs 
	void printMonsters();
	void printSoldiera();
	void printDrones();

	//Getters for The Counts
	int GetSoldierCount();
	int GetMonsterCount();
	int GetDroneCount();
   
	~alienArmy();
};
#endif // !_Alien_Army_
