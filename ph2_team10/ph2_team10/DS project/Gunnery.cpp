#include "Gunnery.h"
#include "Game.h"


Gunnery::Gunnery(int id, int join_time,int health, int power, int attack_capacity, Game* game, Type type) :unit(id, join_time, health, power, attack_capacity, game, type)
{
}

int Gunnery::priority()
{
	return getHealth() + Power();
}

void Gunnery::attack()
{
	LinkedQueue<unit*> tempQueue;
	for (int i = 0;i < Capacity();i++)
	{
		unit* unit1, * unit2,* Unit;
		if (i % 2 == 0) //Attack Monsters if Any else Attack 2 Drones
		{
			
			if (gamePtr()->GetAlienArmy().GetMonster(Unit)) { tempQueue.enqueue(Unit); damage(Unit); }
			else if (gamePtr()->GetAlienArmy().GetFrontDrone(unit1))
			{
				if (gamePtr()->GetAlienArmy().GetBackDrone(unit2))
				{
					tempQueue.enqueue(unit1); tempQueue.enqueue(unit2); damage(unit1); damage(unit2);
				}
				else
				{
					tempQueue.enqueue(unit1); damage(unit1);
				}
			}
			else break; //If No More Enamy Stop
		}
		else //Reverse it to be Attack 2 Drones if Any else Attack Monsters (this Way the Capacity is divded by half betweem the Drones and the Monsters)
		{
			
			if (gamePtr()->GetAlienArmy().GetFrontDrone(unit1))
			{
				if (gamePtr()->GetAlienArmy().GetBackDrone(unit2))
				{
					tempQueue.enqueue(unit1); tempQueue.enqueue(unit2); damage(unit1); damage(unit2);
				}
				else
				{
					tempQueue.enqueue(unit1); damage(unit1);
				}
			}
			else if (gamePtr()->GetAlienArmy().GetMonster(Unit)) { tempQueue.enqueue(Unit); damage(Unit); }
			else break; //If No More Enamy Stop
		}
	}

	if (gamePtr()->GetMode() == NormalMode && !tempQueue.isEmpty()) //Print the Attacked
	{
		cout << GetId() << " EG shots ";
		tempQueue.print();
		cout << endl;
	}

	while (!tempQueue.isEmpty())
	{
		unit* Unit;
		tempQueue.dequeue(Unit);
		if (Unit->dead()) gamePtr()->InforemDead(Unit); // Check if dead (if-> Move it ti the Killed List else -> check its Type and return it its original List) 
		else if (Unit->UnitType() == monster) gamePtr()->GetAlienArmy().AddMonster(Unit);
		else gamePtr()->GetAlienArmy().AddDrone(Unit); //Drones
	}

}
