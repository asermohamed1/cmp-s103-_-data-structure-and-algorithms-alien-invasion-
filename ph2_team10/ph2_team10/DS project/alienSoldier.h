#pragma once

#include "unit.h"

#ifndef _Alien_soldier_
#define _Alien_soldier_


class alienSoldier:public unit
{
private:
public:
	alienSoldier(int id, int join_time,int health, int power, int attack_capacity, Game* game, Type type = alien_solider);
	void attack();
};

#endif // !_Alien_soldier_
