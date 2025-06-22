#include <iostream>
#include <windows.h>
using namespace std;

#include "doubleEndedQueue.h"
#include "LinkedQueue.h"
#include "Game.h"

void setColor(int color) { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); }



int main()
{
	Mode mode = NormalMode; // The Game Mode 
	int GameMode;
	do
	{
		cout << "1-Normal Mode" << endl;
		cout << "2-Silent Mode" << endl;
		cout << "Choose mode : ";
		cin >> GameMode; cin.get(); // Getting the Mode from the user 
		if (GameMode == 1) mode = NormalMode;
		if (GameMode == 2) mode = SilentMode;

	} while (GameMode != 1 && GameMode != 2); 
	cout << endl;
	Game game(mode); // Instantiating the game 
	

	if (mode == SilentMode) { cout << "silent Mode" << endl; cout << "Simulation Starts..." << endl; }
	while (!game.WarEnded())
	{
		game.Generate(); // Generating the Units
		game.StartGame(); // the main Simulating Function
		if (game.GetTime() == MaxTime) break; // checking the Max time
		game.NextTimeStep(); // Moving to the next time step
		if (mode == NormalMode) { setColor(10); cout << "press any where to continue"; setColor(15); cin.get(); }
	}
	game.OutFile(); //Generating the Output file
	if (mode == SilentMode) { setColor(1); cout << "Simulation Ends, Output file is created" << endl; setColor(15); }

	return 0;

}
