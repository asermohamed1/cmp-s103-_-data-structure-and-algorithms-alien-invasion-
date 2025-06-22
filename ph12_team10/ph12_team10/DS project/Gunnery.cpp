#include "Gunnery.h"

Gunnery::Gunnery(int id, int join_time, Health health,int power, int attack_capacity, Type type):unit(id,join_time,health,power,attack_capacity,type)
{
}

int Gunnery::priority()
{
	return health + power;
}

void Gunnery::attack(unit* ptr)
{
}
