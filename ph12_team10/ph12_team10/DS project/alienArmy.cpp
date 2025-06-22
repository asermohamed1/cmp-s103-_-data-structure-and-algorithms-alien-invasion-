#include "alienArmy.h"

alienArmy::alienArmy()
{
	top = -1;
}

void alienArmy::AddMonster(unit* monster)
{
	Monsters[++top] = (Monster*)monster;
}
bool alienArmy::GetMonster(unit*& monster)
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

void alienArmy::AddSoldier(unit* soldier)
{
	alienSoldiers.enqueue(soldier);
}

bool alienArmy::GetSoldier(unit*& soldier)
{
	if (alienSoldiers.isEmpty())
		return false;
	alienSoldiers.dequeue(soldier);
	return true;
}

void alienArmy::AddDrone(unit* drone)
{
	static int i = 0;
	if (i % 2 == 0)
		Drones.enqueueBack(drone);
	else
		Drones.dequeueFront(drone);
}

bool alienArmy::GetFrontDrone(unit*& drone)
{
	if (Drones.isEmpty())
		return false;
	Drones.dequeueFront(drone);
	return true;
}

bool alienArmy::GetBackDrone(unit*& drone)
{
	if (Drones.isEmpty())
		return false;
	Drones.dequeueBack(drone);
	return true;
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

void alienArmy::fileMonsters(ofstream& Outfile)
{
	if (top == -1) return;
	Outfile << top + 1 << " AM [";
	for (int i = 0;i <= top;i++)
	{
		Outfile << Monsters[i]->GetId();
		if (i == top) { Outfile << "]" << endl; }
		else { Outfile << ","; }
	}
}

void alienArmy::fileSoldiers(ofstream& Outfile)
{
	unit* temp; LinkedQueue<unit*> tempQueue; int count = 0;
	while (GetSoldier(temp)) { tempQueue.enqueue(temp); count++; }
	if (count != 0)
	{
		Outfile << count << " AS [";
		while (!tempQueue.isEmpty())
		{
			tempQueue.dequeue(temp);
			Outfile << temp->GetId();
			AddSoldier(temp);
			if (tempQueue.isEmpty()) { Outfile << "]" << endl; }
			else { Outfile << ","; }
		}
	}
}

void alienArmy::fileDrones(ofstream& Outfile)
{
	unit* temp; LinkedQueue<unit*> tempQueue; int count = 0;
	while (GetFrontDrone(temp)) { tempQueue.enqueue(temp); count++; }
	if (count != 0)
	{
		Outfile << count << " AD [";
		while (!tempQueue.isEmpty())
		{
			tempQueue.dequeue(temp);
			Outfile << temp->GetId();
			AddDrone(temp);
			if (tempQueue.isEmpty()) { Outfile << "]" << endl; }
			else { Outfile << ","; }
		}
	}
}


alienArmy::~alienArmy()
{
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
