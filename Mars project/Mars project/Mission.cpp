#include "Mission.h"

Mission::Mission(int in_id, int distance, int num_days): id(in_id)
{
	this->distance = distance;
	this->num_days = num_days;
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

int Mission::get_sig() const
{
	return -1;
}
