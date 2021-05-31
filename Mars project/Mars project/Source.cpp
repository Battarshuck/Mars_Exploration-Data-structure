#include <iostream>
#include "MarsStation.h"
using namespace std;



int main() {

	
	int choice = -1;
	MarsStation Station;
	

	cout << "Welcome To Mars Ground Station !\n";
	cout << "Please choose mode of operation: 1-Interactive   2-Step-by-step   3-Silent\n";
	cin >> choice;

	Station.Load(); // loads input file

	switch (choice)
	{
	case 1:
		while (true)
		{
			// hn3ml step 2 kolaha
			break;
		}
		// hn3ml step 3

		break;
	case 2:
		Station.simulate();
		//bool x = true;
		//while (x)
		//{
			//station.simulate(x);
		//}
		// hn3ml step 3

		break;
	case 3:

		break;

	default:

		break;
	}

	

	return 0;
}