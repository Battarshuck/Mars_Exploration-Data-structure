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
	int ex_days;	     //num_days of excution days + ciel((2*distance/velocity)/25) (distance rover thing)
	
public:
	Mission(int, int, int, int);
	virtual int get_id() const;
	virtual int get_distance() const;
	virtual int get_numDay() const;
	virtual int get_priority() const;
	virtual int get_CompletionDay() const;
	virtual int get_FormulationDay() const;
	virtual int get_WaitingDays() const;
	virtual int get_ExDays() const;

	void set_FormulationDay(int current_day);
	void set_CompletionDay(); // we will set it in the set_WaitingDays function
	void set_WaitingDays(int current_day);
	void set_ExDays(float velocity);
};

