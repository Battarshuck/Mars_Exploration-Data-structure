#pragma once
#include <string>
#include "../data sturctures/PriQ.h"
#include "../data sturctures/Queue.h"
#include "Mission.h"

#include "Event.h"
#include "Rover.h"
#include "Rover_Polar.h"
#include "Rover_Emergency.h"
#include "UI.h"




class MarsStation
{
private:
	Queue<Event*> Event_list;			// list of missions to be formulated

	PriQ<Mission*> missions_emergency;  // sorted according to priority equation
	Queue<Mission*> missions_polar;     // first come first serve
	Queue<Mission*> missions_completed; // placed according to completion day

	PriQ<Rover*> rovers_emergency;      // available rovers sorted according to speed
	PriQ<Rover*> rovers_polar;          // available rovers sorted according to speed
	PriQ<Rover*> rovers_inexecution;    // sorted according to completion day
	Queue<Rover*> rovers_polar_checkup;       // checkup queue for Polar rovers
	Queue<Rover*> rovers_emergency_checkup;   // checkup queue for Emergency rovers

	UI* UserInterface;				    // pointer to user interface

	int current_day;
	int num_events;
	int Failure_Percentage;
	int Failed_Missions;
public:
	MarsStation();

	void Load();  // Loads the file to get input

	void simulate();			// runs the simulation
	void check_events();		// check if mission should be formulated today
	void check_inExecution();	//checks the inExecution rovers if finished or not
	void check_inCheckup();		//checks the rovers that are in checkup  

	void Assign_Emergency_Mission();	// Assigns E missions if possible
	void Assign_Polar_Mission();		// Assigns P missions if possible

	bool If_Failed();					// Checks if mission has failed

	/* string-generating functions */
	void OutputGenerator();
	string generateString_roverQ(Queue<Rover*>);
	string generateString_rover_inExc(PriQ<Rover*>);
	string generateString_rover_avail(PriQ<Rover*>);
	string generateString_missionQ(Queue<Mission*>);
	string generateString_missionP(PriQ<Mission*>);

	void SaveFileGenerator();			// saves output file

};

