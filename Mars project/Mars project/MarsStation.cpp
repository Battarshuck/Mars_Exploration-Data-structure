#include "MarsStation.h"

int Rover_Polar::ID = 0;
int Rover_Emergency::ID = 0;

MarsStation::MarsStation()
{
	UserInterface = new UI();
	current_day = 0;
}

void MarsStation::Load()
{	
	UserInterface->Read_File(Event_list); // fills the queue with events
}


UI* MarsStation::get_UI() const
{
	return UserInterface;
}

void MarsStation::simulate()
{

	while (current_day != 20)
	{
		current_day++;
		//1-Events to be formulated
		check_events();

		//2-Check first for emergency mission then polar 
		//3-check if in-execution missions are done
		//if yes send them to the missions_completed
		//4-movement of rovers
		//5-printing in the UI class
	}

}

void MarsStation::check_events()
{
	Event* temp;
	while (true)
	{
		Event_list.peek(temp);
		if (temp->get_ExecuteDay() != current_day)
			return;

		Event_list.dequeue(temp);

		temp->Execute(missions_emergency, missions_polar);
	}
}
