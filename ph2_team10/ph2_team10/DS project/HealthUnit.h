#include "unit.h"

#ifndef _Health_
#define _Health_



class HealthUnit:public unit
{
private:
	int Successfuly_healed; //Successfuly Helad Units Counters "BY THIS HEALTH UNIT"
public:
	HealthUnit(int id, int join_time, int health, int power, int attack_capacity, Game* game, Type type = Healing);
	
	
	void attack();
	void Heal(unit* Unit); //incremants the Health with maintioned Formula

	int GetHealedUnits(); //returns Successfuly Helad Units Counters
};
#endif // !_Health_