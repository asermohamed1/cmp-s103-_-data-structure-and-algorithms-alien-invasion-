#pragma once

#include "unit.h"

class Monster:public unit
{
private:
public:
	Monster(int id, int join_time, Health health, int power, int attack_capacity, Type type = monster);
	void attack(unit* ptr);
};

