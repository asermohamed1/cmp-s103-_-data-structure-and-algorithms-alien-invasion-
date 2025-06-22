#include <iostream>
#include <windows.h>
using namespace std;

#include "doubleEndedQueue.h"
#include "LinkedQueue.h"
#include "Game.h"

void setColor(int color) { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); }



int main()
{
	
	Game game; bool Mode;
	char Continue; int mode = 0;
	while (mode != 1 && mode !=2)
	{
		cout << "1-Silent Mode" << endl << "2-Normal Mode" << endl << "Entre : ";
		cin >> mode;
		if (mode == 1) Mode = true;
		else Mode = false;
	}
	if (Mode)
	{
		cout << "Silent Mode" << endl;
		cout << "Simulation Starts..." << endl;
		while (game.GetTime() <= 50)
		{
			game.Generate();
			game.SilentMode();
			game.NextTimeStep();
		}
		game.OutFile();
		setColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "Simulation ends, Output file is created" << endl;
		setColor(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
	}
	else
	{
		cin.get();
		while (game.GetTime() <= 50)
		{
			game.Generate();
			game.TestCode();
			game.Print();
			game.NextTimeStep();
			setColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << "press any key to move for the next time step (space to stop) ";
			setColor(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
			Continue = cin.get(); 
			if (Continue == ' ') break;
			cout << endl;
		}
		game.OutFile();
	}

}
