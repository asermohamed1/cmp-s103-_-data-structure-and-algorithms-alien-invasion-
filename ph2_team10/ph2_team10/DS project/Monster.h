#pragma once

#include "unit.h"

#ifndef _Monster_
#define _Monster_

class Monster:public unit
{
private:
public:
	Monster(int id, int join_time,int health, int power, int attack_capacity, Game* game, Type type = monster);
	void attack();
};
#endif // !_Monster_

