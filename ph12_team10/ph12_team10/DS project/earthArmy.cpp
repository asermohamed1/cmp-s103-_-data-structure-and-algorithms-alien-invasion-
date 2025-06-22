#include "earthArmy.h"

void earthArmy::AddTank(unit* tank)
{
	Tanks.push(tank);
}

bool earthArmy::GetTank(unit*& tank)
{
	if (Tanks.isEmpty())
	   return false;
	Tanks.pop(tank);
	return true;
}

void earthArmy::AddSoldier(unit* soldier)
{
	earthSoldiers.enqueue(soldier);
}

bool earthArmy::GetSoldier(unit*& soldier)
{
	if (earthSoldiers.isEmpty())
		return false;
	earthSoldiers.dequeue(soldier);
	return true;
}

void earthArmy::AddGunnery(unit* gunnery)
{
	int pri = ((Gunnery*)gunnery)->priority();
	EGunnery.enqueue(gunnery, pri);
}

bool earthArmy::GetGunnery(unit*& gunnery,int pri)
{
	if (EGunnery.isEmpty())
		return false;
	EGunnery.dequeue(gunnery,pri);
	return true;
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

void earthArmy::fileSoldiers(ofstream& Outfile)
{
	unit* temp; LinkedQueue<unit*> tempQueue; int count = 0;
	while (GetSoldier(temp)) { tempQueue.enqueue(temp); count++; }
	if (count != 0)
	{
		Outfile << count << " ES [";
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

void earthArmy::fileTanks(ofstream& Outfile)
{
	unit* temp; ArrayStack<unit*> tempStack; int count = 0;
	while (GetTank(temp)) { tempStack.push(temp); count++; }
	if (count != 0)
	{
		Outfile << count << " ES [";
		while (!tempStack.isEmpty())
		{
			tempStack.pop(temp);
			Outfile << temp->GetId();
			AddTank(temp);
			if (tempStack.isEmpty()) { Outfile << "]" << endl; }
			else { Outfile << ","; }
		}
	}
}

void earthArmy::fileGunnery(ofstream& Outfile)
{
	unit* temp; int pri = 0; priQueue<unit*> tempQueue; int count = 0;
	while (GetGunnery(temp, pri)) { tempQueue.enqueue(temp, pri); count++; }
	if (count != 0)
	{
		Outfile << count << " EG [";
		while (!tempQueue.isEmpty())
		{
			tempQueue.dequeue(temp, pri);
			Outfile << temp->GetId();
			AddGunnery(temp);
			if (tempQueue.isEmpty()) { Outfile << "]" << endl; }
			else { Outfile << ","; }
		}
	}
}



earthArmy::~earthArmy()
{
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
}
