#include <stdlib.h> // to use rand() function
#include "Rover_Emergency.h"

Rover_Emergency::Rover_Emergency(int N_Rovers, int S, int CheckMissions, int CheckDur) :
	Rover(N_Rovers, S, CheckMissions, CheckDur)
{
	set_ID(++ID); // increases static id from 0 to 1 for example, then places it
	set_Speed(get_Avg_Speed());
}

void Rover_Emergency::set_Speed(int S)
{
	int percentage = rand() % 41;		     // generates a random number between 0 and 40
	percentage += 85;					     // shifts the numbers to [85, 125]
	Speed = (float(percentage) / 100.0) * S; // sets the actual speed of the rover to
										     // a number from 85% to 125% of the speed entered
}

float Rover_Emergency::get_Speed() const
{
	return Speed;
}