#pragma once

#include "unit.h"

#ifndef _Gunnery_
#define _Gunnery_

class Gunnery:public unit
{
private:
public:
	Gunnery(int id, int join_time,int  health, int power, int attack_capacity, Game* game, Type type = gunnery);
	int priority();
	void attack();

};
#endif // !_Gunnery_

