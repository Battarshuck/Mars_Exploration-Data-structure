#include <iostream>
#include "MarsStation.h"
#include "UI.h"
using namespace std;



int main() {

	
	MarsStation Station;
	

	
	//cin >> choice; // 3mltlha comment 3lshan mksl aktb kol mra 2 w adoos enter

	Station.Load();			// loads input file
	Station.simulate();		// runs the simulation
	//Station.save();		// saves the output file

	//switch (choice)
	//{
	//case 1:
	//	while (true)
	//	{
	//		// hn3ml step 2 kolaha
	//		break;
	//	}
	//	// hn3ml step 3

	//	break;
	//case 2:
	//	Station.simulate();
	//	//bool x = true;
	//	//while (x)
	//	//{
	//		//station.simulate(x);
	//	//}
	//	// hn3ml step 3

	//	break;
	//case 3:

	//	break;

	//default:

	//	break;
	//}

	

	return 0;
}