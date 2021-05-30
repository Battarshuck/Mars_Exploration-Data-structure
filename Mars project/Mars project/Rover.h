#pragma once
#include "Mission.h"
#include "Mission_Emergency.h"
#include "Mission_Polar.h"
class Rover
{
private:
	int Rover_ID;
	int Num_Rovers;
	const int Avg_Speed;
	const int Num_TillCheckup;
	const int Checkup_Dur;
	Mission* Curr_Mission;
	
public:
	Rover(int, int, int, int);

	virtual void set_ID(int);

	virtual int get_Num_Rovers() const;
	virtual int get_Checkup_Dur() const;
	virtual int get_Avg_Speed() const;

	virtual void set_Mission(Mission*);  // set/removes the mission
	virtual Mission* get_Mission() const;
	
};

