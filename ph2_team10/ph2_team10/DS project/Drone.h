#pragma once

#include "unit.h"

#ifndef _Drones_
#define _Drones_


class Drone:public unit
{
private:
public:
	Drone(int id, int join_time,int health, int power, int attack_capacity, Game* game, Type type = drone);
	void attack();
};
#endif // !_Drones_


