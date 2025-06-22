#include "earthSoldier.h"
#include "Game.h"


earthSoldier::earthSoldier(int id, int join_time,int health, int power, int attack_capacity, Game* game, Type type) :unit(id, join_time, health, power, attack_capacity, game, type)
{
}

void earthSoldier::setMaintenanceTime(int val)
{
	MaintenanceTime = val;
}

int earthSoldier::GetMaintenance()
{
	return MaintenanceTime;
}

void earthSoldier::attack()
{
	LinkedQueue<unit*> tempQueue;
	for (int i = 0;i < Capacity();i++) 
	{
		unit* Unit;
		if (gamePtr()->GetAlienArmy().GetSoldier(Unit)) { tempQueue.enqueue(Unit); damage(Unit); } //Attack Alien Soldiers if Any 
		else break; // else Stop
	}

	if (gamePtr()->GetMode() == NormalMode && !tempQueue.isEmpty()) //Print The Attacked List
	{
		cout << GetId() << " ES shots ";
		tempQueue.print();
		cout << endl;
	}



	while (!tempQueue.isEmpty())
	{
		unit* Unit;
		tempQueue.dequeue(Unit);
		if (Unit->dead()) gamePtr()->InforemDead(Unit); //Check if the Enamy is Dead (if -> Move it to the Killed List else -> return to its original List)
		else gamePtr()->GetAlienArmy().AddSoldier(Unit);
	}

}
