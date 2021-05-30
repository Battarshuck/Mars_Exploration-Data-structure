#include <stdlib.h> // to use rand() function
#include "Rover_Polar.h"

Rover_Polar::Rover_Polar(int N_Rovers, int S, int CheckMissions, int CheckDur) :
	Rover(N_Rovers, S, CheckMissions, CheckDur)
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