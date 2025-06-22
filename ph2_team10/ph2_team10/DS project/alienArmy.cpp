#include "alienArmy.h"

alienArmy::alienArmy()
{
	top = -1;
}

void alienArmy::AddMonster(unit* monster) //Add a Monster
{
	Monsters[++top] = (Monster*)monster;
}
bool alienArmy::GetMonster(unit*& monster) //Get a Random Monster
{
	if (top == -1)
	  return false;
	int index = std::rand() % (top + 1);
	monster = Monsters[index];
	Monsters[index] = Monsters[top];
	Monsters[top] = nullptr;
	top--;
	return true;
}

void alienArmy::AddSoldier(unit* soldier) // Add a Soldier
{
	alienSoldiers.enqueue(soldier);
}

bool alienArmy::GetSoldier(unit*& soldier) // Get a soldier
{
	if (alienSoldiers.isEmpty())
		return false;
	alienSoldiers.dequeue(soldier);
	return true;
}

void alienArmy::AddDrone(unit* drone) //Add A Drone
{
	Drones.enqueueBack(drone);
}

bool alienArmy::GetFrontDrone(unit*& drone) //Get the Front Drone
{
	if (Drones.isEmpty())
		return false;
	Drones.dequeueFront(drone);
	return true;
}

bool alienArmy::GetBackDrone(unit*& drone) //Get the Back Drone
{
	if (Drones.isEmpty())
		return false;
	Drones.dequeueBack(drone);
	return true;
}

void alienArmy::Attack()
{
	if (top != -1) //Get A Random Monster And let it Attack
	{
	    int index = std::rand() % (top + 1);
		Monsters[index]->attack();
	}
	unit* Unit;
	if(alienSoldiers.peek(Unit)) Unit->attack(); //peek the soldiers and let it Attack
	unit* unit1,* unit2;
	if (Drones.PeekFront(unit1) && Drones.PeekBack(unit2))
	{
		if (unit1 != unit2) //Attacking only if there is Two Drones
		{
			unit1->attack();
			unit2->attack();
		}
	}
}


void alienArmy::printMonsters()
{
	if (top == -1) return;
	cout << top + 1 << " AM [";
	for (int i = 0;i <= top;i++)
	{
		cout << Monsters[i]->GetId();
		if (i == top) cout << "]" << endl;
		else cout << ","; 
	}
}

void alienArmy::printSoldiera()
{
	if (alienSoldiers.size() != 0)
	{
		cout << alienSoldiers.size() << " AS ";
		alienSoldiers.print(); cout << endl;
	}
}

void alienArmy::printDrones()
{
	if (Drones.size() != 0)
	{
		cout << Drones.size() << " AD ";
		Drones.print(); cout << endl;
	}
}

int alienArmy::GetSoldierCount()
{
	return alienSoldiers.size();
}

int alienArmy::GetMonsterCount()
{
	return top + 1;
}

int alienArmy::GetDroneCount()
{
	return Drones.size();
}

alienArmy::~alienArmy()
{
	//delete All the Remaining Alive Units After the Simulation is Done
	unit* temp;
	while (!alienSoldiers.isEmpty())
	{
		alienSoldiers.dequeue(temp);
		delete temp;
	}
	while (!Drones.isEmpty())
	{
		Drones.LinkedQueue<unit *>::dequeue(temp);
		delete temp;
	}
	for (int i = 0;i <= top;i++)
	{
		if (Monsters[i])
			delete Monsters[i];
	}
}
