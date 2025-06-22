#pragma once

#include "unit.h"

#ifndef _Earth_Soldier_
#define _Earth_Soldier_

class earthSoldier:public unit
{
private:
	int MaintenanceTime; //the Time for the unit uf Moved to a Heal list
public:
	earthSoldier(int id, int join_time,int health, int power, int attack_capacity, Game* game, Type type = soldier);
	void setMaintenanceTime(int val);
	int GetMaintenance();
	void attack();
};

#endif // !_Earth_Soldier_
