#include "Health.h"

Health::Health(int hlth)
{
	health = hlth;
	initial_health = hlth;
}

Health::operator int()
{
	return health;
}

void Health::operator-=(int val)
{
	health -= val;
	if (health < 0) health = 0;
}
 

void Health::operator+=(int val)
{
	health += val;
	if (health > 100) health = 100;
}

void Health::operator/=(int val)
{
	health /= val;
}

void Health::operator=(int val)
{
	if (val > 100) health = 100;
	else if (val < 0) health = 0;
	else health = val;
}

bool Health::operator==(int val)
{
	return (health == val);
}

int Health::get_health()
{
	return health;
}

int Health::get_initial_health()
{
	return initial_health;
}
