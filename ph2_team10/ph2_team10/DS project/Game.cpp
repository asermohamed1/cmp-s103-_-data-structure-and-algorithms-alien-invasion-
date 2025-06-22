#include "Game.h"


Game::Game(Mode mode)
{
	this->mode = mode; // initilizing the Mode
	timeStep = 1; // initilizing the time
	try
	{
		if (!ReadFile()) throw "err";
		// Read file if any 
		// else throw an error
	}
	catch (...)
	{
		cout << "No file Found";
	}
}

void Game::Generate()
{
	Generator.Generate(eArmy, aArmy,timeStep,this); //Generating the Units
}

bool Game::ReadFile()
{
	input.open("Input.txt");
	if (!input.is_open()) return false; // if No file retur false // else Read file And Intialize the Generator prametars
	int val;
	input >> val; Generator.SetNumodUnits(val);
	input >> val; Generator.SetES(val); input >> val; Generator.SetET(val); input >> val; Generator.SetEG(val); input >> val; Generator.SetHU(val);
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






void Game::StartGame()
{
	if (mode == NormalMode) // Checking if Normal Mode
	{
		cout << "Current Timestep " << timeStep << endl;
		cout << endl;
	}


	
	if (mode == NormalMode)
	{
		// Printing the Alive Earth Units
		cout << "Earth Army Alive Units" << endl;
		eArmy.printSoldiers(); 
		eArmy.printTanks();
		eArmy.printEGunerry();
		eArmy.printHealthList();
		eArmy.printUML();
		cout << endl << endl << endl;

		// Printing the Alive Alien Units
		cout << "Alien Army Alive Units" << endl;
		aArmy.printSoldiera();
		aArmy.printMonsters();
		aArmy.printDrones();
		cout << endl << endl << endl;
	}

	if (mode == NormalMode) cout << "Current Attacking" << endl;;
	eArmy.Attack(); //Earth Army Attacking
	if (mode == NormalMode) cout << endl << endl << endl;
    aArmy.Attack(); //Alien Army Attacking
	
	if (mode == NormalMode) cout << endl << endl << endl;

	if (mode == NormalMode)
	{
		cout << "Killed Units" << endl;
		printKilledUnits(); // Printing the killed Units
		cout << endl << endl << endl;
	}
	
}


void Game::OutFile()
{
	Outfile.open("output.txt");
	Outfile << "TD\tID\tTJ\tDF\tDd\tDP" << endl;
	KilledUnitsFile(Outfile); // printing the Killed Units Information
	

	int Ecount = eArmy.GetSoldierCount() + eArmy.GetGunneryCount() + eArmy.GetTankCount(); // Geting the Alive Earth Units Count
	int Acount = aArmy.GetMonsterCount() + aArmy.GetSoldierCount() + aArmy.GetDroneCount(); // Geting the Alive Alien Units Count
	
	//Checking who Is the Winner
	Outfile << "Battle result : ";
	
	if (Ecount && !Acount) Outfile << "win";
	else if (!Ecount && Acount) Outfile << "lose";
	else Outfile << "Drawn";
	
	Outfile << endl << endl;

	

	// Geting the Total count of evrey Unit and the Total Df,Db and Dd for earth and alien Units
	int ESdeath = 0, ETdeath = 0, EGdeath = 0;
	int AMdeath = 0, ASdeath = 0, ADdeath = 0;
	int HUCount = 0;
	int EDf = 0; int EDb = 0; int EDd = 0;
	int ADf = 0; int ADb = 0; int ADd = 0;


	while (!KilledUnits.isEmpty())
	{
		unit* Unit;
		KilledUnits.dequeue(Unit);
		switch (Unit->UnitType())
		{
		case monster: AMdeath++; ADf += Unit->GetTa() - Unit->GetTj(); ADd += Unit->GetTd() - Unit->GetTa(); ADb += Unit->GetTd() - Unit->GetTj();  break;
		case alien_solider: ASdeath++;  ADf += Unit->GetTa() - Unit->GetTj(); ADd += Unit->GetTd() - Unit->GetTa(); ADb += Unit->GetTd() - Unit->GetTj(); break;
		case soldier: ESdeath++;  EDf += Unit->GetTa() - Unit->GetTj(); EDd += Unit->GetTd() - Unit->GetTa(); EDb += Unit->GetTd() - Unit->GetTj(); break;
		case drone: ADdeath++;  ADf += Unit->GetTa() - Unit->GetTj(); ADd += Unit->GetTd() - Unit->GetTa(); ADb += Unit->GetTd() - Unit->GetTj(); break;
		case tank: ETdeath++;  EDf += Unit->GetTa() - Unit->GetTj(); EDd += Unit->GetTd() - Unit->GetTa(); EDb += Unit->GetTd() - Unit->GetTj(); break;
		case gunnery: EGdeath++;  EDf += Unit->GetTa() - Unit->GetTj(); EDd += Unit->GetTd() - Unit->GetTa(); EDb += Unit->GetTd() - Unit->GetTj(); break;
		case Healing: HUCount++; break;
		default: break;
		}
		delete Unit;
	}


	//Printing the earth Units Informatiom
	Outfile << "//Earth Army : " << endl;
	Outfile << "ES Alive units : " << eArmy.GetSoldierCount() << endl;
	Outfile << "ET Alive units : " << eArmy.GetTankCount() << endl;
	Outfile << "EG Alive units : " << eArmy.GetGunneryCount() << endl;
	
	//Dead to all %
	if (eArmy.GetSoldierCount() + ESdeath > 0) Outfile << "percentage of destruction ES to total ES : " << ( ESdeath * 100 / (eArmy.GetSoldierCount() + ESdeath)) << "%" << endl; 
	else Outfile << "There is No earth soldiers" << endl;
	
	if (eArmy.GetTankCount() + ETdeath > 0) Outfile << "percentage of destruction ET to total ET : " << ( ETdeath * 100 / (eArmy.GetTankCount() + ETdeath))  << "%" << endl;
	else Outfile << "There is No Tanks" << endl;
	
	if (eArmy.GetGunneryCount() + ETdeath > 0)  Outfile << "percentage of destruction EG to total EG : " << ( EGdeath * 100 / (eArmy.GetGunneryCount() + EGdeath))  << "%" << endl;
	else Outfile << "There is No Gunnery" << endl;

	//Dp,Df and Db information
	if (ESdeath + ETdeath + EGdeath > 0) {
		Outfile << "Healed Units : " << eArmy.Healed() * 100 / (ESdeath + ETdeath + EGdeath) << "%" << endl;
		Outfile << "Avg of DF : " << EDf / (ESdeath + ETdeath + EGdeath) << endl;
		Outfile << "Avg of Dd : " << EDd / (ESdeath + ETdeath + EGdeath) << endl;
		Outfile << "Avg of Db : " << EDb / (ESdeath + ETdeath + EGdeath) << endl;
	}

	if (EDb > 0) {
		Outfile << "Df / Db : " << EDf * 100 / EDb  << "%" << endl;
		Outfile << "Dd / Db : " << EDd * 100 / EDb  << "%" << endl;
	}

	Outfile << endl << endl;



	//Printing the Alien Units Informatiom
	Outfile << "//Alien Army : " << endl;
	Outfile << "AS Alive units : " << aArmy.GetSoldierCount() << endl;
	Outfile << "AM Alive units : " << aArmy.GetMonsterCount() << endl;
	Outfile << "AD Alive units : " << aArmy.GetDroneCount() << endl;

	//Dead to all %
	if (aArmy.GetSoldierCount() + ASdeath > 0)  Outfile << "percentage of destruction AS to total AS : " << ( ASdeath * 100 / (aArmy.GetSoldierCount() + ASdeath)) << "%" << endl;
	else Outfile << "There is No alien soldiers" << endl;

	if (aArmy.GetMonsterCount() + AMdeath > 0)  Outfile << "percentage of destruction AM to total AM : " << ( AMdeath * 100 / (aArmy.GetMonsterCount() + AMdeath))  << "%" << endl;
	else Outfile << "There is No Monsters" << endl;

	if (aArmy.GetDroneCount() + ADdeath > 0)  Outfile << "percentage of destruction AM to total AM : " << ( ADdeath * 100 / (aArmy.GetDroneCount() + ADdeath)) << "%" << endl;
	else Outfile << "There is No Drones" << endl;

	//Dp,Df and Db information
	if (ASdeath + ADdeath + AMdeath > 0) {
		Outfile << "Avg of DF : " << ADf / (ASdeath + ADdeath + AMdeath) << endl;
		Outfile << "Avg of Dd : " << ADd / (ASdeath + ADdeath + AMdeath) << endl;
		Outfile << "Avg of Db : " << ADb / (ASdeath + ADdeath + AMdeath) << endl;
	}

	if (ADb > 0) {
		Outfile << "Df / Db : " << ADf * 100 / ADb  << "%" << endl;
		Outfile << "Dd / Db : " << ADd  * 100 / ADb  << "%" << endl;
	}

	Outfile.close(); // Colse the file
}

void Game::InforemDead(unit* unit)
{
	unit->SetTd(timeStep);	// seting the Destruction time
	KilledUnits.enqueue(unit); // Moving the Unit to the Killed List
}

bool Game::WarEnded()
{
	int Ecount = eArmy.GetSoldierCount() + eArmy.GetGunneryCount() + eArmy.GetTankCount();
	int Acount = aArmy.GetMonsterCount() + aArmy.GetSoldierCount() + aArmy.GetDroneCount();

	if (timeStep <= 40) return false; // check the current time step as metioned

	//check if some team lost
	if (Ecount && !Acount) return true;
	if (Acount && !Ecount) return true;
	if (!Acount && !Ecount) return true;

	return false;
}

void Game::NextTimeStep()
{
	timeStep++; //Move to the Next time step
}

int Game::GetTime()
{
	return timeStep; //return the current time step
}

alienArmy& Game::GetAlienArmy()
{
	return aArmy;
}

earthArmy& Game::GetEarthArmy()
{
	return eArmy;
}

Mode Game::GetMode()
{
	return mode;
}

void Game::printKilledUnits()
{
	if (KilledUnits.size() != 0) // print the killed Units Ids
	{
		cout << KilledUnits.size() << " units ";
		KilledUnits.print(); cout << endl;
	}
}

void Game::KilledUnitsFile(ostream& outfile)
{
	for (int i = 0;i < KilledUnits.size(); i++) // print the Td,Id,Dp,Df and Dd inn the Outfile
	{
		unit* Unit;
		KilledUnits.dequeue(Unit);
		if (Unit->UnitType() != Healing)
	    	outfile << Unit->GetTd() << "\t" << Unit->GetId() << "\t" << Unit->GetTj() << "\t" << Unit->GetTa() - Unit->GetTj() << "\t" << Unit->GetTd() - Unit->GetTa() << "\t" << Unit->GetTd() - Unit->GetTj() << endl;
		else 
			outfile << Unit->GetTd() << "\t" << Unit->GetId() << "\t" << Unit->GetTj() << "\t" << "HL" << "\t" << "HL" << "\t" << Unit->GetTd() - Unit->GetTj() << endl;
		KilledUnits.enqueue(Unit);
	}
}

Game::~Game()
{
	unit* temp;

	while (!KilledUnits.isEmpty()) // deleting All the Units in the Killed List
	{
		KilledUnits.dequeue(temp);
		delete temp;
	}
}
