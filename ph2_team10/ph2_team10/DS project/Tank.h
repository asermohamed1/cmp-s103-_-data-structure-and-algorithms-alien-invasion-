#pragma once

#include "unit.h"


#ifndef _Tanks_
#define _Tanks_

class Tank:public unit
{
private:
	int MaintenanceTime; //the Time for the unit uf Moved to a Heal list
public:
	Tank(int id, int join_time,int health, int power, int attack_capacity, Game* game, Type type = tank);
	void setMaintenanceTime(int val);
	int GetMaintenance();
	void attack();
};
#endif // !_Tanks_
