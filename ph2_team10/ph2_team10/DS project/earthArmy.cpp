#include "earthArmy.h"
#include "HealthUnit.h"

earthArmy::earthArmy()
{
	Successfuly_healed = 0;
}

void earthArmy::AddHealthUnit(unit* health) // Add A health Unit
{
	HealthUnits.push(health); 
}

void earthArmy::AddTank(unit* tank) // Add a Tank
{
	Tanks.push(tank); 
}

bool earthArmy::GetTank(unit*& tank) // Get A Tank
{
	if (Tanks.isEmpty())
	   return false;
	Tanks.pop(tank);
	return true;
}

void earthArmy::AddSoldier(unit* soldier) // Add a Soldier
{
	earthSoldiers.enqueue(soldier);
}

bool earthArmy::GetSoldier(unit*& soldier) // Get a Soldier
{
	if (earthSoldiers.isEmpty())
		return false;
	earthSoldiers.dequeue(soldier);
	return true;
}

void earthArmy::AddGunnery(unit* gunnery) // Add a Gunnery
{
	int pri = ((Gunnery*)gunnery)->priority();
	EGunnery.enqueue(gunnery, pri);
}

bool earthArmy::GetGunnery(unit*& gunnery,int pri) // Get a Gunnery
{
	if (EGunnery.isEmpty())
		return false;
	EGunnery.dequeue(gunnery,pri);
	return true;
}

void earthArmy::AddDamgedSoldier(unit* soldier) 
{
	SoldierMaintenanceList.enqueue(soldier,1000-soldier->getHealth()); // Add a damaged Soldiers "pri -> 1000-health -> damage"
}

bool earthArmy::GetDamgedSoldier(unit*& soldier) // Get Damaged Soldiers
{
	int pri;
	if (SoldierMaintenanceList.isEmpty())
		return false;
	SoldierMaintenanceList.dequeue(soldier,pri);
	return true;
}

void earthArmy::AddDamgedTank(unit* tank)
{
	TankMaintenanceList.enqueue(tank); // Add a damaged Tanks "pri -> FIFO"
}


bool earthArmy::GetDamgedTank(unit*& tank)  // Get Damaged Tanks
{
	if (TankMaintenanceList.isEmpty())
		return false;
	TankMaintenanceList.dequeue(tank);
	return true;
}

int earthArmy::Healed()
{
	return Successfuly_healed;
}

void earthArmy::Attack()
{
	//Peek All the Earth Units And let them Attack
	unit* unit; int temp;
	if (earthSoldiers.peek(unit)) unit->attack();
	if (Tanks.peek(unit)) unit->attack();
	if (EGunnery.peek(unit, temp)) unit->attack();

	//Heal the units and incrment the Successfuly Heald Units
	if (SoldierMaintenanceList.size() + TankMaintenanceList.size() > 0)
	if (HealthUnits.pop(unit)) { unit->attack(); Successfuly_healed += ((HealthUnit*)unit)->GetHealedUnits(); }
}

void earthArmy::printSoldiers()
{
	if (earthSoldiers.size() != 0)
	{
		cout << earthSoldiers.size() << " ES ";
		earthSoldiers.print(); cout << endl;
	}
}

void earthArmy::printTanks()
{
	if (Tanks.size() != 0)
	{
		cout << Tanks.size() << " ET ";
		Tanks.print(); cout << endl;
	}
}

void earthArmy::printEGunerry()
{
	if (EGunnery.size() != 0)
	{
		cout << EGunnery.size() << " EG ";
		EGunnery.print(); cout << endl;
	}
}

void earthArmy::printHealthList()
{
	if (HealthUnits.size() != 0)
	{
		cout << HealthUnits.size(); cout << " HL ";
		HealthUnits.print(); cout << endl;
	}
}

void earthArmy::printUML()
{
	if (SoldierMaintenanceList.size() != 0)
	{
		cout << SoldierMaintenanceList.size(); cout << " Soldiers_UML ";
		SoldierMaintenanceList.print(); cout << endl;
	}
	if (TankMaintenanceList.size() != 0)
	{
		cout << TankMaintenanceList.size(); cout << " Tanks_UML ";
		TankMaintenanceList.print(); cout << endl;
	}
}


int earthArmy::GetSoldierCount()
{
	return earthSoldiers.size();
}

int earthArmy::GetGunneryCount()
{
	return EGunnery.size();
}

int earthArmy::GetTankCount()
{
	return Tanks.size();
}

earthArmy::~earthArmy()
{
	//delete All the Remaining Alive Units After the Simulation is Done
	unit* temp;
	while (!earthSoldiers.isEmpty())
	{
		earthSoldiers.dequeue(temp);
		delete temp;
	}
	while (!Tanks.isEmpty())
	{
		Tanks.pop(temp);
		delete temp;
	}
	while (!EGunnery.isEmpty())
	{
		int pri;
		EGunnery.dequeue(temp,pri);
		delete temp;
	}
	while (!HealthUnits.isEmpty())
	{
		HealthUnits.pop(temp);
		delete temp;
	}
	while (!SoldierMaintenanceList.isEmpty())
	{
		int pri;
		SoldierMaintenanceList.dequeue(temp, pri);
		delete temp;
	}
	while (!TankMaintenanceList.isEmpty())
	{
		TankMaintenanceList.dequeue(temp);
		delete temp;
	}
}
