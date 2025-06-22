#include "HealthUnit.h"
#include "earthArmy.h"
#include "Tank.h"
#include "Game.h"

HealthUnit::HealthUnit(int id, int join_time, int health, int power, int attack_capacity, Game* game, Type type) :unit(id, join_time, health, power, attack_capacity, game, type)
{
	Successfuly_healed = 0; //intialize the Healed Units to Zero
}

void HealthUnit::attack()
{
	LinkedQueue<unit*> tempQueue;
	for (int i = 0;i < Capacity();i++) // while Capacity
	{
		unit* Unit = nullptr;
		if (gamePtr()->GetEarthArmy().GetDamgedSoldier(Unit)) //priority to Healing Earth Soldiers
		{
			if (gamePtr()->GetTime() - ((earthSoldier*)Unit)->GetMaintenance() >= 10) //checking if passed 10 time steps
				gamePtr()->InforemDead(Unit);
			else
			{
				Heal(Unit);
				if (Unit->getHealth() >= .2 * Unit->IntialHealth()) { gamePtr()->GetEarthArmy().AddSoldier(Unit); Successfuly_healed++; } // check if Healed
				else tempQueue.enqueue(Unit);
			}
		}
		else if (gamePtr()->GetEarthArmy().GetDamgedTank(Unit)) //Else Heal Tanks
		{
			if (gamePtr()->GetTime() - ((Tank*)Unit)->GetMaintenance() >= 10) //checking if passed 10 time steps
				gamePtr()->InforemDead(Unit);
			else
			{
				Heal(Unit);
				if (Unit->getHealth() >= .2 * Unit->IntialHealth()) { gamePtr()->GetEarthArmy().AddTank(Unit); Successfuly_healed++; } // check if Healed
				else tempQueue.enqueue(Unit);
			}
		}

		else break; // if No units break
	}

	while (!tempQueue.isEmpty()) //Move the Units that Have Not Successfuly Heald to the Killed List
	{
		unit* Unit;
		tempQueue.dequeue(Unit); 
		gamePtr()->InforemDead(Unit);
	}

	gamePtr()->InforemDead(this); //Moving The Health Units To the killed List After it completed its journey
}

void HealthUnit::Heal(unit* Unit) //Increment the Unit Health
{
	Unit->IncrementHealth((getHealth() * Power() / 100) / sqrt(Unit->getHealth()));
}

int HealthUnit::GetHealedUnits()
{
	return Successfuly_healed;
}
