#include "Mission.h"

Mission::Mission(int in_id, int distance, int num_days, int formulation_day): id(in_id)
{
	this->distance = distance;
	this->num_days = num_days;
	this->formulation_day = formulation_day;

	completion_day = -1;  
	waiting_days = -1;    
	ex_days = -1;
}

int Mission::get_id() const
{
	return id;
}

int Mission::get_distance() const
{
	return distance;
}

int Mission::get_numDay() const
{
	return num_days;
}

int Mission::get_priority() const
{
	return -1;
}
