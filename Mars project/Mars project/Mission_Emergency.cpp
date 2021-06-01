#include "Mission_Emergency.h"

Mission_Emergency::Mission_Emergency(int in_id, int distance, int num_days, int significance, int formulation)
	: Mission(in_id, distance, num_days, formulation)
{
	this->sig = significance;
	calculate_priority();
}

int Mission_Emergency::get_sig() const
{
	return sig;
}

int Mission_Emergency::get_priority() const
{
	return priority;
}

void Mission_Emergency::calculate_priority()
{
	priority = sig;
}