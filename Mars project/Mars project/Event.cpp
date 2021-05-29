#include "Event.h"
#include "Mission.h"
#include "Mission_Emergency.h"
#include "Mission_Polar.h"

Event::Event(char type, int event_day, int id, int distance, int num_days, int sig)
{
	this->type = type;
	this->event_day = event_day;
	this->id = id;
	this->distance = distance;
	this->num_days = num_days;
	this->sig = sig;
}

int Event::get_ExecuteDay()
{
	return event_day;
}

void Event::Execute()
{

	if (type == 'E')
	{
		Mission* mission = new Mission_Emergency(id, distance, num_days, sig);
		//After init. the mission
		//w need to add it in the pQ in the main file
	}
	else
	{
		Mission* mission = new Mission_Polar(id, distance, num_days);
		//After init. the mission
		//w need to add it in the Q in the main file
	}
}
