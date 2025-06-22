#include "unit.h"
#include "Game.h"

unit::unit(int id, int join_time, int health,int power, int attack_capacity, Game* game, Type type)
{
	this->id = id;
	this->type = type;
	this->join_time = join_time;
	this->health = health;
	initial_health = health;
	this->power = power;
	this->attack_capacity = attack_capacity;
	pGame = game;
	first_attacked_time = -1;
}

int unit::GetTa()
{
    return first_attacked_time;
}

int unit::GetTj()
{
	return join_time;
}

int unit::GetTd()
{
	return destruction_time;
}

void unit::SetTd(int val)
{
	destruction_time = val;
}

bool unit::dead()
{
	if (health <= 0)
	{
		destruction_time = pGame->GetTime();
		return true;
	}
	else return false;
	
}

Type unit::UnitType()
{
	return type;
}

void unit::damage(unit* ptr)
{
	ptr->health -= (power * health / 100) / sqrt(ptr->health);
    if (ptr -> first_attacked_time == -1) ptr->first_attacked_time = pGame->GetTime();
}

int unit::getHealth()
{
	return health;
}

int unit::Capacity()
{
	return attack_capacity;
}

int unit::IntialHealth()
{
	return initial_health;
}

int unit::Power()
{
	return power;
}

void unit::IncrementHealth(int val)
{
	health += val;
}


int unit::GetId()
{
	return id;
}


Game* unit::gamePtr()
{
	return pGame;
}


unit::~unit()
{ 
	
}

ostream& operator<<(ostream& out, unit*& Unit)
{
	out << Unit->GetId();
	return out;
}
