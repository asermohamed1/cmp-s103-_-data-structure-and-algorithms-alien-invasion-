#include "Game.h"

Game::Game()
{
	timeStep = 1;
	try
	{
		if (!ReadFile()) throw "err";
	}
	catch (...)
	{
		cout << "No file Found";
	}
}

void Game::Generate()
{
	Generator.Generate(eArmy, aArmy,timeStep);
}

bool Game::ReadFile()
{
	input.open("Input.txt");
	if (!input.is_open()) return false;
	int val;
	input >> val; Generator.SetNumodUnits(val);
	input >> val; Generator.SetES(val); input >> val; Generator.SetET(val); input >> val; Generator.SetEG(val);
	input >> val; Generator.SetAS(val); input >> val; Generator.SetAM(val); input >> val; Generator.SetAD(val);
	input >> val; Generator.Setprop(val);


	int vals[2];
	input >> vals[0]; input.ignore(); input >> vals[1]; Generator.SetEpowerRange(vals);
	input >> vals[0]; input.ignore(); input >> vals[1]; Generator.SetEhealthRange(vals);
	input >> vals[0]; input.ignore(); input >> vals[1]; Generator.SetEcapacityRange(vals);
	input >> vals[0]; input.ignore(); input >> vals[1]; Generator.SetApowerRange(vals);
	input >> vals[0]; input.ignore(); input >> vals[1]; Generator.SetAhealthRange(vals);
	input >> vals[0]; input.ignore(); input >> vals[1]; Generator.SetAcapacityRange(vals);

	return true;
}



void Game::TestCode()
{
	int x = Generator.Random_num(101) - 1;
	unit* temp;
	if (x <= 10)
	{
		if (eArmy.GetSoldier(temp))
		{
			eArmy.AddSoldier(temp);
			cout << "----------------------"<< endl <<"Earth Soldier is Removed and Added again" << endl << "----------------------" << endl;
		}
	}
	else if (x <= 20)
	{
		if (eArmy.GetTank(temp))
		{
			KilledUnits.enqueue(temp);
			cout << "----------------------" << endl << "A tank is Moved to A killed Units list" << endl << "----------------------" << endl;
		}
	}
	else if (x <= 30)
	{
		if (eArmy.GetGunnery(temp))
		{
			temp->damage(temp->getHealth() / 2);
			eArmy.AddGunnery(temp);
			cout << "----------------------" << endl << "An EGunerry helath has been halfed" << endl << "----------------------" << endl;
		}
	}
	else if (x <= 40)
	{
		LinkedQueue<unit*> tempQueue; int i = 0;
		while (aArmy.GetSoldier(temp) && i < 5)
		{
			tempQueue.enqueue(temp);
			i++;
		}
		while (!tempQueue.isEmpty())
		{
			tempQueue.dequeue(temp);
			temp->damage(10);
			if (temp->dead()) KilledUnits.enqueue(temp);
			else aArmy.AddSoldier(temp);
		}
		if (i != 0) cout << "----------------------" << endl << i << " earth Soldiers have been damaged by 10" << endl << "----------------------" << endl;
	}
	else if (x <= 50)
	{
		LinkedQueue<unit*> tempQueue; int i = 0;
		while (aArmy.GetMonster(temp) && i < 5)
		{
			tempQueue.enqueue(temp);
			i++;
		}
		while (!tempQueue.isEmpty())
		{
			tempQueue.dequeue(temp);
			aArmy.AddMonster(temp);
		}
		if (i != 0) cout << "----------------------" << endl << i << " Monsters have been moved to a templist and returned to their list" << endl << "----------------------" << endl;
	}
	else if (x <= 60)
	{
		int i;
		for (i = 0;i < 3;i++)
		{
			if (aArmy.GetFrontDrone(temp)) KilledUnits.enqueue(temp);
			else break;

			if (aArmy.GetBackDrone(temp)) KilledUnits.enqueue(temp);
			else break;
		}
		if (i >= 0) cout << "----------------------" << endl << "6 Drone/s or less have been moved to the killed list" << endl << "----------------------" << endl;
	}
}

