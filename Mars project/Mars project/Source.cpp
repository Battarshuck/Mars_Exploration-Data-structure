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

	

	return 0;
}