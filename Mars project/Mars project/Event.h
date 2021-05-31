#pragma once
#include "Mission.h"
#include "../data sturctures/PriQ.h"
#include "../data sturctures/Queue.h"
#include "Mission.h"
#include "Mission_Emergency.h"
#include "Mission_Polar.h"
class Event
{
private:
	char type;		// type of mission to be formulated
	int event_day;	// day of mission formulation
	int id;			// id of mission
	int distance;	// distance to reach missions (Km)
	int num_days;	// number of days needed to execute mission on site
	int sig;		// significance

public:
	Event();
	Event(char, int, int, int, int, int);
	
	int get_ExecuteDay();
	void Execute(PriQ<Mission*>&, Queue<Mission*>&);
	char get_type();

	void operator = (Event);
};

