#include "alienSoldier.h"
#include "Game.h"

alienSoldier::alienSoldier(int id, int join_time,int health, int power, int attack_capacity, Game* game, Type type) :unit(id, join_time, health, power, attack_capacity, game, type)
{
}

void alienSoldier::attack()
{
	LinkedQueue<unit*> tempQueue;
	for (int i = 0;i < Capacity();i++)
	{
		unit* Unit;
		if (gamePtr()->GetEarthArmy().GetSoldier(Unit)) { tempQueue.enqueue(Unit); damage(Unit); } //Attack Earth Soldiers if Any 
		else break;
	}

	if (gamePtr()->GetMode() == NormalMode && !tempQueue.isEmpty()) //Print The Attacked List
	{
		cout << GetId() << " AS shots ";
		tempQueue.print();
		cout << endl;
	}



	while (!tempQueue.isEmpty())
	{
		unit* Unit;
		tempQueue.dequeue(Unit);
		if (Unit->dead()) gamePtr()->InforemDead(Unit); //Check if the Enamy is Dead (if -> Move it to the Killed List else -> check if Needed to heal and return to the right List)
		else if (Unit->getHealth() < .2 * Unit->IntialHealth()) gamePtr()->GetEarthArmy().AddDamgedSoldier(Unit);
		else gamePtr()->GetEarthArmy().AddSoldier(Unit);
	}
}
