#pragma once

#include <iostream>
#include <fstream>
#include "unit.h"
#include "LinkedQueue.h"
#include "priQueue.h"
#include "ArrayStack.h"
#include "Gunnery.h"
using namespace std;

class earthArmy
{
private:
	LinkedQueue<unit*> earthSoldiers;
	ArrayStack<unit*> Tanks;
	priQueue<unit*> EGunnery;
public:
	void AddTank(unit* tank);
	bool GetTank(unit*&tank);
	void AddSoldier(unit* soldier);
	bool GetSoldier(unit*& soldier);
	void AddGunnery(unit* gunnery);
	bool GetGunnery(unit*& gunnery,int pri = 0);

	void printSoldiers();
	void printTanks();
	void printEGunerry();

	void fileSoldiers(ofstream& Outfile);
	void fileTanks(ofstream& Outfile);
	void fileGunnery(ofstream& Outfile);

	~earthArmy();
};

