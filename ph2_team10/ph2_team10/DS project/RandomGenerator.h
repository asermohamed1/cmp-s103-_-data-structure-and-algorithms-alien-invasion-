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


#ifndef _Random_Generator_
#define _Random_Generator_



class RandomGenerator
{
private:
	int NumofUnits;
	int HU;
	int ES, ET, EG;
	int AS, AM, AD;
	int Epower_range[2], Ehealth_range[2], Ecapacity_range[2];
	int Apower_range[2], Ahealth_range[2], Acapacity_range[2];
	int prop;
	int Eid, Aid;
public:
	RandomGenerator();
	void Generate(earthArmy& eArmy, alienArmy& aArmy, int timestep, Game* game); //Generating the Units
    
	
	
	// Seters
	void SetNumodUnits(int val);
	void SetES(int val);
	void SetET(int val);
	void SetEG(int val);
	void SetAS(int val);
	void SetAM(int val);
	void SetAD(int val);
	void SetHU(int val);
	void Setprop(int val);
	void SetEhealthRange(int* vals);
	void SetAhealthRange(int* vals);
	void SetEpowerRange(int* vals);
	void SetApowerRange(int* vals);
	void SetEcapacityRange(int* vals);
	void SetAcapacityRange(int* vals);


	int Random_num(int range); // generates a number between 1 and range 
	int Random_num(int range[2]); // generates a number between range[0] and range[1]
};

#endif // !_Random_Generator_