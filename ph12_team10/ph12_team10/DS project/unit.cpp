#include "unit.h"


unit::unit(int id, int join_time, Health health,int power, int attack_capacity, Type type)
{
	this->id = id;
	this->type = type;
	this->join_time = join_time;
	this->health = health;
	this->power = power;
	this->attack_capacity = attack_capacity;
}

bool unit::dead()
{
	return health == 0;
}

Type unit::UnitType()
{
	return type;
}

void unit::damage(unit* ptr)
{
	health -= ((ptr->power * ptr->health) / 100) / sqrt(int(health));
}

int unit::getHealth()
{
	return health;
}

void unit::damage(int val)
{
	health -= val;
}

int unit::GetId()
{
	return id;
}
