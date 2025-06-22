#pragma once
#include "Health.h"
#include "cmath"
enum Type { soldier,tank,gunnery,alien_solider,monster,drone };


class unit
{
protected:
	int id;
	Type type;
	int join_time;
	Health health;
	int power;
	int attack_capacity;
public:
	unit(int id,int join_time,Health health,int power,int attack_capacity,Type type);
	virtual void attack(unit* ptr) = 0;
	bool dead();
	Type UnitType();
	void damage(unit* ptr);
	int getHealth();
	void damage(int val);
	int GetId();
};

