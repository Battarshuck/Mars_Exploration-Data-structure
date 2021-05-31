#include "MarsStation.h"

int Rover_Polar::ID = 0;
int Rover_Emergency::ID = 0;

MarsStation::MarsStation()
{
	UserInterface = new UI();
}

void MarsStation::Load()
{
	UserInterface->Read_File(Event_list); // fills the queue with events
}



UI* MarsStation::get_UI() const
{
	return UserInterface;
}