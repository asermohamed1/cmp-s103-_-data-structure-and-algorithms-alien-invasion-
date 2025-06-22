#include "Monster.h"
#include "Game.h"

Monster::Monster(int id, int join_time,int health, int power, int attack_capacity, Game* game, Type type) :unit(id, join_time, health, power, attack_capacity, game, type)
{
}

void Monster::attack()
{
	LinkedQueue<unit*> tempQueue;
	
	
	for (int i = 0;i < Capacity();i++)
	{
		unit* Unit;
		if (i % 2 == 0) //Attack the Tanks if Any else Attack the Soldiers
		{
			if (gamePtr()->GetEarthArmy().GetTank(Unit)) { tempQueue.enqueue(Unit); damage(Unit); }
			else if (gamePtr()->GetEarthArmy().GetSoldier(Unit)) { tempQueue.enqueue(Unit); damage(Unit); }
			else break; //if No More Enemies Stop
		}
		else //Reverse it to be Attack the Soldiers if Any else Attack the Tanks (this Way the capaxity is halfed between tanks and Soldiers) 
		{
			if (gamePtr()->GetEarthArmy().GetSoldier(Unit)) { tempQueue.enqueue(Unit); damage(Unit); }
			else if (gamePtr()->GetEarthArmy().GetTank(Unit)) { tempQueue.enqueue(Unit); damage(Unit); }
			else break; //if No More Enemies Stop
		}
	}


	if (gamePtr()->GetMode() == NormalMode && !tempQueue.isEmpty()) //Print The Attacked List
	{
		cout << GetId() << " AM shots ";
		tempQueue.print();
		cout << endl;
	}


	while (!tempQueue.isEmpty())
	{
		unit* Unit;
		tempQueue.dequeue(Unit);
		if (Unit->dead()) gamePtr()->InforemDead(Unit); //Check if Dead (if -> move it to killed List else ->  check if Needed to heal and return to the right List)
		else if (Unit->UnitType() == tank) 
			if (Unit->getHealth() < .2 * Unit->IntialHealth()) gamePtr()->GetEarthArmy().AddDamgedTank(Unit);
			else gamePtr()->GetEarthArmy().AddTank(Unit);
		else if (Unit->UnitType() == soldier)
			if (Unit->getHealth() < .2 * Unit->IntialHealth()) gamePtr()->GetEarthArmy().AddDamgedSoldier(Unit);
			else gamePtr()->GetEarthArmy().AddSoldier(Unit);
	}

}
