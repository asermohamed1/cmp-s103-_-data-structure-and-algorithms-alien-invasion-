#include "RandomGenerator.h"

RandomGenerator::RandomGenerator()
{
	Eid = 1; Aid = 2000;
	srand(time(0));
}


void RandomGenerator::Generate(earthArmy& eArmy, alienArmy& aArmy,int timestep)
{
	int Erndm = Random_num(100);
	if (Erndm <= prop)
	{
		for (int i = 0;i < NumofUnits;i++)
		{
			int rndm = Random_num(100);
			if (rndm <= ES) { eArmy.AddSoldier(new earthSoldier(Eid++, timestep, Random_num(Ehealth_range), Random_num(Epower_range), Random_num(Ecapacity_range))); }
			else if (rndm <= ET + ES) { eArmy.AddTank(new Tank(Eid++, timestep, Random_num(Ehealth_range), Random_num(Epower_range), Random_num(Ecapacity_range))); }
			else { eArmy.AddGunnery(new Gunnery(Eid++, timestep, Random_num(Ehealth_range), Random_num(Epower_range), Random_num(Ecapacity_range))); }
		}
	}
	int Arndm = Random_num(100);
	if (Arndm <= prop)
	{
		for (int i = 0;i < NumofUnits;i++)
		{
			int rndm = Random_num(100);
			if (rndm <= AS) { aArmy.AddSoldier(new alienSoldier(Aid++, timestep, Random_num(Ahealth_range), Random_num(Apower_range), Random_num(Acapacity_range))); }
			else if (rndm <= AM + AS) { aArmy.AddMonster(new Monster(Aid++, timestep, Random_num(Ahealth_range), Random_num(Apower_range), Random_num(Acapacity_range))); }
			else { aArmy.AddDrone(new Drone(Aid++, timestep, Random_num(Ahealth_range), Random_num(Apower_range), Random_num(Acapacity_range))); }
		}
	}

}

void RandomGenerator::SetNumodUnits(int val)
{
	NumofUnits = val;
}

void RandomGenerator::SetES(int val)
{
	ES = val;
}

void RandomGenerator::SetET(int val)
{
	ET = val;
}

void RandomGenerator::SetEG(int val)
{
	EG = val;
}

void RandomGenerator::SetAS(int val)
{
	AS = val;
}

void RandomGenerator::SetAM(int val)
{
	AM = val;
}

void RandomGenerator::SetAD(int val)
{
	AD = val;
}

void RandomGenerator::Setprop(int val)
{
	prop = val;
}

void RandomGenerator::SetEhealthRange(int* vals)
{
	Ehealth_range[0] = vals[0];
	Ehealth_range[1] = vals[1];
}

void RandomGenerator::SetAhealthRange(int* vals)
{
	Ahealth_range[0] = vals[0];
	Ahealth_range[1] = vals[1];
}

void RandomGenerator::SetEpowerRange(int* vals)
{
	Epower_range[0] = vals[0];
	Epower_range[1] = vals[1];
}

void RandomGenerator::SetApowerRange(int* vals)
{
	Apower_range[0] = vals[0];
	Apower_range[1] = vals[1];
}

void RandomGenerator::SetEcapacityRange(int* vals)
{
	Ecapacity_range[0] = vals[0];
	Ecapacity_range[1] = vals[1];
}

void RandomGenerator::SetAcapacityRange(int* vals)
{
	Acapacity_range[0] = vals[0];
	Acapacity_range[1] = vals[1];
}

int RandomGenerator::Random_num(int range) // generates a number between 1 and range 
{
	return rand() % range + 1;
}

int RandomGenerator::Random_num(int range[2]) // generates a number between range[0] and range[1]
{
	return rand() % abs(range[1] - range[0] + 1) + range[0];
}
