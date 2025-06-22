#include "Tank.h"
#include "Game.h"


Tank::Tank(int id, int join_time,int health,int power, int attack_capacity, Game* game,Type type) :unit(id, join_time, health, power, attack_capacity, game,type)
{
}

void Tank::setMaintenanceTime(int val)
{
	MaintenanceTime = val;
}

int Tank::GetMaintenance()
{
	return MaintenanceTime;
}





void Tank::attack()
{
	LinkedQueue<unit*> tempQueue;
	int count = 0;
	if (gamePtr()->GetEarthArmy().GetSoldierCount() < .3 * gamePtr()->GetAlienArmy().GetSoldierCount()) // if Eath Soliders lest than 30% of the Alien Soldiers
	{
		while (gamePtr()->GetEarthArmy().GetSoldierCount() < .8 * gamePtr()->GetAlienArmy().GetSoldierCount() && count < Capacity()) //start Attackin Soldiers While  Eath Soliders lest than 80% of the Alien Soldiers
		{
			unit* Unit;
			if (gamePtr()->GetAlienArmy().GetSoldier(Unit)) { tempQueue.enqueue(Unit); damage(Unit); count++; }
			else break;
		}
	}


	for (int i = count;i < Capacity();i++) //else Attack Monstiers
	{
		unit* Unit;
		if (gamePtr()->GetAlienArmy().GetMonster(Unit)) { tempQueue.enqueue(Unit); damage(Unit); }
		else break;
	}
	

	if (gamePtr()->GetMode() == NormalMode && !tempQueue.isEmpty()) //Print the Attacked Units
	{
		cout << GetId() << " ET shots ";
		tempQueue.print();
		cout << endl;
	}

	while (!tempQueue.isEmpty())
	{
		unit* Unit;
		tempQueue.dequeue(Unit);
		if (Unit->dead()) gamePtr()->InforemDead(Unit); // Check if dead (if-> Move it ti the Killed List else -> check its Type and return it its original List) 
		else if (Unit->UnitType() == monster) gamePtr()->GetAlienArmy().AddMonster(Unit);
		else gamePtr()->GetAlienArmy().AddSoldier(Unit); //Soldiers
	}

}
