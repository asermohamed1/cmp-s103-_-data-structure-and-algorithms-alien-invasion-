#include "Drone.h"

Drone::Drone(int id, int join_time, Health health, int power, int attack_capacity, Type type):unit(id, join_time, health, power, attack_capacity, type)
{
}

void Drone::attack(unit* ptr)
{
}
