#pragma once

#include <iostream>
#include <fstream>
#include "unit.h"
#include "LinkedQueue.h"
#include "priQueue.h"
#include "ArrayStack.h"
#include "Gunnery.h"
using namespace std;

#ifndef _Earth_Army_
#define _Earth_Army_



class earthArmy
{
private:
	LinkedQueue<unit*> earthSoldiers; //Soldiers
	ArrayStack<unit*> Tanks; //Tanks
	priQueue<unit*> EGunnery; //EGunnery

	//lists Added for Health Units
	priQueue<unit*> SoldierMaintenanceList;
	LinkedQueue<unit*> TankMaintenanceList;
	ArrayStack<unit*> HealthUnits;
	
	//the Total Healed Units "By all Health Units"
	int Successfuly_healed;
public:
	earthArmy();
	void AddHealthUnit(unit *health);

	//Adders and Getters for the Units
	void AddTank(unit* tank);
	bool GetTank(unit*&tank);
	void AddSoldier(unit* soldier);
	bool GetSoldier(unit*& soldier);
	void AddGunnery(unit* gunnery);
	bool GetGunnery(unit*& gunnery,int pri = 0);

	//Adders and Getters for the Damged Units
	void AddDamgedSoldier(unit* soldier);
	bool GetDamgedSoldier(unit*& soldier);
	void AddDamgedTank(unit* tank);
	bool GetDamgedTank(unit*& tank);

	//Get the All Healed Units
	int Healed();

	//All earth Units Attacking
	void Attack();

	//Print the Units IDs 
	void printSoldiers();
	void printTanks();
	void printEGunerry();
	void printHealthList();
	void printUML();


	//Getters for The Counts
	int GetSoldierCount();
	int GetGunneryCount();
	int GetTankCount();


	~earthArmy();
};
#endif // !_Earth_Army_
