#pragma once


#include <fstream>
#include "LinkedQueue.h"
#include "unit.h"
#include "RandomGenerator.h"

class Game
{
private:
	LinkedQueue<unit*> KilledUnits;
	RandomGenerator Generator;
	int timeStep;
	ofstream Outfile;
	earthArmy eArmy;
	alienArmy aArmy;
	ifstream input;
public:
	Game();
	void Generate();
	
	bool ReadFile();

	void TestCode();
	void SilentMode();

	void Print();
	void OutFile();
	
	void NextTimeStep();
	int GetTime();

	
	void printKilledUnits();
	void fileKilledUnits(ofstream& Outfile);

	~Game();
};
 
