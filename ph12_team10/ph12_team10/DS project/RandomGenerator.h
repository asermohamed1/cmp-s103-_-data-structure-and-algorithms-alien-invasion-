#pragma once

#include <fstream>
#include <ctime>
#include <iostream>
#include "alienArmy.h"
#include "earthArmy.h"
#include "earthSoldier.h"
#include "Tank.h"
#include "Gunnery.h"
#include "alienSoldier.h"
#include "Monster.h"
#include "Drone.h"
using namespace std;


class RandomGenerator
{
private:
	int NumofUnits;
	int ES, ET, EG;
	int AS, AM, AD;
	int Epower_range[2], Ehealth_range[2], Ecapacity_range[2];
	int Apower_range[2], Ahealth_range[2], Acapacity_range[2];
	int prop;
	int Eid, Aid;
public:
	RandomGenerator();
	void Generate(earthArmy& eArmy, alienArmy& aArmy,int timestep);
    
	
	
	
	void SetNumodUnits(int val);
	void SetES(int val);
	void SetET(int val);
	void SetEG(int val);
	void SetAS(int val);
	void SetAM(int val);
	void SetAD(int val);
	void Setprop(int val);
	void SetEhealthRange(int* vals);
	void SetAhealthRange(int* vals);
	void SetEpowerRange(int* vals);
	void SetApowerRange(int* vals);
	void SetEcapacityRange(int* vals);
	void SetAcapacityRange(int* vals);

	int Random_num(int range);
	int Random_num(int range[2]);
};

