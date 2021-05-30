#include "Rover.h"

Rover::Rover(int N_Rovers, int S, int CheckMissions, int CheckDur) :
	Avg_Speed(S), Num_TillCheckup(CheckMissions), Checkup_Dur(CheckDur)
{
	Num_Rovers = N_Rovers;
	Curr_Mission = nullptr;
}

void Rover::set_ID(int ID)
{
	Rover_ID = ID;
}

int Rover::get_Num_Rovers() const
{
	return Num_Rovers;
}

int Rover::get_Checkup_Dur() const
{
	return Checkup_Dur;
}

int Rover::get_Avg_Speed() const
{
	return Avg_Speed;
}

void Rover::set_Mission(Mission* mission = nullptr)  // if no parameter is given, it removes the mission / frees the rover 
{
	Curr_Mission = mission;
}

Mission* Rover::get_Mission() const
{
	return Curr_Mission;
}