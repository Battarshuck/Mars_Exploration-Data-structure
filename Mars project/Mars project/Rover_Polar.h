#pragma once
#include "Rover.h"
class Rover_Polar : public Rover
{
private:
	float Speed; // The actual speed of the rover, differs for each rover

public:
	static int ID;


	Rover_Polar(int, int, int, int);

	void set_Speed(int);	 // sets speed for each rover
	float get_Speed() const; // returns the actual speed

	
};