void Game::SilentMode()
{
	int x = Generator.Random_num(101) - 1;
	unit* temp;
	if (x <= 10)
	{
		if (eArmy.GetSoldier(temp))
		{
			eArmy.AddSoldier(temp);
		}
	}
	else if (x <= 20)
	{
		if (eArmy.GetTank(temp))
		{
			KilledUnits.enqueue(temp);
		}
	}
	else if (x <= 30)
	{
		if (eArmy.GetGunnery(temp))
		{
			temp->damage(temp->getHealth() / 2);
			eArmy.AddGunnery(temp);
		}
	}
	else if (x <= 40)
	{
		LinkedQueue<unit*> tempQueue; int i = 0;
		while (aArmy.GetSoldier(temp) && i < 5)
		{
			tempQueue.enqueue(temp);
			i++;
		}
		while (!tempQueue.isEmpty())
		{
			tempQueue.dequeue(temp);
			temp->damage(10);
			if (temp->dead()) KilledUnits.enqueue(temp);
			else aArmy.AddSoldier(temp);
		}
	}
	else if (x <= 50)
	{
		LinkedQueue<unit*> tempQueue; int i = 0;
		while (aArmy.GetMonster(temp) && i < 5)
		{
			tempQueue.enqueue(temp);
			i++;
		}
		while (!tempQueue.isEmpty())
		{
			tempQueue.dequeue(temp);
			aArmy.AddMonster(temp);
		}
	}
	else if (x <= 60)
	{
		int i;
		for (i = 0;i < 3;i++)
		{
			if (aArmy.GetFrontDrone(temp)) KilledUnits.enqueue(temp);
			else break;

			if (aArmy.GetBackDrone(temp)) KilledUnits.enqueue(temp);
			else break;
		}
	}
}




void Game::Print()
{
	Outfile.open("output.txt");
	
	cout << "Current Timestep " << timeStep << endl;
	Outfile << "Current Timestep " << timeStep << endl;
	cout << endl;

	cout << "Earth Army Alive Units" << endl;
	Outfile << "Earth Army Alive Units" << endl;
    eArmy.printSoldiers();
	eArmy.printTanks();
	eArmy.printEGunerry();
	cout << endl << endl << endl;

	cout << "Alien Army Alive Units" << endl;
	Outfile << "Alien Army Alive Units" << endl;
	aArmy.printSoldiera();
	aArmy.printMonsters();
	aArmy.printDrones();
	cout << endl << endl << endl;



	cout << "Killed Units" << endl;
	Outfile << "Killed Units" << endl;
	printKilledUnits();
	cout << endl << endl << endl;



	Outfile.close();
}

void Game::OutFile()
{
	Outfile.open("output.txt");


	Outfile << "Current Timestep " << timeStep << endl;
	

	
	Outfile << "Earth Army Alive Units" << endl;
	eArmy.fileSoldiers(Outfile);
	eArmy.fileTanks(Outfile);
	eArmy.fileGunnery(Outfile);


	Outfile << "Alien Army Alive Units" << endl;
	aArmy.fileSoldiers(Outfile);
	aArmy.fileMonsters(Outfile);
	aArmy.fileDrones(Outfile);



	Outfile << "Killed Units" << endl;
	fileKilledUnits(Outfile);


	Outfile.close();
}

void Game::NextTimeStep()
{
	timeStep++;
}

int Game::GetTime()
{
	return timeStep;
}

void Game::printKilledUnits()
{
	if (KilledUnits.size() != 0)
	{
		cout << KilledUnits.size() << " units ";
		KilledUnits.print(); cout << endl;
	}
}

void Game::fileKilledUnits(ofstream& Outfile)
{
	unit* temp; LinkedQueue<unit*> tempQueue; int count = 0;
	while (!KilledUnits.isEmpty())
	{
		KilledUnits.dequeue(temp);
		tempQueue.enqueue(temp); count++;
	}
	if (count != 0)
	{
		Outfile << count << " units [";
		while (!tempQueue.isEmpty())
		{
			tempQueue.dequeue(temp);
			Outfile << temp->GetId();
			KilledUnits.enqueue(temp);
			if (tempQueue.isEmpty()) { Outfile << "]" << endl; }
			else { Outfile << ","; }
		}
	}
}

Game::~Game()
{
	unit* temp;

	while (!KilledUnits.isEmpty())
	{
		KilledUnits.dequeue(temp);
		delete temp;
	}
}
