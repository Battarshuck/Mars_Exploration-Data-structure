#include "Event.h"
Event::Event()
{
	type = 'N';
	event_day = -1;
	id = -1;
	distance = -1;
	num_days = -1;
	sig = -1;
}

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

void Event::Execute(PriQ<Mission*>& emergency, Queue<Mission*>& polar)
{
	Mission* mission;

	if (type == 'E')
	{
		mission = new Mission_Emergency(id, distance, num_days, sig, event_day);
		emergency.insert(mission, mission->get_priority());
	}
	else
	{
		mission = new Mission_Polar(id, distance, num_days, event_day);
		polar.enqueue(mission);
	}
}

char Event::get_type()
{
	return type;
}

void Event::operator = (Event n_event)
{
	type = n_event.type;
	event_day = n_event.event_day;
	id = n_event.id;
	distance = n_event.distance;
	num_days = n_event.num_days;
	sig = n_event.sig;
}


