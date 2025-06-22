#pragma once

#include "unit.h"

class Tank:public unit
{
private:
public:
	Tank(int id, int join_time, Health health,int power, int attack_capacity, Type type = tank);
	void attack(unit* ptr);
};

