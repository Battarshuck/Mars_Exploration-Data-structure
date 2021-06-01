#pragma once
#include "Mission.h"
#include "Mission_Emergency.h"
#include "Mission_Polar.h"
class Rover
{
private:
	int Rover_ID;				// ID for each rover
	int Num_Missions;			// number of missions done by rover
	const int Avg_Speed;		// average speed for each rover type
	const int Num_TillCheckup;	// number of missions before needing a checkup
	const int Checkup_Dur;		// checkup duration
	Mission* Curr_Mission;		// the missions currently in execution
	
public:
	static int ID;

	Rover();
	Rover(int, int, int);

	virtual void set_ID(int);
	virtual int get_ID() const;

	virtual void set_Num_Mission(int);
	virtual int get_Num_Missions() const;

	virtual int get_Avg_Speed() const;
	virtual int get_Num_TillCheckup() const;
	virtual int get_Checkup_Dur() const;

	virtual void set_Mission(Mission*);  // set/removes the mission
	virtual Mission* get_Mission() const;
	

	Rover operator = (Rover R2);
};

