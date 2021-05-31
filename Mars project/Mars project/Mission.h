#pragma once
#include<cmath>

class Mission
{
private:
	const int id;
	int distance;
	int num_days;

	int formulation_day; //input file
	int completion_day;  //formulation + waiting_days + ex_days
	int waiting_days;    //current_day - formulation
	int ex_days;	     //num_days of excution days + ciel((distance/velocity)/25) (distance rover thing)
	
public:
	Mission(int, int, int, int);
	virtual int get_id() const;
	virtual int get_distance() const;
	virtual int get_numDay() const;
	virtual int get_priority() const;

	void set_CompletionDay(); // we will set it in the set_WaitingDays function
	void set_WaitingDays(int current_day);
	void set_ExDays(float velocity);
};

