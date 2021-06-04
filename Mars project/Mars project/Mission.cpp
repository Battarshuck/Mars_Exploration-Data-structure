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

int Mission::get_CompletionDay() const
{
	return completion_day;
}

int Mission::get_FormulationDay() const
{
	return formulation_day;
}

int Mission::get_WaitingDays() const
{
	return waiting_days;
}

int Mission::get_ExDays() const
{
	return ex_days;
}

int Mission::get_priority() const
{
	return -1;
}

void Mission::set_WaitingDays(int current_day)
{
	waiting_days = current_day - formulation_day;
}

void Mission::set_ExDays(float velocity)
{
	ex_days = num_days + ceil((2 * distance / velocity) / 25);
}

void Mission::set_CompletionDay()
{
	completion_day = formulation_day + waiting_days + ex_days;
}

void Mission::set_FormulationDay(int current_day)
{
	formulation_day = current_day;
}