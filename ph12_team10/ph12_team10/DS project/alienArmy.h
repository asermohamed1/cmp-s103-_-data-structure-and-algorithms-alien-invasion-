#pragma once


#include <iostream>
#include <fstream>
#include "unit.h"
#include "Monster.h"
#include "doubleEndedQueue.h"
#include "LinkedQueue.h"
#include "ArrayStack.h"
using namespace std;

class alienArmy
{
	int top;
	enum {max_size = 1000};
private:
	Monster* Monsters[max_size];
	LinkedQueue<unit*> alienSoldiers;
	doubleEndedQueue<unit*> Drones;
public:
	alienArmy();
	void AddMonster(unit* monster);
	bool GetMonster(unit*& monster);
	void AddSoldier(unit* soldier);
	bool GetSoldier(unit*& soldier);
	void AddDrone(unit* drone);
	bool GetFrontDrone(unit*& drone1);
	bool GetBackDrone(unit*& drone1);

	void printMonsters();
	void printSoldiera();
	void printDrones();

	void fileMonsters(ofstream& Outfile);
	void fileSoldiers(ofstream& Outfile);
	void fileDrones(ofstream& Outfile);
	~alienArmy();
};

