#pragma once


#include <fstream>
#include "LinkedQueue.h"
#include "RandomGenerator.h"

enum Mode { SilentMode,NormalMode };
enum { MaxTime = 250}; // Max time steps to result in a Draw if the Game Lasted too long
class unit;

#ifndef _GAME_
#define _GAME_




class Game
{
private:
	int timeStep; //the Timestep Counter

	LinkedQueue<unit*> KilledUnits; //Killed Units List
	RandomGenerator Generator; //the Units Generator

	// i/o Files
	ifstream input;
	ofstream Outfile;

	//Earth and aAlien Armies
	earthArmy eArmy;
	alienArmy aArmy;

	//the Game Mode
	Mode mode;
	
public:
	Game(Mode mode = NormalMode);  //Game constructor 
	
	bool ReadFile(); //Reading file function
	
	void Generate(); //Generating Units
	


	
	
	void StartGame(); //the main simulating function
	
	void OutFile(); //Generating the Outputvfile


	void InforemDead(unit* unit); //to Add the Killed Units to the Killed List

	bool WarEnded(); // Check if some one Won to End the Simulation

	void NextTimeStep(); //Moving to the Next time step
	int GetTime(); //Checking time
	 
	alienArmy& GetAlienArmy(); //to be able to Attack them by other Units
	earthArmy& GetEarthArmy(); //to be able to Attack them by other Units
	

	Mode GetMode();

	void printKilledUnits(); //Printing the Killed Units
	void KilledUnitsFile(ostream& outfile); // printing the Killed Units details in the Output file

	~Game();
};
 
#endif // !_GAME_