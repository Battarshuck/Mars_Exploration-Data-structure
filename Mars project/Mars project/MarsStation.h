#pragma once
#include "Mission.h"
#include "Event.h"
#include "Rover.h"
#include "../data sturctures/PriQ.h"
#include "../data sturctures/Queue.h"

class MarsStation
{
private:
	Queue<Event> Event_list;

	PriQ<Mission> missions_emergency;
	Queue<Mission> missions_polar;
	Queue<Mission> missions_completed;

	PriQ<Rover> rovers_emergency;
	PriQ<Rover> rovers_polar;
	PriQ<Rover> rovers_inexecution;
	Queue<Rover> rovers_checkup;

public:




};

