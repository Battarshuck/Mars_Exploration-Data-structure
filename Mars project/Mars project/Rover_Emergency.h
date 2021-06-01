#pragma once
#include "Rover.h"
class Rover_Emergency : public Rover
{
private:
	float Speed; // The actual speed of the rover, differs for each rover

public:
	Rover_Emergency(int, int, int);

	void set_Speed(int);	 // sets speed for each rover
	float get_Speed() const; // returns the actual speed

	Rover_Emergency operator = (Rover_Emergency R2);
};

