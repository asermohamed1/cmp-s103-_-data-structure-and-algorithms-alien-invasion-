#pragma once

#include "unit.h"
class Gunnery:public unit
{
private:
public:
	Gunnery(int id, int join_time, Health health,int power, int attack_capacity, Type type = gunnery);
	int priority();
	void attack(unit* ptr);

};

