#include "Rover.h"

Rover::Rover() :
	Avg_Speed(-1), Num_TillCheckup(-1), Checkup_Dur(-1)
{
	Num_Missions = 0;
	Curr_Mission = nullptr;
}

Rover::Rover(int S, int CheckMissions, int CheckDur) :
	Avg_Speed(S), Num_TillCheckup(CheckMissions), Checkup_Dur(CheckDur)
{
	// initially, the rover has done no missions
	// and has no assinged mission
	Num_Missions = 0;  
	Curr_Mission = nullptr;
}

void Rover::set_ID(int ID)
{
	Rover_ID = ID;
}

int Rover::get_ID() const
{
	return Rover_ID;
}

void Rover::set_Num_Mission(int N)
{
	Num_Missions = N;
}

int Rover::get_Num_Missions() const
{
	return Num_Missions;
}

int Rover::get_Avg_Speed() const
{
	return Avg_Speed;
}

int Rover::get_Num_TillCheckup() const
{
	return Num_TillCheckup;
}

int Rover::get_Checkup_Dur() const
{
	return Checkup_Dur;
}

void Rover::set_Mission(Mission* mission = nullptr)  // if no parameter is given, it removes the mission / frees the rover 
{
	Curr_Mission = mission;
}

Mission* Rover::get_Mission() const
{
	return Curr_Mission;
}

Rover Rover::operator= (Rover R2)
{
	this->Rover_ID = R2.Rover_ID;
	this->Num_Missions = R2.Num_Missions;
	int Avg_Speed = R2.Avg_Speed;
	int Num_TillCheckup = R2.Num_TillCheckup;
	int Checkup_Dur = R2.Checkup_Dur;
	this->Curr_Mission = R2.Curr_Mission;
	return Rover(Avg_Speed, Num_TillCheckup, Checkup_Dur);
}