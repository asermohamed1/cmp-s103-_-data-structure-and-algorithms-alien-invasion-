#pragma once

#include "unit.h"

class earthSoldier:public unit
{
private:
public:
	earthSoldier(int id, int join_time, Health health,int power, int attack_capacity, Type type = soldier);
	void attack(unit* ptr);
};

