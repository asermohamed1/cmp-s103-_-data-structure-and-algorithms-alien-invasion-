#pragma once

#include "unit.h"

class alienSoldier:public unit
{
private:
public:
	alienSoldier(int id, int join_time, Health health, int power, int attack_capacity, Type type = alien_solider);
	void attack(unit* ptr);
};

