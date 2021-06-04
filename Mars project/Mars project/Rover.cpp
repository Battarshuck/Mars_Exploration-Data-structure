#include "Rover.h"

Rover::Rover() :
	Avg_Speed(-1), Checkup_Every(-1), Checkup_Dur(-1)
{
	Num_Missions = 0;
	Curr_Mission = nullptr;
	Checkup_endDay = -1;
	Num_Till_Checkup = Checkup_Every;
}

Rover::Rover(int S, int CheckMissions, int CheckDur) :
	Avg_Speed(S), Checkup_Every(CheckMissions), Checkup_Dur(CheckDur)
{
	// initially, the rover has done no missions
	// and has no assinged mission
	Num_Missions = 0;  
	Curr_Mission = nullptr;
	Checkup_endDay = -1;
	Num_Till_Checkup = Checkup_Every;
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

int Rover::get_Checkup_Every() const
{
	return Checkup_Every;
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

void Rover::set_Checkup_endDay(int endDay)
{
	Checkup_endDay = endDay;
}

int Rover::get_Checkup_endDay() const
{
	return Checkup_endDay;
}

void Rover::set_Num_Till_Checkup(int x)
{
	Num_Till_Checkup = x;
}

int Rover::get_Num_Till_Checkup() const
{
	return Num_Till_Checkup;
}

bool Rover::ReachCheckup() const
{
	return Num_Till_Checkup == 0;
}

Rover Rover::operator= (Rover R2)
{
	this->Rover_ID = R2.Rover_ID;
	this->Num_Missions = R2.Num_Missions;
	int Avg_Speed = R2.Avg_Speed;
	int Checkup_Every = R2.Checkup_Every;
	int Checkup_Dur = R2.Checkup_Dur;
	this->Curr_Mission = R2.Curr_Mission;
	return Rover(Avg_Speed, Checkup_Every, Checkup_Dur);
}