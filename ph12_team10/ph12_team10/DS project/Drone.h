#pragma once

#include "unit.h"

class Drone:public unit
{
private:
public:
	Drone(int id, int join_time, Health health, int power, int attack_capacity, Type type = drone);
	void attack(unit* ptr);
};

