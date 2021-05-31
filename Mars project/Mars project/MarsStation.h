#pragma once
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
	Queue<Event*> Event_list; // list of missions to be formulated

	PriQ<Mission*> missions_emergency;  // sorted according to priority equation
	Queue<Mission*> missions_polar;     // first come first serve
	Queue<Mission*> missions_completed; // placed according to completion day

	PriQ<Rover> rovers_emergency;     // sorted according to speed
	PriQ<Rover> rovers_polar;         // sorted according to speed
	PriQ<Rover> rovers_inexecution;   // sorted according to completion day
	Queue<Rover> rovers_checkup;      // checkup queue for rovers

	UI* UserInterface;				  // pointer to user interface

	int current_day;
public:
	MarsStation();

	void Load();

	UI* get_UI() const;

	void simulate();
	void check_events();


};

