#include <stdlib.h> // to use rand() function
#include "Rover_Polar.h"

Rover_Polar::Rover_Polar(int S, int CheckMissions, int CheckDur) :
	Rover(S, CheckMissions, CheckDur)
{
	set_ID(++ID); // increases static id from 0 to 1 for example, then places it
	set_Speed(get_Avg_Speed());
}

void Rover_Polar::set_Speed(int S)
{
	int percentage = rand() % 31;		     // generates a random number between 0 and 30
	percentage += 80;					     // shifts the numbers to [80, 110]
	Speed = (float(percentage) / 100.0) * S; // sets the actual speed of the rover to
										     // a number from 80% to 110% of the speed entered
}

float Rover_Polar::get_Speed() const
{
	return Speed;
}

Rover_Polar Rover_Polar::operator= (Rover_Polar R2)
{
	this->set_ID(R2.get_ID());
	this->set_Num_Mission(R2.get_Num_Missions());
	this->set_Mission(R2.get_Mission());
	int Avg_Speed = R2.get_Avg_Speed();
	int Num_TillCheckup = R2.get_Num_TillCheckup();
	int Checkup_Dur = R2.get_Checkup_Dur();
	this->set_Speed(R2.get_Speed());
	return Rover_Polar(Avg_Speed, Num_TillCheckup, Checkup_Dur);
}